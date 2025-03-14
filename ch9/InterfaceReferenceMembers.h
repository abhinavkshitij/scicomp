#include <iostream>

// VIRTUAL INTERFACE: Instrument controller
class GPIBInstrument
{
public:
 	virtual void send(const char* cmd) = 0;
 	virtual void send(float f) = 0;
	virtual float receive() = 0;
};

// Client function:
void transferOnGPIB(GPIBInstrument& from, GPIBInstrument& to);

// BASE INTERFACE CLASS
class GPIBController
{
public:
	virtual void insert(const char* device_name, unsigned int address) = 0;
 	virtual void send(unsigned int address, const char* cmd) = 0;
 	virtual void send(unsigned int address, float f) = 0;
	virtual float receive(unsigned int address) = 0; 
	virtual ~GPIBController();	
};

// DERIVED CLASS
class GPIBController_GC: public GPIBController
{
public:
	virtual void insert(const char* device_name, unsigned int address) override;
 	virtual void send(unsigned int address, const char* cmd) override;
 	virtual void send(unsigned int address, float f) override;
	virtual float receive(unsigned int address) override; 
};


// BASE INTERFACE CLASS
class VoltageSupply
{
public:
	virtual void set(float volts) = 0;
	virtual float minimum() const = 0;
	virtual float maximum() const = 0;
	virtual ~VoltageSupply();
};

// DERIVED CLASS 1: Voltage supply 1
class Acme130_VS_GI_GC: public VoltageSupply
{
private:
	GPIBController& _controller; // member interface: Controller
	int _gpib_address;
public:
	Acme130_VS_GI_GC(GPIBController& controller, int gpib_address);

	// VoltageSupply Interface
	virtual void set(float volts) override;
	virtual float minimum() const override;
	virtual float maximum() const override;
};


// DERIVED CLASS 2: Voltage supply 2
class VoltOn59_VS_GI_GC: public VoltageSupply
{
private:
	GPIBController& _controller; // member interface: Controller
	int _gpib_address;
public:
	VoltOn59_VS_GI_GC(GPIBController& controller, int gpib_address);

	// VoltageSupply Interface
	virtual void set(float volts) override;
	virtual float minimum() const override;
	virtual float maximum() const override;
};


// BASE INTERFACE CLASS
class Voltmeter
{
public:
	virtual float read() = 0;
	~Voltmeter();
};

// DERIVED CLASS: Multiple inheritence
class VoltyMetrics: public Voltmeter
{
private:
	GPIBController& _controller;
	int _gpib_address;	
public:
	VoltyMetrics(GPIBController& controller, int what_address);

	// Voltmeter interface
	virtual float read() override;
};


// Client function calling interface base classes VoltageSupply, Voltmeter 
float checkCalibration(VoltageSupply& supply, Voltmeter& meter, float test_voltage);
