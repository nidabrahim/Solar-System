#ifndef MOON_T2DFQ1YK

#define MOON_T2DFQ1YK

class Moon;

#include "../geometry/sphere.hpp"
#include "../engine/shader_object.hpp"
#include "../engine/texture_object.hpp"
#include "../solar_system.hpp"
#include "../engine/shader.hpp"

class Moon : public Sphere, public ShaderObject, public TextureObject {
	public:
		Moon(SolarSystem*);
		~Moon();

		void draw(GLuint time);

		mat4 position;

	protected:
		Shader *shader;

		void loadTexture();

		GLuint texture;

		SolarSystem *solar_system;

		struct {
			GLuint model_matrix;
			GLuint texture0;
		} shader_vars;
};


#endif /* end of include guard: MOON_T2DFQ1YK */
