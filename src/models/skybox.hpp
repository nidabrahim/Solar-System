#ifndef SKYBOX_HPP
#define SKYBOX_HPP

#include "../geometry/cube.hpp"
#include "../engine/shader_object.hpp"
#include "../engine/texture_object.hpp"
#include "../engine/shader.hpp"

class SkyBox : public Cube, public ShaderObject, public TextureObject {

	protected:
		Shader *shader;
		struct {
			GLuint model_matrix;
			GLuint texture0;
		} shader_vars;
		GLuint texture;

	public:
		SkyBox();
		~SkyBox();
		void draw(GLuint);
};


#endif
