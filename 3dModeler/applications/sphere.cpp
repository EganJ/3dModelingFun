#include <iostream>
#include "solid.hpp"
#include "vectors.hpp"
#include <cmath>

# define PI           3.14159265358979323846
using namespace vector;

int main() {
	std::string Name = "Sphere";
	Solid solid{ Name, "C:\\Users\\egcoj\\3D Objects\\Generated\\" + Name + ".stl" };

	//Create a sphere representation.
	int radius = 1;
	/*
		How many vertical slices to cut the sphere into. The first and last slices are always points.
		  _---_             .          ^ z = +radius
		/       \        -------       |
	   | sphere  | =>   ----------     |z=0
		\       /        -------       |
		  `----'            .          v z = -radius
	*/
	const uint32_t verticalSlices = 40;
	/*
		How many sections to break each slice up into.
		  _---_                           +y
		/       \         \   /            ^
	   |  slice  | =>      \./        -x < + > +x
		\       /          / \             v
		  `----'          /   \           -y
	*/
	const uint32_t sliceSections = 40;

	double sliceZValues[verticalSlices]{};
	sliceZValues[0] = radius;
	sliceZValues[verticalSlices - 1] = -radius;

	double sliceRadius[verticalSlices]{};
	sliceRadius[0] = 0;
	sliceRadius[verticalSlices - 1] = 0;
	double sliceThetaStep = (PI / (verticalSlices - 1)); // step from 0 to pi
	for (int slice = 1; slice < verticalSlices - 1; slice++) {
		double theta = (slice * sliceThetaStep); // start at top of sphere and move down
		sliceZValues[slice] =cos(theta) * radius;//start at +radius go to -radius
		sliceRadius[slice] = sin(theta) * radius;//start at 0, go to +radius, then 0

	}
	//add facets iteritively
	double xyThetaStep = (2 * PI / (sliceSections));
	for (int slice = 0; slice < verticalSlices-1; slice++) {
		double zTop = sliceZValues[slice];
		double zBot = sliceZValues[slice + 1];
		double rTop = sliceRadius[slice];
		double rBot = sliceRadius[slice + 1];
		for (int section = 0; section < sliceSections; section++) {
			solid.addFacet(
				Vector3D::XYZ(cos(xyThetaStep*section)*rTop, sin(xyThetaStep * section) * rTop,zTop),
				Vector3D::XYZ(cos(xyThetaStep * section) * rBot, sin(xyThetaStep * section) * rBot,zBot),
				Vector3D::XYZ(cos(xyThetaStep * section + xyThetaStep) * rBot, sin(xyThetaStep * section + xyThetaStep) * rBot,zBot)
			);
			solid.addFacet(
				Vector3D::XYZ(cos(xyThetaStep * section) * rTop, sin(xyThetaStep * section) * rTop, zTop),
				Vector3D::XYZ(cos(xyThetaStep * section + xyThetaStep) * rBot, sin(xyThetaStep * section + xyThetaStep) * rBot, zBot),
				Vector3D::XYZ(cos(xyThetaStep * section + xyThetaStep) * rTop, sin(xyThetaStep * section + xyThetaStep) * rTop, zTop)
			);
		}
	}
	
	solid.end();
	return 0;
}