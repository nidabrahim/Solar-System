#include "sphere.hpp"

#define BUFFER_OFFSET(bytes) ((GLubyte*) NULL + (bytes))

Sphere::Sphere(GLuint depth) : vertices(new boost::container::vector<GLfloat>()){
	vertex_buffers = new GLuint;

	const float X = .525731112119133606;
	const float Z = .850650808352039932;

	GLfloat verts[12][3] = {
		{-X, 0.0, Z}, {X, 0.0, Z}, {-X, 0.0, -Z}, {X, 0.0, -Z},
		{0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X},
		{Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0}
	};

	GLuint indices[] = {
		1,4,0,     4,9,0,    4,5,9,    8,5,4,    1,8,4,
		1,10,8,    10,3,8,   8,3,5,    3,2,5,    3,7,2,
		3,10,7,    10,6,7,   6,11,7,   6,0,11,   6,1,0,
		10,1,6,    11,0,9,   2,11,9,   5,2,9,    11,2,7
	};

	GLuint index_count = 60;

	for (unsigned int i = 0; i < index_count; i+=3) {
		float v1[3] = {
			verts[indices[i]][0],
			verts[indices[i]][1],
			verts[indices[i]][2]
		};
		float v2[3] = {
			verts[indices[i + 1]][0],
			verts[indices[i + 1]][1],
			verts[indices[i + 1]][2]
		};
		float v3[3] = {
			verts[indices[i + 2]][0],
			verts[indices[i + 2]][1],
			verts[indices[i + 2]][2]
		};
		subdivide(v1, v2, v3, depth);
	}
	vertex_count = vertices->size() / 3;

	glGenBuffers(1, vertex_buffers);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffers[0]);

	glBufferData(
			GL_ARRAY_BUFFER,
			vertices->size() * sizeof(GLfloat),
			vertices->data(),
			GL_STATIC_DRAW
	);
}

void Sphere::subdivide(float *v1, float *v2, float *v3, long depth) {
	GLfloat v12[3], v23[3], v31[3];

	if (depth == 0) {
		vertices->push_back(v1[0]);
		vertices->push_back(v1[1]);
		vertices->push_back(v1[2]);
		vertices->push_back(v2[0]);
		vertices->push_back(v2[1]);
		vertices->push_back(v2[2]);
		vertices->push_back(v3[0]);
		vertices->push_back(v3[1]);
		vertices->push_back(v3[2]);
		return;
	}

	for (GLuint i = 0; i < 3; i++) {
		v12[i] = (v1[i] + v2[i]) / 2.0;
		v23[i] = (v2[i] + v3[i]) / 2.0;
		v31[i] = (v3[i] + v1[i]) / 2.0;
	}

	normalize(v12);
	normalize(v23);
	normalize(v31);

	subdivide(v1, v12, v31, depth - 1);
	subdivide(v2, v23, v12, depth - 1);
	subdivide(v3, v31, v23, depth - 1);
	subdivide(v12, v23, v31, depth - 1);
}

void Sphere::normalize(float v[3]) {
	GLfloat d = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	if (d == 0.0) {
		throw "Zero length vector";
	}

	v[0] /= d;
	v[1] /= d;
	v[2] /= d;
}

void Sphere::draw() {

	glEnableVertexAttribArray(s_Attribute);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffers[0]);

	glVertexAttribPointer(
			s_Attribute,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			BUFFER_OFFSET(0)
	);

	glDrawArrays(GL_TRIANGLES, 0, vertex_count);
	
	glDisableVertexAttribArray(s_Attribute);

}
