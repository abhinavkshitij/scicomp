#include <iostream>
#include <stdexcept>
#include <cmath>
#include "MemberForwarding.h"

// Controller
void GPIBController::insert(const char* device_name, unsigned int address)
{
	std::cout << device_name << " now at address " << address << std::endl;
}
void GPIBController::send(unsigned int address, const char* cmd)
{
	std::cout << "GPIB instrument # " << address << " sends " << cmd
	<< std::endl;
}
void GPIBController::send(unsigned int address, float f)
{
	std::cout << "GPIB instrument# " << address << " sends value " << f 
	<< std::endl;
}
float GPIBController::receive(unsigned int address)
{
	std::cout << "Enter volts (default=1) for GPIB instrument#" << address << ": ";
	float f=1.f;
	// std::cin >> f;
	return f;
}

// Client function: transferOnGPIB
void transferOnGPIB(GPIBInstrument& from, GPIBInstrument& to)
{
	to.send(from.receive());
}


// GPIBInstrumentData
GPIBInstrumentData::GPIBInstrumentData(GPIBController& c, int address, const char* name)
	: _controller(c), _gpib_address(address)
{
	_controller.insert(name, _gpib_address);
}

void GPIBInstrumentData::send(const char* cmd)
{
	_controller.send(_gpib_address, cmd);
}
void GPIBInstrumentData::send(float volts) 
{
	_controller.send(_gpib_address, volts);
}
float GPIBInstrumentData::receive() 
{
	 return _controller.receive(_gpib_address);
}


// Interface destructor: Voltage Supply
VoltageSupply::~VoltageSupply(){};


// Voltage supply 1: ACME 130
Acme130_Fwd::Acme130_Fwd(GPIBController& controller, int gpib_address)
	: _gpib_rep(controller, gpib_address, "Acme130_Fwd"){}

void Acme130_Fwd::set(float volts)
{
	if (volts > maximum() || volts < minimum()) 
		throw std::invalid_argument("Acme130_Fwd voltage out of range");
	send(volts); // send(): declared in GPIBInterface; defined in Acme130 class 
}

float Acme130_Fwd::minimum() const {return 0.0;}
float Acme130_Fwd::maximum() const {return 40.0;}


// GPIBInstrument interface
void Acme130_Fwd::send(const char* cmd)
{
	_gpib_rep.send(cmd);
}
void Acme130_Fwd::send(float volts) 
{
	_gpib_rep.send(volts);
}
float Acme130_Fwd::receive() 
{
	return _gpib_rep.receive();
}

// Voltage supply 2: VoltOn59_Fwd
 VoltOn59_Fwd::VoltOn59_Fwd(GPIBController& controller, int gpib_address)
		: _gpib_rep(controller, gpib_address, "VoltOn59_Fwd"){}

void VoltOn59_Fwd::set(float volts)
{
	if (volts > maximum() || volts < minimum()) 
		throw std::invalid_argument(" VoltOn59_Fwd voltage out of range");
	_gpib_rep.send(volts);
}

float VoltOn59_Fwd::minimum() const {return 0.0;}
float VoltOn59_Fwd::maximum() const {return 40.0;}

// GPIBInstrument interface
void VoltOn59_Fwd::send(const char* cmd)
{
	_gpib_rep.send(cmd);
}
void VoltOn59_Fwd::send(float volts) 
{
	_gpib_rep.send(volts);
}
float VoltOn59_Fwd::receive() 
{
	 return _gpib_rep.receive();
}

// INTERFACE destructor: Voltmeter
Voltmeter::~Voltmeter(){};

VoltyMetrics_Fwd::VoltyMetrics_Fwd(GPIBController& controller, int what_address)
	: _gpib_rep(controller, what_address, "VoltyMetrics_Fwd"){}

float VoltyMetrics_Fwd::read()
{
	return _gpib_rep.receive();
}

// GPIBInstrument interface
void  VoltyMetrics_Fwd::send(const char* cmd)
{
	_gpib_rep.send(cmd);
}
void  VoltyMetrics_Fwd::send(float volts) 
{
	_gpib_rep.send(volts);
}
float  VoltyMetrics_Fwd::receive() 
{
	return _gpib_rep.receive();
}

// Client function
float checkCalibration(VoltageSupply& supply, Voltmeter& meter, float test_voltage)
{
	supply.set(test_voltage);
	return abs(test_voltage - meter.read()) / test_voltage;
}

// DRIVER CODE
int main(int argc, char const *argv[])
{
	GPIBController gpib;

	// Check calibration 
	VoltyMetrics_Fwd meter(gpib, 14);
	Acme130_Fwd supply1(gpib, 12);
	VoltOn59_Fwd supply2(gpib, 13);

	std::cout << "Acme130_Fwd relative error at 1V is: " 
		<< checkCalibration(supply1, meter, 6.0) << std::endl;
	std::cout << "Acme130_Fwd relative error at 1V is: " 
		<< checkCalibration(supply2, meter, 8.0) << std::endl;

	transferOnGPIB(supply2, supply1);

	return 0;
}

