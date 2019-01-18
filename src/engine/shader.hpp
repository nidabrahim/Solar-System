#ifndef __SHADER_HPP

#define __SHADER_HPP

#include <string>
#include <GL/gl.h>
#include <stdexcept>

using std::string;
using std::logic_error;

/**
 * @brief Shader class
 * 
 */
class Shader {

	protected:
		string loadShaderFile(string file);
		void compileShader(GLuint shaderID, string shader_code);
		GLboolean checkShader(GLuint, string shader_file);
		GLboolean checkProgram(GLuint);

	public:
		GLuint program;
		Shader(string vert_shader_file, string frag_shader_file);
};


#endif
