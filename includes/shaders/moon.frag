#version 130

in vec4 world_vertex;
in vec4 world_ball_center;
in vec4 raw_vertex;

uniform mat4 he_projection;
uniform mat4 he_view;
uniform vec3 he_cam_pos;

uniform samplerCube texture0;

out vec4 out_color;

void main() {

	vec4 tex_color = texture(texture0, raw_vertex.xyz);
	vec4 surf_color = tex_color;

	vec4 surface_frag_pos = world_vertex - world_ball_center;
	vec4 normal = normalize(surface_frag_pos);

	vec4 light_direction =  world_vertex;

	// diffuse
	float intensity = clamp(dot(normal, -light_direction), 0, 100);
	vec4 diffuse = intensity * 0.1 * surf_color;

	// ambient
	vec4 ambient = 0.02 * surf_color;

	// specular
	vec4 reflected = normalize(reflect(light_direction, normal));
	vec4 view_direction = normalize(vec4(he_cam_pos, 1) - world_vertex);
	float spec_intensity = 0.2 * pow(max(0.0, dot(view_direction, reflected)), 5);

	vec4 specular = spec_intensity * vec4(0.5, 0.5, 0.5, 1);

	out_color = vec4((diffuse + ambient + specular).xyz, 1.0);
}
