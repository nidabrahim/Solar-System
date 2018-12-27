#version 130

in vec4 raw_vertex;

out vec4 out_color;

uniform samplerCube texture0;

void main() {

	out_color = vec4(texture(texture0, raw_vertex.xyz).xyz, 0.2);
}
