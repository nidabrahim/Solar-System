#ifndef SOLARSYSTEM_HPP__
#define SOLARSYSTEM_HPP__

#define GL_GLEXT_PROTOTYPES
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glx.h>

class SolarSystem;

#include "engine/Engine.hpp"
#include "models/earth.hpp"
#include "models/sun.hpp"
#include "models/moon.hpp"
#include "models/skybox.hpp"

/**
 * @brief SolarSystem Class
 * 
 */
class SolarSystem {
	public:
		SolarSystem();
		void renderFunc(GLuint time, Engine engine);

		void toggleCam(SDL_Event&);

		//! Models
		struct {
			Earth *earth;
			Sun *sun;
			Moon *moon;
			SkyBox *skybox;
		} objects;
	
	private:

		GLuint shader;
		GLuint camera = 0;

		void followMoon();
		void followEarth();
		void followEarthFar();
		void checkoutSun();
		void overview();
};


#endif
