#include <string>
#include <iostream>
#include "console_writer.h"

void alert(std::string &alertCode) {
	//deleteTask()
	if (alertCode == "FileEmpty_D") {
		write("No tasks to delete", 31, 0, 0);
	}
	else if (alertCode == "TaskS_D") {
		write("Task deleted successfully", 32, 0, 0);
	}
	else if (alertCode == "TaskNFound_D") {
		write("Task not found", 31, 0, 0);
	}

	//addTask()
	else if (alertCode == "TaskS_A") {
		write("Task added", 32, 0, 0);
	}

	//showTasks()
	else if (alertCode == "TaskNFound_S") {
		write("No tasks to show", 31, 0, 0);
	}

	alertCode = "0";
	std::cout << std::endl;
}