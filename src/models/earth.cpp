#include "earth.hpp"
#include "engine/shader.hpp"
#include "../solar_system_globals.hpp"

#include <iostream>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

/**
 * @brief Construct a new Earth:: Earth object
 * 
 * @param system 
 */
Earth::Earth(SolarSystem *system) :Sphere(4),solar_system(system)
{
	shader = new Shader(EARTH_SHADER_VERT_FILENAME, EARTH_SHADER_FRAG_FILENAME);

	shader_vars.model_matrix   = glGetUniformLocation(shader->program, "model_matrix");
	shader_vars.texture_day    = glGetUniformLocation(shader->program, "texture_day");
	shader_vars.texture_night  = glGetUniformLocation(shader->program, "texture_night");
	shader_vars.earth_rotation = glGetUniformLocation(shader->program, "earth_rotation");

	initialiseVariables(shader->program);
	
	//! Construct a new load Texture object
	loadTexture();
}

/**
 * @brief 
 * 
 * @param time 
 */
void Earth::compute(GLuint time) {
	time *= 0.5;

	mat4 earth_rotation = glm::rotate(
		mat4(1),
		0.005f * time,
		vec3(0, 1, 0)
	);

	mat4 axis_tilt = glm::rotate(
		mat4(1),
		23.44f,
		vec3(0, 1, 0)
	);

	mat4 sun_rotation = glm::rotate(
		mat4(1),
		0.0005f * time,
		vec3(0, 1, 0)
	);

	mat4 scale = glm::scale(mat4(1), vec3(0.5));
	mat4 translate = glm::translate(mat4(1), vec3(-10, 0, 0)) * solar_system->objects.sun->position;
	position = sun_rotation * translate;
	transformation = position * earth_rotation * axis_tilt * scale;
}

/**
 * @brief Draw a new Earth
 * 
 * @param time 
 */
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

	//! Construct a new Sphere::draw object
	Sphere::draw();
}

/**
 * @brief Load texture
 * 
 */
void Earth::loadTexture() {
	//! Load day textures
	texture_day = createCubeTexture(
		EARTH_TEXTURES_MORNING_XP_FILENAME,
		EARTH_TEXTURES_MORNING_XN_FILENAME,
		EARTH_TEXTURES_MORNING_YP_FILENAME,
		EARTH_TEXTURES_MORNING_YN_FILENAME,
		EARTH_TEXTURES_MORNING_ZP_FILENAME,
		EARTH_TEXTURES_MORNING_ZN_FILENAME
	);

	//! Load night textures
	texture_night = createCubeTexture(
		EARTH_TEXTURES_NIGHT_XP_FILENAME,
		EARTH_TEXTURES_NIGHT_XN_FILENAME,
		EARTH_TEXTURES_NIGHT_YP_FILENAME,
		EARTH_TEXTURES_NIGHT_YN_FILENAME,
		EARTH_TEXTURES_NIGHT_ZP_FILENAME,
		EARTH_TEXTURES_NIGHT_ZN_FILENAME
	);
}

/**
 * @brief Destroy the Earth:: Earth object
 * 
 */
Earth::~Earth() {
	delete shader;
}
