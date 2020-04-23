#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class solid {
public:
	//constructors
	solid(std::string name = "", std::string savepath = "solid.stl");

private:
	std::string savepath;
	std::stringstream body;
};