#include <iostream>
#include <stdexcept>
#include <cmath>
#include "Acme140.h"

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
	std::cout << "Enter volts (default = 1) for GPIB instrument #" << address << ": ";
	float f=1.f;
	// std::cin >> f;
	return f;
}
// Interface destructor: Controller
GPIBController::~GPIBController(){};	

// Interface destructor: Voltage Supply
VoltageSupply::~VoltageSupply(){};


// Voltage supply 1: ACME 130
Acme130_VS_GI_GC::Acme130_VS_GI_GC(GPIBController& controller, int gpib_address)
		: _controller(controller), _gpib_address(gpib_address)
{
	_controller.insert("Acme130_VS_GI_GC", gpib_address);
}

void Acme130_VS_GI_GC::set(float volts)
{
	if (volts > maximum() || volts < minimum()) 
		std::cout << "Voltage out of range" << std::endl;
	else
		// throw std::invalid_argument("Acme130_VS_GI_GC voltage out of range");
		_controller.send(_gpib_address, volts); // send(): declared in GPIBInterface; defined in Acme130 class 
}

float Acme130_VS_GI_GC::minimum() const {return 0.0;}
float Acme130_VS_GI_GC::maximum() const {return 40.0;}


// Acme 140 constructor (builds base implmentation Acme130 subobject)
Acme140::Acme140(GPIBController& controller, int gpib_address, Jumper j)
	: Acme130_VS_GI_GC(controller, gpib_address),
	  max_voltage(j == J1 ? 10.f : 50.f){}

float Acme140::maximum() const {return max_voltage;}

// Voltage supply 2: VoltOn59_VS_GI_GC
 VoltOn59_VS_GI_GC::VoltOn59_VS_GI_GC(GPIBController& controller, int gpib_address)
		: _controller(controller), _gpib_address(gpib_address)
{
	_controller.insert("VoltOn59_VS_GI_GC", gpib_address);
}

void VoltOn59_VS_GI_GC::set(float volts)
{
	if (volts > maximum() || volts < minimum()) 
		throw std::invalid_argument(" VoltOn59_VS_GI_GC voltage out of range");
	_controller.send(_gpib_address, volts);
}

float VoltOn59_VS_GI_GC::minimum() const {return 0.0;}
float VoltOn59_VS_GI_GC::maximum() const {return 40.0;}


// INTERFACE destructor: Voltmeter
Voltmeter::~Voltmeter(){};


VoltyMetrics::VoltyMetrics(GPIBController& controller, int what_address)
	: _controller(controller), _gpib_address(what_address)
{
	_controller.insert("VoltyMetrics", what_address);
}

float VoltyMetrics::read()
{
	return _controller.receive(_gpib_address);
}


// CLIENT FUNCTION
float checkCalibration(VoltageSupply& supply, Voltmeter& meter, float test_voltage)
{
	supply.set(test_voltage);
	return abs(test_voltage - meter.read()) / test_voltage;
}


// CLIENT CLASS
IVTester::IVTester(VoltageSupply& vs, Voltmeter& vm)
	: _voltage_supply(vs), _voltmeter(vm)
{
	// empty constructor
}

double IVTester::current(double voltage)
{
	_voltage_supply.set(voltage);
	return _voltmeter.read();
}


// Destructor: GPIBInstrumentSimulation
GPIBInstrumentSimulation::~GPIBInstrumentSimulation(){}


void ExperimentSimulation::apply(double voltage){}
double ExperimentSimulation::test(){return _voltage;}	


void Acme130Simulation::send(float f)
{
	_experiment.apply(f);
}

float VoltyMetricsSimulation::receive()
{
	return _experiment.test();
}


// DRIVER CODE
int main(int argc, char const *argv[])
{
	GPIBController_GC gpib;
	Acme140 supply1(gpib, 12, Acme140::J2);
	Acme140 supply2(gpib, 13, Acme140::J1);
	Acme130_VS_GI_GC supply3(gpib, 14);
	std::cout << std::endl;
	
	// Use directly
	std::cout << "Use directly" << std::endl;
	std::cout << supply1.maximum() << std::endl;
	std::cout << supply2.maximum() << std::endl;
	std::cout << supply3.maximum() << std::endl;
	std::cout << std::endl;

	// Use supply1,2,3 as Acme130_VS_GI_GC [base impl class]
	Acme130_VS_GI_GC& s1_as_130 = supply1;
	Acme130_VS_GI_GC& s2_as_130 = supply2;
	Acme130_VS_GI_GC& s3_as_130 = supply3;

	std::cout << "Use as Acme130 base impl" << std::endl;
	std::cout << s1_as_130.maximum() << std::endl;
	std::cout << s2_as_130.maximum() << std::endl;
	std::cout << s3_as_130.maximum() << std::endl;
	std::cout << std::endl;

	// Use as VoltageSupply [base interface class]
	VoltageSupply& v1 = supply1;
	VoltageSupply& v2 = supply2;
	VoltageSupply& v3 = supply3;

	std::cout << "Use as VoltageSupply base interface" << std::endl;
	std::cout << v1.maximum() << std::endl;
	std::cout << v2.maximum() << std::endl;
	std::cout << v3.maximum() << std::endl;
	std::cout << std::endl;

	// set() defined in base class calls 
	// maximum() depending on the object type
	supply1.set(15); // works
	supply2.set(15); // throws an exception
	supply3.set(15); // works
	std::cout << std::endl;

	s1_as_130.set(15); // works
	s2_as_130.set(15);  // throws an exception
	std::cout << std::endl;
	
	v1.set(15); // works 
	v2.set(15); // throws an exception
	std::cout << std::endl;
	return 0;
}

