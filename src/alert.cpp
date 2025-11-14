#include <string>
#include <iostream>
#include "console_writer.h"

void alert(std::string &alertCode) {
	//deleteTask()
	if (alertCode == "FileEmpty_D") {
		consoleTools::write("No tasks to delete", 31, 0, 0);
	}
	else if (alertCode == "TaskS_D") {
		consoleTools::write("Task deleted successfully", 32, 0, 0);
	}
	else if (alertCode == "TaskNFound_D") {
		consoleTools::write("Task not found", 31, 0, 0);
	}

	//addTask()
	else if (alertCode == "TaskS_A") {
		consoleTools::write("Task added", 32, 0, 0);
	}

	//showTasks()
	else if (alertCode == "TaskNFound_S") {
		consoleTools::write("No tasks to show", 31, 0, 0);
	}

	alertCode = "0";
	std::cout << std::endl;
}