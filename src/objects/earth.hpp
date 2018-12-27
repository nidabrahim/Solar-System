#ifndef EARTH_KVWZSO54

#define EARTH_KVWZSO54

#include <glm/glm.hpp>

using namespace glm;

class Earth;

#include "geometry/sphere.hpp"
#include "engine/shader_object.hpp"
#include "engine/texture_object.hpp"
#include "solar_system.hpp"
#include "engine/shader.hpp"

class Earth : public Sphere, public ShaderObject, public TextureObject {
	public:
		Earth(SolarSystem*);

		void draw(GLuint time);
		void compute(GLuint time);

		mat4 position;

		~Earth();

	protected:
		Shader *shader;

		SolarSystem *solar_system;

		struct {
			GLuint model_matrix;
			GLuint earth_rotation;
			GLuint texture_day;
			GLuint texture_night;
		} shader_vars;

		void loadTexture();

		GLuint texture_day;
		GLuint texture_night;

		mat4 transformation;
};

#endif /* end of include guard: EARTH_KVWZSO54 */
