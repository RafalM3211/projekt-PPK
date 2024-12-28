#ifndef FILES_HANDLERS
#define FILES_HANDLERS

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

std::stringstream getLineToStringStream(std::ifstream &);

std::vector<int> parseInputsLine(std::ifstream &);

int parseOutputLine(std::ifstream &);

#endif