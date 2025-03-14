#include <iostream>
#include <iterator>
#include <vector>

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

// // DERIVED CLASS
// class GPIBController_GC: public GPIBController
// {
// public:
// 	virtual void insert(const char* device_name, unsigned int address) override;
//  	virtual void send(unsigned int address, const char* cmd) override;
//  	virtual void send(unsigned int address, float f) override;
// 	virtual float receive(unsigned int address) override; 
// };


// BASE INTERFACE CLASS
class GPIBInstrumentSimulation
{
public:
	virtual void send(const char*) = 0;
	virtual void send(float f) = 0;
	virtual float receive() = 0;

	virtual ~GPIBInstrumentSimulation();
};

// SHARED OBJECT
class ExperimentSimulation
{
private:
	double the_voltage;
public:
	void apply(double voltage);
	double test();	
};

// DERIVED CLASS
class Acme130Simulation: public GPIBInstrumentSimulation
{
private:
	ExperimentSimulation& the_experiment;
public:
	Acme130Simulation(ExperimentSimulation& e);
	virtual void send(const char*);
	virtual void send(float f);
	virtual float receive();	
};

// DERIVED CLASS
class VoltyMetricsSimulation: public GPIBInstrumentSimulation
{
private:
	ExperimentSimulation& the_experiment;
public:
	VoltyMetricsSimulation(ExperimentSimulation& e);
	virtual void send(const char*);
	virtual void send(float f);
	virtual float receive();	
};


// INTERFACE BASE CLASS: SIMULATOR FACTORY 
class SimulatorFactory
{
public:
	virtual GPIBInstrumentSimulation* 
		create(const char* device_name, ExperimentSimulation& exp) const = 0;
	virtual ~SimulatorFactory();
};


// DERIVED INTFERFACE FROM BASE CONTROLLER
class GPIBController_GIS: public GPIBController
{
private:
	const SimulatorFactory& simulator_factory;
	CheckedSimpleArray<GPIBInstrumentSimulation*> simulators;
	ExperimentSimulation the_experiment;
public:
	GPIBController_GIS(const SimulatorFactory& factory);
	~GPIBController_GIS();

	// GPIBController INTERFACE
	virtual void insert(const char* device_name, unsigned int address) override;
	virtual void send(unsigned int address, const char* buf) override;
	virtual void send(unsigned int address, float f) override;
	virtual float receive (unsigned int address) override;
};


// DERIVED CLASS: SIMULATOR FACTORY
class MySimulators: public SimulatorFactory
{
public:
	virtual GPIBInstrumentSimulation* 
		create(const char* device_name, ExperimentSimulation& exp) const override;
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


// DERIVED CLASS 2: Voltage supply 2
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


// BASE INTERFACE CLASS
class Voltmeter
{
public:
	virtual float read() = 0;
	~Voltmeter();
};

// DERIVED CLASS: Multiple inheritence
class VoltyMetrics_VM_GI: public Voltmeter
{
private:
	GPIBController& my_controller;
	int my_gpib_address;	
public:
	VoltyMetrics_VM_GI(GPIBController& controller, int what_address);

	// Voltmeter interface
	virtual float read() override;
};


// Client function calling interface base classes VoltageSupply, Voltmeter 
float checkCalibration(VoltageSupply& supply, 
					   Voltmeter& meter, 
					   float test_voltage);


// CONCRETE CLASS
class IVTester
{
private:
	VoltageSupply& the_voltage_supply;
	Voltmeter& the_voltmeter;
public:
	IVTester(VoltageSupply& vs, Voltmeter& vm);
	double current(double voltage);
};





