// Example from pg 117.
#include <iostream>
#include <cstring>

using namespace std;

extern void command_a(){
	cout << "Doing a" << endl;
	float x;
	cin >> x;
	if (x < 0) {
		throw "Nonnegative input expected in command a";
	}
}
extern void command_b(){cout << "Doing b" << endl;}
extern void command_c(){cout << "Doing c" << endl;}

int main(int argc, char const *argv[])
{
	char command[100];
	while(cin >> command){
		if (strcmp(command,"a") == 0) command_a();
		else if (strcmp(command,"b") == 0) command_b();
		else if (strcmp(command,"c") == 0) command_c();
		else cout << "Unknown command: " << command  << endl;
	}
	return 0;
}