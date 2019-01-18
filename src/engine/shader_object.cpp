
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glx.h>

#include "shader_object.hpp"
#include "../engine/camera.hpp"

/**
 * @brief Initialize shader variables
 * 
 * @param programID 
 */
void ShaderObject::initialiseVariables(GLuint programID) {
	global_shader_vars.projection = glGetUniformLocation(programID, "he_projection");
	global_shader_vars.view       = glGetUniformLocation(programID, "he_view");
	global_shader_vars.cam_pos    = glGetUniformLocation(programID, "he_cam_pos");
}

/**
 * @brief Assign variables
 * 
 */
void ShaderObject::assignVariables() {
	mat4 projection = Camera::inst()->projection();
	mat4 view       = Camera::inst()->view();
	vec3 cam_pos    = Camera::inst()->pos();

	glUniformMatrix4fv(global_shader_vars.projection , 1 , GL_FALSE , &projection[0][0]);
	glUniformMatrix4fv(global_shader_vars.view       , 1 , GL_FALSE , &view[0][0]);

	glUniform3f(global_shader_vars.cam_pos, cam_pos.x, cam_pos.y, cam_pos.z);
}

ShaderObject::~ShaderObject() {}
