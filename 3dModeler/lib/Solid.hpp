#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Point3D.hpp"
class Solid {
public:
	Solid(std::string name = "", std::string savepath = "solid.stl");
	void end();
	void addFacet(Point3D point1, Point3D point2, Point3D point3);
private:
	std::ofstream document;
	std::string solidName;
};