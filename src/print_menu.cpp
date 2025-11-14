#include "print_menu.h"
#include "console_writer.h"
#include <iostream>

using namespace std;

void printMenu() {
	cout << endl;

	consoleTools::write("(A) add task", 92, 0, 0); cout << endl;
	consoleTools::write("(D) delete task", 91, 0, 0); cout << endl;
	consoleTools::write("_______________", 90, 0, 0); cout << endl;
	consoleTools::write("(S) show tasks", 96, 0, 0); cout << endl;
	consoleTools::write("(E) exit", 90, 0, 0); cout << endl;

	cout << endl;
}