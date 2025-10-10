#include "clear_terminal.h"
#include <iostream>

void clearTerm() { std::cout << "\033[2J\033[1;1H"; }