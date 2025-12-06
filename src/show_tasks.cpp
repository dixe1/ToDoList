#include "show_tasks.h"
#include "console_writer.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
using namespace std;
using json = nlohmann::json;
void showTasks() {
    string file = "tasks/data.json";
    ifstream dataFile(file);
    if (!dataFile.is_open()) {
        consoleTools::write("No tasks found.\n", 31, 0, 0);
        return;
    }
    json tasks;
    dataFile >> tasks;
    dataFile.close();

    if (!tasks.is_array() || tasks.empty()) {
        //No tasks to display
        alertCode = "TaskNFound_S";
        return;
    }


    int index = 1;
    for (const auto& task : tasks) {
        consoleTools::write("+ " + task["name"].get<string>(), 32, 0, 0); cout << endl;
        consoleTools::write("    |-- Description: " + task["description"].get<string>(), 36, 0, 0); cout << endl;
        consoleTools::write("    |-- Create date: " + task["createDate"].get<string>(), 36, 0, 0); cout << endl;

        auto endDate = task["endDate"];
        consoleTools::write("    |-- End date: " + endDate[0].get<string>() + "-" + endDate[1].get<string>() + "-" + endDate[2].get<string>(), 36, 0, 0); cout << endl;

        cout << endl;
        index++;
    }
}