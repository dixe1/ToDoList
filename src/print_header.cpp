#include "print_header.h"
#include "console_writer.h"
#include <iostream>
using namespace std;

void printHeader(bool firstStart){
	cout << "\033[?25l"; // hide cursor

	int delay = 0;
	if (firstStart) delay = 20;
	consoleTools::write("------- My to do list -------", 90, delay, delay); cout << endl;

	cout << "\033[?25h"; // show
}