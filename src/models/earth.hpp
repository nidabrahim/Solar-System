#ifndef EARTH_HPP
#define EARTH_HPP

#include <glm/glm.hpp>

using namespace glm;

class Earth;

#include "geometry/sphere.hpp"
#include "engine/shader_object.hpp"
#include "engine/texture_object.hpp"
#include "solar_system.hpp"
#include "engine/shader.hpp"

class Earth : public Sphere, public ShaderObject, public TextureObject {

	protected:
		Shader *shader;
		SolarSystem *solar_system;
		struct {
			GLuint model_matrix;
			GLuint earth_rotation;
			GLuint texture_day;
			GLuint texture_night;
		} shader_vars;
		GLuint texture_day;
		GLuint texture_night;
		mat4 transformation;
		void loadTexture();

	public:
		mat4 position;
		Earth(SolarSystem*);
		void draw(GLuint time);
		void compute(GLuint time);
		~Earth();
};

#endif
