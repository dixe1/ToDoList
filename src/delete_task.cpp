#include "clear_terminal.h"
#include "console_writer.h"
#include "delete_task.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
using namespace std;
using json = nlohmann::json;
namespace fs = std::filesystem;

void deleteTask() {
	clearTerm();
	string folder = "tasks";
	string file = folder + "/data.json";
	string taskName;

	if (!fs::exists(file)) {	//checking file
		write("no tasks found", 31, 0, 0);
	}

	ifstream dataFileIn(file);
	json tasks;
	dataFileIn >> tasks;	// downloading data from .json to variable
	dataFileIn.close();

	if (!tasks.is_array() || tasks.empty()) {
		//No tasks to delete
		alertCode = "FileEmpty_D";
		return;
	}

	write("enter task's name >> ", 90, 0, 0);
	cin.ignore(INT_MAX, '\n');
	(getline(cin, taskName));

	bool found = false;
	for (auto it = tasks.begin(); it != tasks.end(); ++it) {
		if ((*it)["name"] == taskName) {	//scaning all names
			tasks.erase(it);
			found = true;
			break;
		}
	}

	if (found) {
		ofstream dataFileOut(file);
		dataFileOut << tasks.dump(4);
		dataFileOut.close();
		alertCode = "TaskS_D";
		//Task deleted successfully
	}
	else {
		alertCode = "TaskNFound_D";
		//Task not found
	}
}