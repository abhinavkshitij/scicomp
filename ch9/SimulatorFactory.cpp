#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstring>
#include <iterator>
#include <algorithm>
#include <vector>
#include "SimulatorFactory.h"

// Client function: transferOnGPIB
void transferOnGPIB(GPIBInstrument& from, GPIBInstrument& to)
{
	to.send(from.receive());
}

// Interface destructor: Controller
GPIBController::~GPIBController(){};

// // DERIVED Class: Controller 
// void GPIBController_GC::insert(const char* device_name, unsigned int address)
// {
// 	std::cout << device_name << " now at address " << address << std::endl;
// }
// void GPIBController_GC::send(unsigned int address, const char* cmd)
// {
// 	std::cout << "GPIB instrument # " << address << " sends " << cmd
// 	<< std::endl;
// }
// void GPIBController_GC::send(unsigned int address, float f)
// {
// 	std::cout << "GPIB instrument# " << address << " sends value " << f 
// 	<< std::endl;
// }
// float GPIBController_GC::receive(unsigned int address)
// {
// 	std::cout << "Please enter number for GPIB instrument #" << address << ": ";
// 	float f;
// 	std::cin >> f;
// 	return f;
// }
	

// Destructor: GPIBInstrumentSimulation
GPIBInstrumentSimulation::~GPIBInstrumentSimulation(){}


void ExperimentSimulation::apply(double voltage){}
double ExperimentSimulation::test(){return the_voltage;}	


Acme130Simulation::Acme130Simulation(ExperimentSimulation& e)
	: the_experiment(e)
{
	// my_controller.insert("Acme130Simulation", what_address);
}

void Acme130Simulation::send(const char*)
{
	//
}

void Acme130Simulation::send(float f)
{
	the_experiment.apply(f);
}

float Acme130Simulation::receive()
{
	//
}


VoltyMetricsSimulation::VoltyMetricsSimulation(ExperimentSimulation& e)
	: the_experiment(e)
{
	// my_controller.insert("VoltyMetrics", what_address);
}

void VoltyMetricsSimulation::send(const char*)
{
	//
}

void VoltyMetricsSimulation::send(float f)
{
	//
}

float VoltyMetricsSimulation::receive()
{
	return the_experiment.test();
}

SimulatorFactory::~SimulatorFactory(){}


// GPIBSimulation constructor
GPIBController_GIS::GPIBController_GIS(const SimulatorFactory& factory)
	: simulator_factory(factory), simulators(31)
{
	simulators = 0;
}

GPIBController_GIS::~GPIBController_GIS()
{
	for (int i = 0; i < simulators.size(); ++i)
	{
		delete simulators[i];
	}
}

// Insert function: Call factory to register a new intrument to the array.
void GPIBController_GIS::insert(const char* device_name, unsigned int address)
{
	simulators[address] = simulator_factory.create(device_name, the_experiment);
}

void GPIBController_GIS::send(unsigned int address, const char* msg)
{
	GPIBInstrumentSimulation* ip = simulators[address];
	if(ip!=0)
	{
		ip -> send(msg);
	}
	else
	{
		throw std::invalid_argument("No simulator at specified GPIB address");
	}
}

void GPIBController_GIS::send(unsigned int address, float f)
{
	GPIBInstrumentSimulation *ip = simulators[address];
	if(ip!=0)
	{
		ip -> send(f);
	}
	else
	{
		throw std::invalid_argument("No simulator at specified GPIB address");
	}
}

float GPIBController_GIS::receive(unsigned int address)
{
	float val;
	GPIBInstrumentSimulation* ip = simulators[address];
	if(ip!=0)
	{
		val = ip -> receive();
	}
	else
	{
		throw std::invalid_argument("No simulator at specified GPIB address");
	}
}

GPIBInstrumentSimulation* 
	MySimulators::create(const char* device_name, ExperimentSimulation& exp) const
{
	GPIBInstrumentSimulation* sim_p;
	if(strcmp(device_name, "Acme130_VS_GI_GC") == 0)
		sim_p = new Acme130Simulation(exp);
	else if(strcmp(device_name, "VoltyMetrics_VM_GI") == 0)
		sim_p = new VoltyMetricsSimulation(exp);
	else
		throw std::invalid_argument("Simulator for specified device unavailable");
		sim_p = NULL;
	// return EXIT_SUCCESS;
}	


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

// GPIBInstrument interface
void Acme130_VS_GI_GC::send(const char* cmd)
{
	my_controller.send(my_gpib_address, cmd);
}
void Acme130_VS_GI_GC::send(float volts) 
{
	my_controller.send(my_gpib_address, volts);
}
float Acme130_VS_GI_GC::receive() 
{
	 return my_controller.receive(my_gpib_address);
}	 

// Voltage supply 2: VoltOn59_VS_GI_GC
 VoltOn59_VS_GI_GC::VoltOn59_VS_GI_GC(GPIBController& controller, int gpib_address)
		: my_controller(controller), my_gpib_address(gpib_address)
{
	my_controller.insert("VoltOn59_VS_GI_GC", gpib_address);
}

void VoltOn59_VS_GI_GC::set(float volts)
{
	if (volts > maximum() || volts < minimum()) 
		throw std::invalid_argument("VoltOn59_VS_GI_GC voltage out of range");
	my_controller.send(my_gpib_address, volts);
}

float VoltOn59_VS_GI_GC::minimum() const {return 0.0;}
float VoltOn59_VS_GI_GC::maximum() const {return 40.0;}

// GPIBInstrument interface
void VoltOn59_VS_GI_GC::send(const char* cmd)
{
	my_controller.send(my_gpib_address, cmd);
}
void VoltOn59_VS_GI_GC::send(float volts) 
{
	my_controller.send(my_gpib_address, volts);
}
float VoltOn59_VS_GI_GC::receive() 
{
	 return my_controller.receive(my_gpib_address);
}

// INTERFACE destructor: Voltmeter
Voltmeter::~Voltmeter(){};


VoltyMetrics_VM_GI::VoltyMetrics_VM_GI(GPIBController& controller, int what_address)
	: my_controller(controller), my_gpib_address(what_address)
{
	my_controller.insert("VoltyMetrics_VM_GI", what_address);
}

float VoltyMetrics_VM_GI::read()
{
	return my_controller.receive(my_gpib_address);
}


// CLIENT FUNCTION
float checkCalibration(VoltageSupply& supply, Voltmeter& meter, float test_voltage)
{
	supply.set(test_voltage);
	return abs(test_voltage - meter.read()) / test_voltage;
}


// CLIENT CLASS
IVTester::IVTester(VoltageSupply& vs, Voltmeter& vm)
	: the_voltage_supply(vs), the_voltmeter(vm)
{
	// empty constructor
}

double IVTester::current(double voltage)
{
	the_voltage_supply.set(voltage);
	return the_voltmeter.read();
}





// DRIVER CODE
int main(int argc, char const *argv[])
{
	MySimulators simulators;
	GPIBController_GIS gpib(simulators);
	
	// Check calibration 
	Acme130_VS_GI_GC supply(gpib, 12);
	VoltyMetrics_VM_GI meter(gpib, 13);

	IVTester iv(supply, meter);
	double v_step = 1.0;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << iv.current(v_step * i) << std::endl;
	}



	return 0;
}

