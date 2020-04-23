#include <iostream>
#include "solid.h"

int main() {
	solid solid1{};
	solid solid2{ "name1" };
	solid solid3{ "name2", "path1.stl" };
	return 0;
}