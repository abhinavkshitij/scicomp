#include <iostream>
#include <stdexcept>
#include <cmath>
#include "MultipleInterfaces.h"

// Controller
void GPIBController_Stub::insert(const char* device_name, unsigned int address)
{
	std::cout << device_name << " now at address " << address << std::endl;
}
void GPIBController_Stub::send(unsigned int address, const char* cmd)
{
	std::cout << "GPIB instrument # " << address << " sends " << cmd
	<< std::endl;
}
void GPIBController_Stub::send(unsigned int address, float f)
{
	std::cout << "GPIB instrument# " << address << " sends value " << f 
	<< std::endl;
}
float GPIBController_Stub::receive(unsigned int address)
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

// Interface destructor: Voltage Supply
 VoltageSupply::~VoltageSupply(){};


// Voltage supply 1: ACME 130
Acme130_VS_GI::Acme130_VS_GI(GPIBController_Stub& controller, int gpib_address)
		: _controller(controller), _gpib_address(gpib_address)
{
	_controller.insert("Acme130_VS_GI", gpib_address);
}

void Acme130_VS_GI::set(float volts)
{
	if (volts > maximum() || volts < minimum()) 
		throw std::invalid_argument("Acme130_VS_GI voltage out of range");
	send(volts); // send(): declared in GPIBInterface; defined in Acme130 class 
}

float Acme130_VS_GI::minimum() const {return 0.0;}
float Acme130_VS_GI::maximum() const {return 40.0;}


// GPIBInstrument interface
void Acme130_VS_GI::send(const char* cmd)
{
	_controller.send(_gpib_address, cmd);
}
void Acme130_VS_GI::send(float volts) 
{
	_controller.send(_gpib_address, volts);
}
float Acme130_VS_GI::receive() 
{
	 return _controller.receive(_gpib_address);
}

// Voltage supply 2: VoltOn59_VS_GI
 VoltOn59_VS_GI::VoltOn59_VS_GI(GPIBController_Stub& controller, int gpib_address)
		: _controller(controller), _gpib_address(gpib_address)
{
	_controller.insert("VoltOn59_VS_GI", gpib_address);
}

void VoltOn59_VS_GI::set(float volts)
{
	if (volts > maximum() || volts < minimum()) 
		throw std::invalid_argument(" VoltOn59_VS_GI voltage out of range");
	_controller.send(_gpib_address, volts);
}

float VoltOn59_VS_GI::minimum() const {return 0.0;}
float VoltOn59_VS_GI::maximum() const {return 40.0;}

// GPIBInstrument interface
void VoltOn59_VS_GI::send(const char* cmd)
{
	_controller.send(_gpib_address, cmd);
}
void VoltOn59_VS_GI::send(float volts) 
{
	_controller.send(_gpib_address, volts);
}
float VoltOn59_VS_GI::receive() 
{
	 return _controller.receive(_gpib_address);
}

// INTERFACE destructor: Voltmeter
Voltmeter::~Voltmeter(){};

VoltyMetrics::VoltyMetrics(GPIBController_Stub& controller, int what_address)
	: _controller(controller), _gpib_address(what_address)
{
	_controller.insert("VoltyMetrics", what_address);
}

float VoltyMetrics::read()
{
	return _controller.receive(_gpib_address);
}

// GPIBInstrument interface
void  VoltyMetrics::send(const char* cmd)
{
	_controller.send(_gpib_address, cmd);
}
void  VoltyMetrics::send(float volts) 
{
	_controller.send(_gpib_address, volts);
}
float  VoltyMetrics::receive() 
{
	return _controller.receive(_gpib_address);
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
	GPIBController_Stub gpib;

	// Check calibration 
	VoltyMetrics meter(gpib, 14);
	Acme130_VS_GI supply1(gpib, 12);
	VoltOn59_VS_GI supply2(gpib, 13);

	std::cout << "Acme130_VS_GI relative error at 1V is: " 
		<< checkCalibration(supply1, meter, 6.0) << std::endl;
	std::cout << "Acme130_VS_GI relative error at 1V is: " 
		<< checkCalibration(supply2, meter, 8.0) << std::endl;

	transferOnGPIB(supply2, supply1);

	return 0;
}

