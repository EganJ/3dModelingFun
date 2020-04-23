#include "solid.h"

/* Creates a new solid object.
*
* Has two optional parameters:
* std::string name: name of the object. Cannot be changed
* std::string savepath: path to be saved at. Can be changed.
*/
solid::solid(std::string name, std::string savepath) : body("solid " + name + (name == "" ? "" : " ")), savepath(savepath) {
	std::cout << "body: \n" << body.str() << "|\n" << "save path: " << savepath << std::endl;
}