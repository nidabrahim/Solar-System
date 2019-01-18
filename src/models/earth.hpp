#ifndef EARTH_HPP
#define EARTH_HPP

#include <glm/glm.hpp>

using namespace glm;

class Earth;

#include "geometry/sphere.hpp"
#include "engine/shader_object.hpp"
#include "engine/texture_object.hpp"
#include "solar_system.hpp"
#include "engine/shader.hpp"

/**
 * @brief La classe Terre
 * 
 */

class Earth : public Sphere, public ShaderObject, public TextureObject {

	protected:
		//! Le shader
		Shader *shader;
		SolarSystem *solar_system;
		//! Les variables de shaders
		struct {
			//! La matrice modele
			GLuint model_matrix;
			//! L'angle de rotation au tour de la terre
			GLuint earth_rotation;
			//! Texture pour la matinée
			GLuint texture_day;
			//! Texture pour la nuit
			GLuint texture_night;
		} shader_vars;
		GLuint texture_day;
		GLuint texture_night;
		//! La matrice de transformation
		mat4 transformation;
		//! Charger la texture
		void loadTexture();

	public:
		//! La matrice position
		mat4 position;
		//! Le constructeur de la classe Terre 
		Earth(SolarSystem*);

		/**
		 * @brief Dessiner la planète terre 
		 * 
		 * @param time
		 */
		void draw(GLuint time);

		void compute(GLuint time);
		~Earth();
};

#endif
