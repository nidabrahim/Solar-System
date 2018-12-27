#include "earth.hpp"
#include "engine/shader.hpp"

#include <iostream>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

Earth::Earth(SolarSystem *system) :
	Sphere(4),
	solar_system(system)
{
	shader = new Shader("shaders/earth.vert", "shaders/earth.frag");

	shader_vars.model_matrix   = glGetUniformLocation(shader->program, "model_matrix");
	shader_vars.texture_day    = glGetUniformLocation(shader->program, "texture_day");
	shader_vars.texture_night  = glGetUniformLocation(shader->program, "texture_night");
	shader_vars.earth_rotation = glGetUniformLocation(shader->program, "earth_rotation");

	initialiseVariables(shader->program);
	loadTexture();
}

void Earth::compute(GLuint time) {
	time *= 0.5;

	mat4 earth_rotation = glm::rotate(
		mat4(1),
		0.05f * time,
		vec3(0, 1, 0)
	);

	mat4 axis_tilt = glm::rotate(
		mat4(1),
		23.44f,
		vec3(0, 0, 1)
	);

	mat4 sun_rotation = glm::rotate(
		mat4(1),
		0.005f * time,
		vec3(0, 1, 0)
	);

	mat4 scale = glm::scale(mat4(1), vec3(0.5));
	// using the sun here is actually bullshit since the light isn't adjusted to that
	mat4 translate = glm::translate(mat4(1), vec3(-10, 0, 0)) * solar_system->objects.sun->position;
	position = sun_rotation * translate;
	transformation = position * earth_rotation * axis_tilt * scale;
}

void Earth::draw(GLuint time) {
	glUseProgram(shader->program);

	assignVariables();


	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture_day);
	glUniform1i(shader_vars.texture_day, 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture_night);
	glUniform1i(shader_vars.texture_night, 1);

	glUniformMatrix4fv(shader_vars.model_matrix, 1, GL_FALSE, &transformation[0][0]);

	Sphere::draw();
}

void Earth::loadTexture() {
	texture_day = createCubeTexture(
		"textures/world/world_xPos.png",
		"textures/world/world_xNeg.png",
		"textures/world/world_yPos.png",
		"textures/world/world_yNeg.png",
		"textures/world/world_zPos.png",
		"textures/world/world_zNeg.png"
	);

	texture_night = createCubeTexture(
		"textures/world_night/world_night_xPos.png",
		"textures/world_night/world_night_xNeg.png",
		"textures/world_night/world_night_yPos.png",
		"textures/world_night/world_night_yNeg.png",
		"textures/world_night/world_night_zPos.png",
		"textures/world_night/world_night_zNeg.png"

	);
}

Earth::~Earth() {
	delete shader;
}
