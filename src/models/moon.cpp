#include "moon.hpp"
#include "../engine/shader.hpp"
#include "../solar_system_globals.hpp"

#include <glm/gtc/matrix_transform.hpp>


Moon::Moon(SolarSystem *sys) : Sphere(3),solar_system(sys)
{
	shader = new Shader(MOON_SHADER_VERT_FILENAME, MOON_SHADER_FRAG_FILENAME);

	shader_vars.model_matrix = glGetUniformLocation(shader->program, "model_matrix");
	shader_vars.texture0     = glGetUniformLocation(shader->program, "texture0");

	initialiseVariables(shader->program);
	loadTexture();
}

void Moon::draw(GLuint time) {
	glUseProgram(shader->program);

	assignVariables();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
	glUniform1i(shader_vars.texture0, 0);

	mat4 scale = glm::scale(mat4(1), vec3(0.2));
	mat4 translate_moon = glm::translate(mat4(1), vec3(-2, 0, 0));
	mat4 translate_earth = solar_system->objects.earth->position;
	mat4 rotate_earth = glm::rotate(mat4(1), 0.001f * time, vec3(0, 1, 0));

	position = translate_earth * rotate_earth * translate_moon;
	mat4 transformation = position * scale;

	glUniformMatrix4fv(shader_vars.model_matrix, 1, GL_FALSE, &transformation[0][0]);

	Sphere::draw();
}

void Moon::loadTexture() {
	texture = createCubeTexture(
		MOON_TEXTURES_XP_FILENAME,
		MOON_TEXTURES_XN_FILENAME,
		MOON_TEXTURES_YP_FILENAME,
		MOON_TEXTURES_YN_FILENAME,
		MOON_TEXTURES_ZP_FILENAME,
		MOON_TEXTURES_ZN_FILENAME
	);
}

Moon::~Moon() {
	delete shader;
}
