#pragma once

void addTask();
void getUserData(std::string &taskName, std::string taskEndDate[]);
std::string formatTime(time_t t);
extern std::string alertCode;