#pragma once

class Point3D {
public:
	Point3D(double x, double y, double z);
	Point3D(double coordinates[3]);
	double getX();
	double getY();
	double getZ();
	void setX(double newX);
	void setY(double newY);
	void setZ(double newZ);
private:
	double x, y, z;
};