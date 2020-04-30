#include <iostream>
#include <stdexcept>
#include <cmath>
#include "InterfaceReferenceMembers.h"

// Client function: transferOnGPIB
void transferOnGPIB(GPIBInstrument& from, GPIBInstrument& to)
{
	to.send(from.receive());
}

// DERIVED Class: Controller 
void GPIBController_GC::insert(const char* device_name, unsigned int address)
{
	std::cout << device_name << " now at address " << address << std::endl;
}
void GPIBController_GC::send(unsigned int address, const char* cmd)
{
	std::cout << "GPIB instrument # " << address << " sends " << cmd
	<< std::endl;
}
void GPIBController_GC::send(unsigned int address, float f)
{
	std::cout << "GPIB instrument# " << address << " sends value " << f 
	<< std::endl;
}
float GPIBController_GC::receive(unsigned int address)
{
	std::cout << "Please enter number for GPIB instrument #" << address << ": ";
	float f;
	std::cin >> f;
	return f;
}
// Interface destructor: Controller
GPIBController::~GPIBController(){};	

// Interface destructor: Voltage Supply
VoltageSupply::~VoltageSupply(){};


// Voltage supply 1: ACME 130
Acme130_VS_GI_GC::Acme130_VS_GI_GC(GPIBController& controller, int gpib_address)
		: my_controller(controller), my_gpib_address(gpib_address)
{
	my_controller.insert("Acme130_VS_GI_GC", gpib_address);
}

void Acme130_VS_GI_GC::set(float volts)
{
	if (volts > maximum() || volts < minimum()) 
		throw std::invalid_argument("Acme130_VS_GI_GC voltage out of range");
	my_controller.send(my_gpib_address, volts); // send(): declared in GPIBInterface; defined in Acme130 class 
}

float Acme130_VS_GI_GC::minimum() const {return 0.0;}
float Acme130_VS_GI_GC::maximum() const {return 40.0;}


// Voltage supply 2: VoltOn59_VS_GI_GC
 VoltOn59_VS_GI_GC::VoltOn59_VS_GI_GC(GPIBController& controller, int gpib_address)
		: my_controller(controller), my_gpib_address(gpib_address)
{
	my_controller.insert("VoltOn59_VS_GI_GC", gpib_address);
}

void VoltOn59_VS_GI_GC::set(float volts)
{
	if (volts > maximum() || volts < minimum()) 
		throw std::invalid_argument(" VoltOn59_VS_GI_GC voltage out of range");
	my_controller.send(my_gpib_address, volts);
}

float VoltOn59_VS_GI_GC::minimum() const {return 0.0;}
float VoltOn59_VS_GI_GC::maximum() const {return 40.0;}


// INTERFACE destructor: Voltmeter
Voltmeter::~Voltmeter(){};

VoltyMetrics::VoltyMetrics(GPIBController& controller, int what_address)
	: my_controller(controller), my_gpib_address(what_address)
{
	my_controller.insert("VoltyMetrics", what_address);
}

float VoltyMetrics::read()
{
	return my_controller.receive(my_gpib_address);
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
	GPIBController_GC gpib;

	// Check calibration 
	VoltyMetrics meter(gpib, 14);
	Acme130_VS_GI_GC supply1(gpib, 12);
	VoltOn59_VS_GI_GC supply2(gpib, 13);

	std::cout << "Acme130_VS_GI_GC relative error at 1V is: " 
		<< checkCalibration(supply1, meter, 1.0) << std::endl;
	std::cout << "Acme130_VS_GI_GC relative error at 1V is: " 
		<< checkCalibration(supply2, meter, 1.0) << std::endl;

	return 0;
}

