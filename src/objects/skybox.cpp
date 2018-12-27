#include "skybox.hpp"

#include "../engine/shader.hpp"


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

SkyBox::SkyBox() {
	
	shader = new Shader("shaders/skybox.vert", "shaders/skybox.frag"); 
	shader_vars.model_matrix = glGetUniformLocation(shader->program, "model_matrix");
	shader_vars.texture0     = glGetUniformLocation(shader->program, "texture0");

	initialiseVariables(shader->program);

	texture = createCubeTexture(
		"textures/stars/stars_xPos.png",
		"textures/stars/stars_xNeg.png",
		"textures/stars/stars_yPos.png",
		"textures/stars/stars_yNeg.png",
		"textures/stars/stars_zPos.png",
		"textures/stars/stars_zNeg.png"

	);
}

void SkyBox::draw(GLuint time) {

	glUseProgram(shader->program);

	assignVariables();

	mat4 scale = glm::scale(mat4(1), vec3(200, 200, 200));

	glUniformMatrix4fv(shader_vars.model_matrix, 1, GL_FALSE, &scale[0][0]);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
	glUniform1i(shader_vars.texture0, 0);

	Cube::draw();
}

SkyBox::~SkyBox() {
	delete shader;
}
