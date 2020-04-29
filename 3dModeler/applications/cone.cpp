#include <iostream>
#include "solid.hpp"
#include "vectors.hpp"
#include <cmath>

# define PI           3.14159265358979323846
using namespace vector;

int main() {
	Solid solid{ "cone", "C:\\Users\\egcoj\\3D Objects\\Generated\\cone.stl" };
	const int sides{ 14 };
	const double rot{ 2 * PI / sides };
	double c = cos(rot);
	std::cout << "Cos: " << c << std::endl;
	double s = sin(rot);
	std::cout << "Sin: " << s << std::endl;
	double affineRotZ[4][4] = {
		{c,-s, 0, 0},
		{s, c, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	double vertArr[3] = { 0,0,1 };
	Vector3D vertice = Vector3D{ vertArr };
	double baseArr[3] = { 0,1,0 };
	Vector3D base1 = Vector3D(baseArr);
	Vector3D base2 = base1.affineTransform(affineRotZ);
	for (int i = 0; i < sides; i++) {
		solid.addFacet(vertice, base1, base2);
		base1 = base2;
		base2 = base1.affineTransform(affineRotZ);
	}
	solid.end();
	return 0;
}