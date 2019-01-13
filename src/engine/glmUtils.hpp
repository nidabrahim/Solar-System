#ifndef GLM_UTILS_HPP
#define GLM_UTILS_HPP

#include <iostream>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

ostream& operator<<(ostream &out, const vec2 vec);
ostream& operator<<(ostream &out, const vec3 vec); 

#endif 