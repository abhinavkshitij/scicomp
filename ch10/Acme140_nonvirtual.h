// Example from pg. 280
#include <iostream>

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
	float maximum() const; // non-virtual function
};

// INHERITED CLASS: Acme 140
class Acme140 : public Acme130_VS_GI_GC
{
private:
	float max_voltage; 
public:
	enum Jumper {J1, J2}; // Possible jumper settings

	Acme140(GPIBController& controller, int gpib_address, Jumper j);
	float maximum() const; // overrides base class function
};
