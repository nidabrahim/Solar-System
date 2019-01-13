#ifndef SOLARSYSTEM_HPP__
#define SOLARSYSTEM_HPP__

#define GL_GLEXT_PROTOTYPES
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glx.h>

class SolarSystem;

#include "engine/Engine.hpp"
#include "objects/earth.hpp"
#include "objects/sun.hpp"
#include "objects/moon.hpp"
#include "objects/skybox.hpp"


class SolarSystem {
	public:
		SolarSystem();
		void renderFunc(GLuint time, Engine engine);

		void toggleCam(SDL_Event&);

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
