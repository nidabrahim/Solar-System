#include "glmUtils.hpp"


#include <iostream>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

ostream& operator<<(ostream &out, const vec2 vec) {
	out << "[ "
		<< vec.x << ", "
		<< vec.y
		<< " ]";

	return out;
}

ostream& operator<<(ostream &out, const vec3 vec) {
	out << "[ "
		<< vec.x << ", "
		<< vec.y << ", "
		<< vec.z
		<< " ]";

	return out;
}

