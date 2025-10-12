#include "print_header.h"
#include "console_writer.h"
#include <iostream>
using namespace std;

void printHeader(bool firstStart){
	int color = 0;
	if (firstStart) color = 20;
	write("------- My to do list -------", 90, color, color); cout << endl;
}