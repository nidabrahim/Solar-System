#version 130

uniform mat4 model_matrix;
uniform mat4 he_projection;
uniform mat4 he_view;

in vec4 in_vertex;

out vec4 world_vertex;
out vec4 world_ball_center;
out vec4 raw_vert;

void main() {
	world_vertex      = model_matrix * in_vertex;
	world_ball_center = model_matrix * vec4(0,0,0,1);

	raw_vert = in_vertex;

	gl_Position = world_vertex;
}
