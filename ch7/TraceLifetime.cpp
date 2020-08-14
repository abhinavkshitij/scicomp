// Example from pg. 186
#include "TraceLifetime.h"
#include <cstring>
#include <iostream>

using namespace std;

char TraceLifetime::existing_objects[1+max_objects_to_trace] = "";

int TraceLifetime::total_created = 0;

TraceLifetime::TraceLifetime(const char* variable_name)
	: instance_number(total_created++)
{
	// copy first 20 char 
	strncpy(var_name, variable_name, 20);
	var_name[20] = '\0';

	if (total_created <= max_objects_to_trace){
		existing_objects[total_created-1] = 'L';
		existing_objects[total_created] = '\0';
		cout << existing_objects << " TraceLifetime constructed for " 
			 << var_name << "." << endl;
	}
}	

TraceLifetime::~TraceLifetime()
{
	if (instance_number < max_objects_to_trace){
		existing_objects[instance_number] = 'D';
		cout << existing_objects << " TraceLifetime destroyed for "
			 << var_name << "." <<  endl;
	}
}				
