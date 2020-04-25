#include <iostream>

// Controller 
class GPIBController_Stub
{
public:
	void insert(const char* device_name, unsigned int address);
 	void send(unsigned int address, const char* cmd);
 	void send(unsigned int address, float f);
	float receive(unsigned int address);
};


// Voltage supply 1
class Acme130
{
private:
	GPIBController_Stub my_controller; // member class: Controller
	int my_gpib_address;
public:
	Acme130(GPIBController_Stub& controller, int gpib_address);
	void set(float volts);
	double minimum() const;
	double maximum() const;	
};


// Voltage supply 2
class VoltOn59
{
private:
	GPIBController_Stub my_controller; // member class: Controller
	int my_gpib_address;
public:
	VoltOn59(GPIBController_Stub& controller, int gpib_address);
	void set(float volts);
	double minimum() const;
	double maximum() const;	
};


// Voltmeter
class VoltyMetrics
{
private:
	GPIBController_Stub my_controller;
	int my_gpib_address;	
public:
	VoltyMetrics(GPIBController_Stub& controller, int what_address);
	float read();
};

// Client function
float checkCalibration1(Acme130& supply, VoltyMetrics& meter, float test_voltage);
float checkCalibration2(VoltOn59& supply, VoltyMetrics& meter, float test_voltage);
