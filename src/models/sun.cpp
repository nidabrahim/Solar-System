#include "sun.hpp"
#include "../engine/shader.hpp"
#include "../engine/glmUtils.hpp"
#include "../solar_system_globals.hpp"

#include <SDL2/SDL.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/noise.hpp>

#define BUFFER_OFFSET(bytes) ((GLubyte*) NULL + (bytes))

/**
 * @brief Construct a new Sun:: Sun object
 * 
 * @param sys 
 */
Sun::Sun(SolarSystem *sys) : Sphere(3),solar_system(sys)
{
	shader = new Shader(SUN_SHADER_VERT_FILENAME, SUN_SHADER_FRAG_FILENAME);

	shader_vars.model_matrix = glGetUniformLocation(shader->program, "model_matrix");
	shader_vars.texture      = glGetUniformLocation(shader->program, "texture0");
	shader_vars.time      = glGetUniformLocation(shader->program,    "time");

	initialiseVariables(shader->program);

	texture = create1DTexture(SUN_TEXTURES_FILENAME);
}

/**
 * @brief Draw a new Sun
 * 
 * @param time 
 */
void Sun::draw(GLuint time) {
	glUseProgram(shader->program);

	assignVariables();

	position = glm::translate(mat4(1), vec3(0, 0, 0));

	mat4 transformation = position;

	glUniformMatrix4fv(shader_vars.model_matrix, 1, GL_FALSE, &transformation[0][0]);
	glUniform1ui(shader_vars.time, time);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_1D, texture);
	glUniform1i(shader_vars.texture, 0);

	Sphere::draw();
}

/**
 * @brief Destroy the Sun:: Sun object
 * 
 */
Sun::~Sun() {
	delete shader;
}
