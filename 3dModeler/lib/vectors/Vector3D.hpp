#pragma once
#include <string>
#include "Vector.hpp"
class Vector3D : public Vector<3> {
public:
	Vector3D(Vector<3>); // NOT explicit, so can swap between them 
	Vector3D(double vals[3]);
	Vector3D cross(Vector3D crossWith); // cross product
	Vector3D affineTransform(double affineMatrix[4][4]); // affine transformation
	double X();
	double Y();							// Getters
	double Z();

	void X(double x);
	void Y(double y);                   // Setters
	void Z(double z);

	static Vector3D XYZ(double x, double y, double z);       // Convenience creator
};