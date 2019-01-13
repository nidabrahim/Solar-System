#version 130 

#define PI 3.1415926

in vec4 world_vertex;
in vec4 world_ball_center;
in vec4 raw_vertex;

uniform mat4 he_projection;
uniform mat4 he_view;
uniform vec3 he_cam_pos;

out vec4 out_color;

uniform samplerCube texture_day;
uniform samplerCube texture_night;

vec3 getTangent(vec3 normal) {
	vec3 tangent;
	vec3 c1 = cross(normal, vec3(0, 0, 1));
	vec3 c2 = cross(normal, vec3(0, 1, 0));

	if (length(c1) > length(c2)) {
		tangent = c1;
	}
	else {
		tangent = c2;
	}

	return tangent;
}

void main() {
	vec4 surf_color;

	vec4 surface_frag_pos = world_vertex - world_ball_center;
	vec4 normal           = normalize(surface_frag_pos);
	vec4 view_direction   = normalize(vec4(he_cam_pos, 1) - world_vertex);
	vec4 light_direction  = normalize(world_vertex);

	// cos of angle between light and normal
	float cos_angle = -dot(normal, light_direction);

	float angle = acos(cos_angle);

	vec4 tex_day = texture(texture_day, raw_vertex.xyz);
	vec4 tex_night = texture(texture_night, raw_vertex.xyz);

	vec4 diffuse;
	vec4 specular;

	if (angle < PI / 2) {
		// day
		surf_color = tex_day;
		diffuse = cos_angle * surf_color;
	}
	else {
		// night
		surf_color = mix(tex_day, tex_night + tex_night, abs(cos_angle));

		
		float intensity = clamp(cos_angle, 0, 1);
		diffuse = intensity * surf_color;
		
	}

	vec4 reflected = normalize(reflect(light_direction, normal));
	float spec_intensity = pow(max(0.0, dot(view_direction, reflected)), 5);
	specular = spec_intensity * surf_color;

	vec4 ambient = 0.15 * surf_color;;

	out_color = vec4((diffuse + ambient + specular).xyz, 1.0);
}
