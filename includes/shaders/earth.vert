#version 130

uniform mat4 he_projection;
uniform mat4 he_view;
uniform mat4 model_matrix;

uniform mat4 earth_rotation;

in vec4 in_vertex;

out vec4 world_vertex;
out vec4 world_ball_center;
out vec4 raw_vertex;

void main() {
	world_vertex      = model_matrix * in_vertex;
	world_ball_center = model_matrix * vec4(0, 0, 0, 1);

	gl_Position = he_projection * he_view * world_vertex;
	raw_vertex = in_vertex;
}
