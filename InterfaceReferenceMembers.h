#include <iostream>

// INTERFACE: Instrument controller
class GPIBInstrument
{
public:
 	virtual void send(const char* cmd) = 0;
 	virtual void send(float f) = 0;
	virtual float receive() = 0;
};

// Client function: transferOnGPIB
void transferOnGPIB(GPIBInstrument& from, GPIBInstrument& to);

// Controller: Concrete Class with no Interface 
class GPIBController_Stub
{
public:
	void insert(const char* device_name, unsigned int address);
 	void send(unsigned int address, const char* cmd);
 	void send(unsigned int address, float f);
	float receive(unsigned int address);
};

// INTERFACE: Controller base interface
class GPIBController
{
public:
	virtual void insert(const char* device_name, unsigned int address) = 0;
 	virtual void send(unsigned int address, const char* cmd) = 0;
 	virtual void send(unsigned int address, float f) = 0;
	virtual float receive(unsigned int address) = 0; 

	virtual ~GPIBController();	
};

// DERIVED Class: Controller 
class GPIBController_GC: public GPIBController
{
public:
	virtual void insert(const char* device_name, unsigned int address) override;
 	virtual void send(unsigned int address, const char* cmd) override;
 	virtual void send(unsigned int address, float f) override;
	virtual float receive(unsigned int address) override; 
};


// INTERFACE: VoltageSupply 
class VoltageSupply
{
public:
	virtual void set(float volts) = 0;
	virtual float minimum() const = 0;
	virtual float maximum() const = 0;
	virtual ~VoltageSupply();
};

// Derived Class: Voltage supply 1, GPIBInstrument
class Acme130_VS_GI_GC: public VoltageSupply, public GPIBInstrument
{
private:
	GPIBController& my_controller; // member interface: Controller
	int my_gpib_address;
public:
	Acme130_VS_GI_GC(GPIBController& controller, int gpib_address);

	// VoltageSupply Interface
	virtual void set(float volts) override;
	virtual float minimum() const override;
	virtual float maximum() const override;

	// GPIBInstrument interface
	virtual void send(const char* cmd) override;
 	virtual void send(float f) override;
	virtual float receive() override;
};


// Derived Class: Voltage supply 2
class VoltOn59_VS_GI_GC: public VoltageSupply, public GPIBInstrument
{
private:
	GPIBController& my_controller; // member interface: Controller
	int my_gpib_address;
public:
	VoltOn59_VS_GI_GC(GPIBController& controller, int gpib_address);

	// VoltageSupply Interface
	virtual void set(float volts) override;
	virtual float minimum() const override;
	virtual float maximum() const override;

	// GPIBInstrument interface
	virtual void send(const char* cmd) override;
 	virtual void send(float f) override;
	virtual float receive() override;
};


// INTERFACE: Voltmeter
class Voltmeter
{
public:
	virtual float read() = 0;
	~Voltmeter();
};

// Derived voltmeter 
class VoltyMetrics: public Voltmeter, public GPIBInstrument
{
private:
	GPIBController& my_controller;
	int my_gpib_address;	
public:
	VoltyMetrics(GPIBController& controller, int what_address);

	// Voltmeter interface
	virtual float read() override;

	// GPIBInstrument interface
	virtual void send(const char* cmd) override;
 	virtual void send(float f) override;
	virtual float receive() override;
};


// Client function calling the interface base class VoltageSupply, Voltmter 
float checkCalibration(VoltageSupply& supply, Voltmeter& meter, float test_voltage);
