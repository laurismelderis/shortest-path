#pragma once

#include <vector>
#include <string>

#include <iostream>
#include <fstream>
#include <sstream>

class CSV
{
public:
	static std::vector<std::string> read(std::string fileName);
	static void print(std::vector<std::string> content);
};