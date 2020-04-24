#include "Point3D.hpp"

Point3D::Point3D(double x, double y, double z) :x(x), y(y), z(z) {}

/**
	Constructs a Point3D using the given coordinates, taking index 0 as x, index 1 as y, and index 2 as z.
*/
Point3D::Point3D(double coordinates[3]) : Point3D(coordinates[0], coordinates[1], coordinates[2]) {}

double Point3D::getX() { return x; }
double Point3D::getY() { return y; }
double Point3D::getZ() { return z; }
void Point3D::setX(double newX) { x= newX; }
void Point3D::setY(double newY) { y = newY; }
void Point3D::setZ(double newZ) { z = newZ; }