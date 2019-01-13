#ifndef CUBE_HPP
#define CUBE_HPP

#define GL_GLEXT_PROTOTYPES
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glx.h>


class Cube {

	protected:
		GLuint *buffers;
		GLuint vertex_count;
		GLfloat *vertices;
		GLuint normal_count;
		GLfloat *normals;
		void draw();

	public:
		Cube();
		~Cube();
};

#endif
