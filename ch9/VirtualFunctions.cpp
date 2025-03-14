#include <iostream>
#include <stdexcept>
#include <cmath>
#include "VirtualFunctions.h"

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
	std::cout << "GPIB instrument# " << address << " sends voltage " << f 
	<< std::endl;
}
float GPIBController_Stub::receive(unsigned int address)
{
	std::cout << "Please enter number for GPIB instrument #" << address << ": ";
	float f=1.f;
	// std::cin >> f;
	return f;
}


// Voltage Supply
 VoltageSupply::~VoltageSupply(){};


// Voltage supply 1: ACME 130
Acme130_VS::Acme130_VS(GPIBController_Stub& controller, int gpib_address)
		: _controller(controller), _gpib_address(gpib_address)
{
	_controller.insert("Acme130_VS", gpib_address);
}

void Acme130_VS::set(float volts)
{
	if (volts > maximum() || volts < minimum()) 
		throw std::invalid_argument("Acme130_VS voltage out of range");
	_controller.send(_gpib_address, volts);
}

float Acme130_VS::minimum() const {return 0.0;}
float Acme130_VS::maximum() const {return 40.0;}


// Voltage supply 2: VoltOn59_VS
 VoltOn59_VS::VoltOn59_VS(GPIBController_Stub& controller, int gpib_address)
		: _controller(controller), _gpib_address(gpib_address)
{
	_controller.insert("VoltOn59_VS", gpib_address);
}

void VoltOn59_VS::set(float volts)
{
	if (volts > maximum() || volts < minimum()) 
		throw std::invalid_argument(" VoltOn59_VS voltage out of range");
	_controller.send(_gpib_address, volts);
}

float VoltOn59_VS::minimum() const {return 0.0;}
float VoltOn59_VS::maximum() const {return 40.0;}


// Voltmeter
VoltyMetrics::VoltyMetrics(GPIBController_Stub& controller, int what_address)
	: _controller(controller), _gpib_address(what_address)
{
	_controller.insert("VoltyMetrics", what_address);
}

float VoltyMetrics::read()
{
	return _controller.receive(_gpib_address);
}


// Client function
float checkCalibration(VoltageSupply& supply, VoltyMetrics& meter, float test_voltage)
{
	supply.set(test_voltage);
	return abs(test_voltage - meter.read()) / test_voltage;
}

// DRIVER CODE
int main(int argc, char const *argv[])
{
	GPIBController_Stub gpib;
	Acme130_VS supply1(gpib, 12);
	VoltOn59_VS supply2(gpib, 13);

	std::cout << "Reset Acme130_VS" << std::endl;
	supply1.reset(); // reset() is defined in VoltageSupply interface base class
	std::cout << "Reset VoltOn59_VS" << std::endl;
	supply2.reset();

	// Check calibration 
	VoltyMetrics meter(gpib, 14);
	std::cout << "Acme130_VS relative error at 1V is: " 
		<< checkCalibration(supply1, meter, 6.0) << std::endl;
	std::cout << "VoltOn59_VS relative error at 1V is: " 
		<< checkCalibration(supply2, meter, 8.0) << std::endl;
	
	return 0;
}

