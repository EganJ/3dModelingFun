#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Vector3D.hpp"
#include "Vector.hpp"
#include "vectors.hpp"
class Solid {
public:
	Solid(std::string name = "", std::string savepath = "solid.stl");
	void end();
	void addFacet(Vector3D point1, Vector3D point2, Vector3D point3);
private:
	std::ofstream document;
	std::string solidName;
};