#include "cube.hpp"

#define BUFFER_OFFSET(bytes) ((GLubyte*) NULL + (bytes))

/**
 * @brief Construct a new Cube:: Cube object
 * 
 */
Cube::Cube() {
	vertex_count = normal_count = 24;
	//! Init the vertices vector
	vertices = new GLfloat[vertex_count * 3] {
		//! front
		1, 1, 1,
		1, -1, 1,
		-1, -1, 1,
		-1, 1, 1,
		//! right
		1, 1, -1,
		1, -1, -1, 
		1, -1, 1,
		1, 1, 1,
		//! back
		-1, 1, -1,
		-1, -1, -1,
		1, -1, -1,
		1, 1, -1,
		//! left
		-1, 1, 1,
		-1, -1, 1,
		-1, -1, -1,
		-1, 1, -1,
		//! top
		1, 1, 1,
		-1, 1, 1,
		-1, 1, -1,
		1, 1, -1,
		//! bottom
		1, -1, 1,
		-1, -1, 1,
		-1, -1, -1,
		1, -1, -1
	};

	//! Init the normals vector
	normals = new GLfloat[normal_count * 3] {
		//! front
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		//! right
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		//! back
		0, 0, -1,
		0, 0, -1,
		0, 0, -1,
		0, 0, -1,
		//! left
		-1, 0, 0,
		-1, 0, 0,
		-1, 0, 0,
		-1, 0, 0,
		//! top
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		//! bottom
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,
		0, -1, 0
	};

	buffers = new GLuint[2];

	glGenBuffers(2, buffers);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);

	glBufferData(
			GL_ARRAY_BUFFER,
			vertex_count * 3 * sizeof(GLfloat),
			vertices,
			GL_STATIC_DRAW
	);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);

	glBufferData(
			GL_ARRAY_BUFFER,
			normal_count * 3 * sizeof(GLfloat),
			normals,
			GL_STATIC_DRAW
	);

	delete normals;
	delete vertices;
}

/**
 * @brief Draw a new cube
 * 
 */
void Cube::draw() {
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);

	glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			BUFFER_OFFSET(0)
	);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);

	glVertexAttribPointer(
			1,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			BUFFER_OFFSET(1)
	);

	glDrawArrays(GL_QUADS, 0, vertex_count);
	
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

}

/**
 * @brief Destroy the Cube:: Cube object
 * 
 */
Cube::~Cube() {
	delete buffers;
}
