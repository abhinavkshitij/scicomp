#include <iostream>
#include <stdexcept>
#include <cmath>
#include "Commonality.h"

using namespace std;
#define LOG(msg) {cout << msg;}
#define LOGLN(msg) {cout << msg << endl;}

// Controller
void GPIBController_Stub::insert(const char* device_name, unsigned int address)
{
	LOGLN (device_name << " now at address# " << address); 
}

void GPIBController_Stub::send(unsigned int address, const char* cmd)
{
	LOGLN("GPIB instrument # " << address << " sends command " << cmd);
}

void GPIBController_Stub::send(unsigned int address, float f)
{
	LOGLN ("GPIB instrument# " << address << " sends voltage " << f);
}

float GPIBController_Stub::receive(unsigned int address)
{
	LOG ("Enter reading for GPIB instrument# " << address << " (default = 1): ");
	float f=1.0;
	// std::cin >> f;
	return f;
}

// Voltage supply 1: ACME 130
Acme130::Acme130(GPIBController_Stub& controller, int gpib_address)
		: _controller(controller), _gpib_address(gpib_address)
{
	_controller.insert("Acme130", gpib_address);
}

void Acme130::set(float volts)
{
	if (volts > maximum() || volts < minimum()) 
		throw std::invalid_argument("Acme130 voltage out of range");
	_controller.send(_gpib_address, volts);
}

double Acme130::minimum() const {return 0.0;}
double Acme130::maximum() const {return 40.0;}


// Voltage supply 2: VoltOn59
 VoltOn59::VoltOn59(GPIBController_Stub& controller, int gpib_address)
		: _controller(controller), _gpib_address(gpib_address)
{
	_controller.insert("VoltOn59", gpib_address);
}

void  VoltOn59::set(float volts)
{
	if (volts > maximum() || volts < minimum()) 
		throw std::invalid_argument(" VoltOn59 voltage out of range");
	_controller.send(_gpib_address, volts);
}

double VoltOn59::minimum() const {return 0.0;}
double VoltOn59::maximum() const {return 40.0;}


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
float checkCalibration1(Acme130& supply, VoltyMetrics& meter, float test_voltage)
{
	supply.set(test_voltage);
	return fabs(test_voltage - meter.read()) / test_voltage;
}

float checkCalibration2(VoltOn59& supply, VoltyMetrics& meter, float test_voltage)
{
	supply.set(test_voltage);
	return fabs(test_voltage - meter.read()) / test_voltage;
}

// DRIVER CODE
int main(int argc, char const *argv[])
{
	GPIBController_Stub gpib;
	Acme130 volt_supply(gpib, 12);
	volt_supply.set(3.0);

	bool useReplacement = true;
	if(!useReplacement)
	{
		// Check calibration - 1
		VoltyMetrics meter(gpib, 14);
		Acme130 supply1(gpib, 12);
		LOGLN("Acme130 relative error at 1V is: [" 
			<< checkCalibration1(supply1, meter, 6.0));
	} 
	else
	{
		// Check calibration - 2
		VoltyMetrics meter(gpib, 14);
		VoltOn59 supply2(gpib, 17);
		LOGLN("VoltOn59 relative error at 1V is: [" 
			<< checkCalibration2(supply2, meter, 8.0));
	}		
	return 0;
}

