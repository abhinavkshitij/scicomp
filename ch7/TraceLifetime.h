// Example from pg. 186

class TraceLifetime
{
private:
	enum {max_objects_to_trace = 100};
	static char existing_objects[1+max_objects_to_trace]; // L-live,D-destroy
	static int total_created;
	int instance_number;							// Creation sequence number
	char var_name[21];								// 20 char + null

public:
	TraceLifetime(const char* variable_name);		// Create, print msg 
	~TraceLifetime();								// Destroy, print msg
};