#include "json.hpp"	// https://github.com/nlohmann/json
#include "add_task.h"
#include "console_writer.h"
#include "clear_terminal.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <ctime>
using namespace std;
using json = nlohmann::json;
namespace fs = std::filesystem;

void addTask() {
	string folder = "tasks";
	string file = folder + "/data.json";
	string taskName;
	time_t taskCreateDate = time(0);
	string taskEndDate[3];

	json tasks;	//creating a variable to temporalu store json data from .json file

	if (!fs::exists(folder)) {	//checking folder if not exist creating one
		fs::create_directory(folder);
	}

	ifstream dataFileIn(file);	//opening file to read
	if (dataFileIn.is_open()) {
		dataFileIn >> tasks;	//loading .json to tempolary json in RAM
		dataFileIn.close();
	}
	if (!tasks.is_array()) {
		tasks = json::array();	//if .json wasn't array set array
	}

	clearTerm();
	getUserData(taskName,taskEndDate);	//getting data aboud task

	json newTask;
	newTask["name"] = taskName;
	tasks.push_back(newTask);	//adding newTask to tempolary task

	ofstream dataFileOut(file);	//opening file to save
	dataFileOut << tasks.dump(4);	//saving tempolary tasks to .json 
	dataFileOut.close();
}


void getUserData(std::string &taskName, std::string taskEndDate[]) {
	cin.ignore(INT_MAX, '\n');	//cleaning bufor
	write("enter name >> ", 37, 0, 0); getline(cin, taskName); cout << endl;

	write("enter task's end date", 37, 0, 0); cout << endl;
	write("day >> ", 90, 0, 0); cin >> taskEndDate[0]; cout << endl;
	write("mounth >> ", 90, 0, 0); cin >> taskEndDate[1]; cout << endl;
	write("year >> ", 90, 0, 0); cin >> taskEndDate[2]; cout << endl;
}