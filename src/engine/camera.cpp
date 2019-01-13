#include "camera.hpp"

#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

#include "glmUtils.hpp"

using namespace std;

Camera *Camera::instance = NULL;

Camera *Camera::inst() {
	if (!instance) {
		instance = new Camera;
	}

	return instance;
}

void Camera::setRes(GLuint w, GLuint h) {
	width = w;
	height = h;

	glViewport(0, 0, width, height);
}

void Camera::init(vec3 pos, vec3 dir, vec3 up) {
	position = pos;
	direction = dir;
	this->up = up;
}


Camera::Camera() :
	position(vec3(0, 0, 1)) {

	//SDL_SetRelativeMouseMode(SDL_TRUE);
}

mat4 Camera::projection() {
	float ratio = (float)height / (float)width;
	return perspective(45.0f,1/ratio,0.1f,500.0f);
}

mat4 Camera::view() {
	return lookAt(position,direction,up);
}

vec3 Camera::pos() {
	return position;
}

void Camera::mouseMotion(SDL_Event &event) {
	Sint32 xRel = event.motion.xrel;
	Sint32 yRel = event.motion.yrel;

	float xAngle = yRel * 0.002;
	float yAngle = -xRel * 0.002;

	mat4 rotX = mat4(
			1, 0, 0, 0,
			0, cos(xAngle), -sin(xAngle),  0,
			0, sin(xAngle), cos(xAngle),  0,
			0, 0, 0, 1
	);

	mat4 rotY = mat4(
		cos(yAngle), sin(yAngle), 0, 0,
		0, 1, 0, 0,
		sin(yAngle), 0, cos(yAngle), 0,
		0, 0, 0, 1
	);
	
	vec4 new_dir = rotX * rotY * vec4(direction - position, 1.0);

	direction = position + vec3(new_dir);
}


void Camera::stride(SDL_Event &event) {
	if (event.key.keysym.scancode == SDL_SCANCODE_D) {
		position.x += 0.1;
	}
	else {
		position.x -= 0.1;
	}
}

