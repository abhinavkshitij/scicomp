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

// Interface to provide acccess to set() function, which is
// present in both classes of Voltage Supply
class VoltageSupply
{
public:
	virtual void set(float volts) = 0;
	virtual float minimum() const = 0;
	virtual float maximum() const = 0;
	virtual ~VoltageSupply();
};

// Derived Class: Voltage supply 1
class Acme130_VS: public VoltageSupply
{
private:
	GPIBController_Stub my_controller; // member class: Controller
	int my_gpib_address;
public:
	Acme130_VS(GPIBController_Stub& controller, int gpib_address);
	virtual void set (float volts) override;
	virtual float minimum() const override;
	virtual float maximum() const override ;	
};


// Derived Class: Voltage supply 2
class VoltOn59_VS: public VoltageSupply
{
private:
	GPIBController_Stub my_controller; // member class: Controller
	int my_gpib_address;
public:
	VoltOn59_VS(GPIBController_Stub& controller, int gpib_address);
	virtual void set(float volts);
	virtual float minimum() const override;
	virtual float maximum() const override;	
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

// Client function calls the interface base class VoltageSupply 
float checkCalibration(VoltageSupply& supply, VoltyMetrics& meter, float test_voltage);
