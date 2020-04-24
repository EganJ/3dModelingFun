#include <iostream>
#include "solid.hpp"

int main() {
	Solid solid{ "name2", "object.stl" };
	Point3D p1{ 1,0,0 };
	Point3D p2{ 0,1,0 };
	Point3D p3{ 0,0,1 };
	Point3D p4{ 0,0,0 };
	solid.addFacet(p1, p2, p3);
	solid.addFacet(p2, p3, p4);
	solid.addFacet(p1, p2, p4);
	solid.addFacet(p1, p3, p4);

	solid.end();
	return 0;
}