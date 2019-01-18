#include "glmUtils.hpp"


#include <iostream>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

/**
 * @brief Overload << operation for vec2
 * 
 * @param out 
 * @param vec 
 * @return ostream& 
 */
ostream& operator<<(ostream &out, const vec2 vec) {
	out << "[ "
		<< vec.x << ", "
		<< vec.y
		<< " ]";

	return out;
}

/**
 * @brief Overload << operation for vec3
 * 
 * @param out 
 * @param vec 
 * @return ostream& 
 */
ostream& operator<<(ostream &out, const vec3 vec) {
	out << "[ "
		<< vec.x << ", "
		<< vec.y << ", "
		<< vec.z
		<< " ]";

	return out;
}

