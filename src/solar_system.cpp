#include <string>
#include <glm/glm.hpp>
#include <boost/bind.hpp>

#include "solar_system.hpp"

#include "engine/glmUtils.hpp" 
#include "engine/camera.hpp"
#include "engine/shader.hpp"
#include "engine/EventHandler.hpp"


using namespace glm;

SolarSystem::SolarSystem() {
	Camera::inst()->init(vec3(0, 20, 0),
						 vec3(0, 0, 0),
						 vec3(0, 0, -1));


	EventHandler::inst()->registerKeyOnce(SDL_SCANCODE_SPACE,
			boost::bind(&SolarSystem::toggleCam, this, _1) 
	);

	objects.earth = new Earth(this);
	objects.moon  = new Moon(this);
	objects.sun   = new Sun(this);
	objects.skybox = new SkyBox();
}

void SolarSystem::followMoon() {
	vec3 moon_position  = vec3(objects.moon->position * vec4(0, 0, 0, 1));
	vec3 cam_position = moon_position + vec3(1.5, 0, 0);

	Camera::inst()->init(cam_position, moon_position, normalize(vec3(0, 1, 0)));
}

void SolarSystem::followEarth() {
	vec3 earth_position = vec3(objects.earth->position * vec4(0, 0, 0, 1));
	vec3 cam_position = earth_position + vec3(2, 0, 0);

	Camera::inst()->init(cam_position, earth_position, normalize(vec3(0, 1, 0)));
}

void SolarSystem::followEarthFar() {
	vec3 earth_position = vec3(objects.earth->position * vec4(0, 0, 0, 1));
	vec3 cam_position = earth_position + vec3(3, 1, 0);


	Camera::inst()->init(cam_position, earth_position, normalize(vec3(0, 1, 0)));
}

void SolarSystem::checkoutSun() {
	Camera::inst()->init(vec3(0, 0, 5), vec3(0, 0, 0), vec3(0, 1, 0));
}

void SolarSystem::overview()  {
	Camera::inst()->init(vec3(0, 20, 20),
						 vec3(0, 0, 0),
						 vec3(0, 1, -1)); 
}

void SolarSystem::renderFunc(GLuint time, Engine engine) {

	objects.earth->compute(time);

	if (camera == 0) {
		overview();
	}
	else if (camera == 1) {
		followEarthFar();
	}
	else if (camera == 2) {
		followEarth();
	}
	else if (camera == 3) {
		followMoon();
	}
	else if (camera == 4) {
		checkoutSun();
	}

	objects.sun->draw(time);
	objects.earth->draw(time);
	objects.moon->draw(time);
	objects.skybox->draw(time);
}

void SolarSystem::toggleCam(SDL_Event &ev) {
	camera = (camera + 1) % 5;
}
