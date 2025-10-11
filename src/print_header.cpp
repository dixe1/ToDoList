#include "print_header.h"
#include "console_writer.h"
#include <iostream>
using namespace std;

void printHeader(bool firstStart){
	if (firstStart) {
		write("------- My to do list -------", 90,20,20); cout << endl;
	}
	else {
		write("------- My to do list -------", 90, 0, 0); cout << endl;
	}
}