#version 130

uniform mat4 he_view;
uniform mat4 he_projection;

uniform mat4 model_matrix;

in vec4 in_vertex;

out vec4 raw_vertex;

void main() {

	gl_Position = he_projection * he_view * model_matrix * in_vertex;

	raw_vertex = in_vertex;
}
