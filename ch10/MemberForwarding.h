#include <iostream>

// INTERFACE: Controller 
class GPIBInstrument
{
public:
 	virtual void send(const char* cmd) = 0;
 	virtual void send(float f) = 0;
	virtual float receive() = 0;
};

// Controller 
class GPIBController
{
public:
	void insert(const char* device_name, unsigned int address);
 	void send(unsigned int address, const char* cmd);
 	void send(unsigned int address, float f);
	float receive(unsigned int address);
};

// Client function: transferOnGPIB
void transferOnGPIB(GPIBInstrument& from, GPIBInstrument& to);

// Member function forwarding
class GPIBInstrumentData 
{
public:
	GPIBInstrumentData(GPIBController& c, int address, const char* name);
// GPIBInstrument interface
	void send(const char*);
	void send(float f);
	float receive();
private:
	GPIBController& _controller;
	int _gpib_address;
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
class Acme130_Fwd: public VoltageSupply, public GPIBInstrument
{
private:
	GPIBInstrumentData _gpib_rep; 

public:
	Acme130_Fwd(GPIBController& controller, int gpib_address);

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
class VoltOn59_Fwd: public VoltageSupply, public GPIBInstrument
{
private:
	GPIBInstrumentData _gpib_rep; 

public:
	VoltOn59_Fwd(GPIBController& controller, int gpib_address);

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
class VoltyMetrics_Fwd: public Voltmeter, public GPIBInstrument
{
private:
	GPIBInstrumentData _gpib_rep; 
public:
	VoltyMetrics_Fwd(GPIBController& controller, int what_address);

	// Voltmeter interface
	virtual float read() override;

	// GPIBInstrument interface
	virtual void send(const char* cmd) override;
 	virtual void send(float f) override;
	virtual float receive() override;
};

// Client function calling the interface base class VoltageSupply, Voltmter 
float checkCalibration(VoltageSupply& supply, Voltmeter& meter, float test_voltage);
