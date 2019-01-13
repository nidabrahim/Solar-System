#ifndef MOON_HPP
#define MOON_HPP

class Moon;

#include "../geometry/sphere.hpp"
#include "../engine/shader_object.hpp"
#include "../engine/texture_object.hpp"
#include "../solar_system.hpp"
#include "../engine/shader.hpp"

class Moon : public Sphere, public ShaderObject, public TextureObject {

	protected:
		Shader *shader;
		GLuint texture;
		SolarSystem *solar_system;
		struct {
			GLuint model_matrix;
			GLuint texture0;
		} shader_vars;
		void loadTexture();

	public:
		mat4 position;

		Moon(SolarSystem*);
		~Moon();
		void draw(GLuint time);
};


#endif
