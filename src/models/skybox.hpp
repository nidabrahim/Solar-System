#ifndef SKYBOX_HPP
#define SKYBOX_HPP

#include "../geometry/cube.hpp"
#include "../engine/shader_object.hpp"
#include "../engine/texture_object.hpp"
#include "../engine/shader.hpp"

/**
 * @brief La classe de skybox
 * 
 */

class SkyBox : public Cube, public ShaderObject, public TextureObject {

	protected:
		//! Le shader
		Shader *shader;
		//! Les variables de shaders
		struct {
			//! La matrice modele
			GLuint model_matrix;
			// Texture
			GLuint texture0;
		} shader_vars;
		GLuint texture;

	public:
		SkyBox();
		~SkyBox();

		/**
		 * @brief Dessiner le skybox
		 * 
		 */
		void draw(GLuint);
};


#endif
