#include "solid.hpp"
using std::endl;
/* Creates a new solid object.
*
* std::string name: name of the object. Cannot be changed. Defaults to empty.
* std::string savepath: path to be saved at. Cannot be changed. Defaults to "./solid.stl"
*/
Solid::Solid(std::string name, std::string savepath) : solidName(name), document() {
	document.open(savepath);
	document << "solid " << solidName << endl;
}

void Solid::addFacet(Point3D point1, Point3D point2, Point3D point3) {
	document << "facet normal 0 0 0\n\touter loop\n";
	document << "\t\tvertex " << point1.getX() << " " << point1.getY() << " " << point1.getZ() << "\n";
	document << "\t\tvertex " << point2.getX() << " " << point2.getY() << " " << point2.getZ() << "\n";
	document << "\t\tvertex " << point3.getX() << " " << point3.getY() << " " << point3.getZ() << "\n";
	document << "\tendloop\nendfacet";
	document << endl;
}


void Solid::end() {
	document << "endsolid " << solidName << endl;
	document.close();
}
