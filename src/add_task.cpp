#include "json.hpp"	// https://github.com/nlohmann/json
#include "add_task.h"
#include "console_writer.h"
#include "clear_terminal.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <ctime>
using namespace std;
using json = nlohmann::json;
namespace fs = std::filesystem;

string formatTime(time_t t) {
	struct tm timeInfo;
	localtime_s(&timeInfo, &t);

	char buffer[80];
	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", &timeInfo);
	return std::string(buffer);
}

void addTask() {
	clearTerm();

	string folder = "tasks";
	string file = folder + "/data.json";
	string taskName;
	string taskDescription;
	time_t taskCreateDate = time(0);
	string taskFormattedDate = formatTime(taskCreateDate);
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

	getUserData(taskName, taskDescription,taskEndDate);	//getting data aboud task

	json newTask;
	newTask["name"] = taskName;
	newTask["description"] = taskDescription;
	newTask["createDate"] = taskFormattedDate;
	newTask["endDate"] = taskEndDate;
	tasks.push_back(newTask);	//adding newTask to tempolary task

	ofstream dataFileOut(file);	//opening file to save
	dataFileOut << tasks.dump(4);	//saving tempolary tasks to .json 
	dataFileOut.close();
	alertCode = "TaskS_A";
}


void getUserData(string &taskName, string &taskDescription, string taskEndDate[]) {
	cin.ignore(INT_MAX, '\n');	//cleaning bufor
	write("enter name >> ", 37, 0, 0); getline(cin, taskName); cout << endl;
	write("Enter description (leave blank for none) >> ", 37, 0, 0); getline(cin, taskDescription); cout << endl;

	write("enter task's end date", 37, 0, 0); cout << endl;
	write("day >> ", 90, 0, 0); cin >> taskEndDate[0]; cout << endl;
	write("month >> ", 90, 0, 0); cin >> taskEndDate[1]; cout << endl;
	write("year >> ", 90, 0, 0); cin >> taskEndDate[2]; cout << endl;
	
	if (taskDescription == "") taskDescription = "-";	//seting "-" if user not providet taskDescription
}