#ifndef SUN_HPP
#define SUN_HPP

class Sun;

#include "../geometry/sphere.hpp"
#include "../engine/shader_object.hpp"
#include "../engine/texture_object.hpp"
#include "../solar_system.hpp"
#include "../engine/shader.hpp"

/**
 * @brief La classe du soleil
 * 
 */

class Sun : public Sphere, public ShaderObject, public TextureObject {

	protected:
		//! Le shader
		Shader *shader;
		SolarSystem *solar_system;
		//! Les variables de shaders
		struct {
			//! La matrice modele
			GLuint model_matrix;
			//! Texture
			GLuint texture;
			GLuint time;
		} shader_vars;
		//! Le vecteur bruit
		boost::container::vector<GLfloat> noised;
		//! Le buffer de bruit
		GLuint noise_buffer;
		GLuint texture;

	public:
		//! La matrice position
		mat4 position;

		Sun(SolarSystem *);
		~Sun();

		/**
		 * @brief Dessiner le soleil
		 * 
		 */
		void draw(GLuint);
};

#endif
