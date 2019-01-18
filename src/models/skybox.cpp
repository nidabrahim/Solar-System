#include "skybox.hpp"

#include "../engine/shader.hpp"
#include "../solar_system_globals.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

/**
 * @brief Construct a new Sky Box:: Sky Box object
 * 
 */
SkyBox::SkyBox() {
	
	shader = new Shader(SKYBOX_SHADER_VERT_FILENAME, SKYBOX_SHADER_FRAG_FILENAME); 
	shader_vars.model_matrix = glGetUniformLocation(shader->program, "model_matrix");
	shader_vars.texture0     = glGetUniformLocation(shader->program, "texture0");

	initialiseVariables(shader->program);

	//! Load textures
	texture = createCubeTexture(
		SKYBOX_TEXTURES_XP_FILENAME,
		SKYBOX_TEXTURES_XN_FILENAME,
		SKYBOX_TEXTURES_YP_FILENAME,
		SKYBOX_TEXTURES_YN_FILENAME,
		SKYBOX_TEXTURES_ZP_FILENAME,
		SKYBOX_TEXTURES_ZN_FILENAME
	);
}

/**
 * @brief Draw a new Skybox
 * 
 * @param time 
 */
void SkyBox::draw(GLuint time) {

	glUseProgram(shader->program);

	assignVariables();

	mat4 scale = glm::scale(mat4(1), vec3(200, 200, 200));

	glUniformMatrix4fv(shader_vars.model_matrix, 1, GL_FALSE, &scale[0][0]);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
	glUniform1i(shader_vars.texture0, 0);

	//! Construct a new Cube::draw object
	Cube::draw();
}

/**
 * @brief Destroy the Sky Box:: Sky Box object
 * 
 */
SkyBox::~SkyBox() {
	delete shader;
}
