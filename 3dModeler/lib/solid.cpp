#include "solid.hpp"
#include "vectors/Vector3D.hpp"
#include "Vector3D.hpp"
#include "Vector.hpp"
#include "vectors.hpp"
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

void Solid::addFacet(Vector3D point1, Vector3D point2, Vector3D point3) {
	Vector3D difference1 = point2.subtract(point1); //translate to vectors relative to point 1
	Vector3D difference2 = point3.subtract(point1);
	Vector3D normal = difference1.cross(difference2); // find orthagonal vector
	normal.scale(1 / normal.getMagnitude()); // transform to unit vector
	document << "facet normal " << normal.str() << "\n\touter loop\n";
	document << "\t\tvertex " << point1.str() << "\n";
	document << "\t\tvertex " << point2.str() << "\n";
	document << "\t\tvertex " << point3.str() << "\n";
	document << "\tendloop\nendfacet";
	document << endl;
}


void Solid::end() {
	document << "endsolid " << solidName << endl;
	document.close();
}
