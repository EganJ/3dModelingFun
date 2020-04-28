#include "Vector3D.hpp"
#include "Vector.hpp"
#include <cmath>

/*
	Creates a 3D Vector with the given x, y, and z values
*/

Vector3D Vector3D::XYZ(double x, double y, double z) {
	double vals[3] = { x,y,z };
	return Vector3D(vals);
}

/*
	Constructs a new 3D Vector out of an array in the format {x, y, z}
*/
Vector3D::Vector3D(double vals[3]) : Vector<3>(vals) {}

/*
	Converts a rank 3 vector into a 3-dimensional vector, assuming dimenson 0 is X, 1 is y, and 2 is z
*/
Vector3D::Vector3D(Vector<3> v) : Vector3D( v.values ) {}

/*
	Returns the cross produce between this vector and vector v.
*/
Vector3D Vector3D::cross(Vector3D v) {
	double crossVals[3] = {
		Y() * v.Z() - Z() * v.Y(),
		Z() * v.X() - X() * v.Z(),
		X() * v.Y() - Y() * v.X()
	};
	return Vector3D(crossVals);
}
/*
	Creates a transformed version of this vector. Please seee https://en.wikipedia.org/wiki/Transformation_matrix or 
	https://en.wikipedia.org/wiki/Transformation_matrix for how Affine Transformation matrices work
	
	param affineMatrix - an affine transformation matrice in the format [row][column]
*/
Vector3D Vector3D::affineTransform(double affineMatrix[4][4]) {
	double paddedValues[4] = { X(), Y(), Z(), 1 };
	Vector<4> paddedThis = Vector<4>(paddedValues);
	Vector<4> paddedTransformation = paddedThis.matrixMultiply<4>(affineMatrix);
	double transformedValues[3] = { paddedTransformation.values[0],paddedTransformation.values[1],paddedTransformation.values[2]};
	return Vector3D(transformedValues);
}

/*
	Returns this vectors X-Value
*/
double Vector3D::X() {
	return values[0];
}

/*
	Returns this vectors Y-Value
*/
double Vector3D::Y() {
	return values[1];
}

/*
	Returns this vectors Z-Value
*/
double Vector3D::Z() {
	return values[2];
}

/*
	Sets this vectors X-Value
*/
void Vector3D::X(double x) {
	values[0] = x;
}

/*
	Sets this vectors Y-Value
*/
void Vector3D::Y(double y) {
	values[1] = y;
}

/*
	Sets this vectors Z-Value
*/
void Vector3D::Z(double z) {
	values[2] = z;
}