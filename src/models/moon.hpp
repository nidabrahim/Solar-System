#ifndef MOON_HPP
#define MOON_HPP

class Moon;

#include "../geometry/sphere.hpp"
#include "../engine/shader_object.hpp"
#include "../engine/texture_object.hpp"
#include "../solar_system.hpp"
#include "../engine/shader.hpp"

/**
 * @brief La classe de la lune
 * 
 */

class Moon : public Sphere, public ShaderObject, public TextureObject {

	protected:
		Shader *shader;
		//! Le texture de la lune
		GLuint texture;
		SolarSystem *solar_system;
		//! Les variables du shaders
		struct {
			GLuint model_matrix;
			GLuint texture0;
		} shader_vars;
		//! Charger le texture
		void loadTexture();

	public:
		//! La matrice position
		mat4 position;
		Moon(SolarSystem*);
		~Moon();

		/**
		 * @brief Dessiner la lune
		 * 
		 * @param time 
		 */
		void draw(GLuint time);
};


#endif
