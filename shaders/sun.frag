#version 130

in vec4 world_vertex;
in vec4 world_ball_center;
in vec4 raw_vert;

uniform mat4 he_projection;
uniform mat4 he_view;
uniform vec3 he_cam_pos;

uniform sampler1D texture0;

out vec4 out_color;

void main() {

	vec3 texCoords = raw_vert.xyz;
	vec2 longitudeLatitude = vec2((atan(texCoords.y, texCoords.x) / 3.1415926 + 1.0),
                                  (asin(texCoords.z) / 3.1415926 + 1.5));

	vec4 surf_color = vec4(0.976457, 0.68235, 0.050980, 1);

	vec4 surface_frag_pos = world_vertex - world_ball_center;
	vec4 normal = normalize(surface_frag_pos);

	vec4 light_direction = normalize(vec4(he_cam_pos, 1) - world_ball_center);
	float intensity = dot(normal, light_direction);
	vec4 diffuse = texture(texture0, intensity);// intensity * surf_color;

	// specular
	vec4 view_direction = normalize(vec4(he_cam_pos, 1));
	float spec_intensity = pow(max(0.0, dot(view_direction, normal)), 100);

	//vec4 specular = spec_intensity * vec4(1, 1.0, 1.0, 10);

	out_color = vec4((diffuse).xyz, 1.0);
}
