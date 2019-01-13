#ifndef SUN_HPP
#define SUN_HPP

class Sun;

#include "../geometry/sphere.hpp"
#include "../engine/shader_object.hpp"
#include "../engine/texture_object.hpp"
#include "../solar_system.hpp"
#include "../engine/shader.hpp"

class Sun : public Sphere, public ShaderObject, public TextureObject {

	protected:
		Shader *shader;
		SolarSystem *solar_system;
		struct {
			GLuint model_matrix;
			GLuint texture;
			GLuint time;
		} shader_vars;
		boost::container::vector<GLfloat> noised;
		GLuint noise_buffer;
		GLuint texture;

	public:
		mat4 position;

		Sun(SolarSystem *);
		~Sun();
		void draw(GLuint);
};

#endif
