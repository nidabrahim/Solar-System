#ifndef SPHERE_HPP
#define SPHERE_HPP

#define GL_GLEXT_PROTOTYPES
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glx.h>

#include <cmath>
#include "boost/container/vector.hpp"

using boost::container::vector;

class Sphere {
	protected:
		Sphere(GLuint depth);
		void draw();

	protected:
		void subdivide(float *v1, float *v2, float *v3, long depth);
		void normalize(float v[3]);

		GLuint *vertex_buffers;
		GLuint vertex_count;

		boost::container::vector<GLfloat> *vertices;

		GLuint s_Attribute = 0;
};


#endif
