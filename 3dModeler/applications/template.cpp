#include <iostream>
#include "solid.hpp"
#include "vectors.hpp"
#include <cmath>

# define PI           3.14159265358979323846
using namespace vector;

int main() {
	std::string Name = "";
	Solid solid{ Name, "C:\\Users\\egcoj\\3D Objects\\Generated\\"+Name+".stl" };
	
	// Put facets here

	solid.end();
	return 0;
}