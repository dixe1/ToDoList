#include "console_writer.h" // https://github.com/dixe1/UsefulFunctions/tree/main/console_writer
#include "clear_terminal.h"
#include "print_header.h"
#include "print_menu.h"
#include "add_task.h"
#include <iostream>
using namespace std;

int main()
{
	bool firstStart = true;
	while (true) {
		clearTerm();
		char userChoice = '0';
		printHeader(firstStart); firstStart = false;	// printing the application name [ use write() only with first run ]
		printMenu(); //printing menu options

		write(">> ", 90, 0, 0);
		if (!(cin >> userChoice)) {	// Validate user input
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			clearTerm();
			continue;
		}

		switch (userChoice)
		{
		case 'A':
		case 'a'://add task
			addTask();
			break;
		case 'D':
		case 'd'://delete task
			break;
		case 'S':
		case 's'://show task
			break;
		case 'E':
		case 'e'://show task
			return 0;
		default:
			clearTerm();
			continue;
		}
	}
	return 0;
}