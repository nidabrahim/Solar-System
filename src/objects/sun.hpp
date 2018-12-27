#ifndef SUN_R9D4WPHR

#define SUN_R9D4WPHR

class Sun;

#include "../geometry/sphere.hpp"
#include "../engine/shader_object.hpp"
#include "../engine/texture_object.hpp"
#include "../solar_system.hpp"
#include "../engine/shader.hpp"

class Sun : public Sphere, public ShaderObject, public TextureObject {
	public:
		Sun(SolarSystem *);
		~Sun();
		void draw(GLuint);

		mat4 position;

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
};

#endif /* end of include guard: SUN_R9D4WPHR */
