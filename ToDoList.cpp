#include "console_writer.h" // https://github.com/dixe1/UsefulFunctions/tree/main/console_writer
#include "clear_terminal.h"
#include "print_header.h"
#include "print_menu.h"
#include "add_task.h"
#include "delete_task.h"
#include "show_tasks.h"
#include "alert.h"
#include <iostream>
#include <Windows.h>
using namespace std;

string alertCode = "0";
int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	bool firstStart = true;
	bool showTaskOpen = false;
	while (true) {
		clearTerm();
		char userChoice = '0';
		printHeader(firstStart); firstStart = false;	// printing the application name [ use write() only with first run ]
		printMenu(); //printing menu options

		alert(alertCode);
		if (showTaskOpen) { showTasks(); }

		write(">> ", 90, 0, 0);
		if (!(cin >> userChoice)) {	// Validate user input
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			clearTerm();
			continue;
		}
		showTaskOpen = false;

		switch (userChoice)
		{
		case 'A':
		case 'a':
			addTask();	//	done
			break;

		case 'D':
		case 'd':
			deleteTask();
			break;

		case 'S':
		case 's'://show task
			showTaskOpen = true;
			break;

		case 'E':
		case 'e'://exit
			return 0;
		default:
			clearTerm();
			continue;
		}
	}
	return 0;
}