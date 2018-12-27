#ifndef SKYBOX_16Z7K1KZ

#define SKYBOX_16Z7K1KZ

#include "../geometry/cube.hpp"
#include "../engine/shader_object.hpp"
#include "../engine/texture_object.hpp"
#include "../engine/shader.hpp"

class SkyBox : public Cube, public ShaderObject, public TextureObject {
	public:
		SkyBox();
		~SkyBox();
		void draw(GLuint);

	protected:
		Shader *shader;

		struct {
			GLuint model_matrix;
			GLuint texture0;
		} shader_vars;

		GLuint texture;
};


#endif /* end of include guard: SKYBOX_16Z7K1KZ */
