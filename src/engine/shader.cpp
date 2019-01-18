#include <iostream>
#include <string>
#include <fstream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <stdexcept>
#include <boost/container/vector.hpp>
#include <boost/lexical_cast.hpp>

#include "shader.hpp"

using std::ifstream;
using std::ios;
using boost::container::vector;
using boost::lexical_cast;

/**
 * @brief Construct a new Shader:: Shader object
 * 
 * @param vert_shader_file 
 * @param frag_shader_file 
 */
Shader::Shader(string vert_shader_file, string frag_shader_file) {
    //! Create the shaders
	GLuint vert_shader = glCreateShader(GL_VERTEX_SHADER);
	GLuint frag_shader = glCreateShader(GL_FRAGMENT_SHADER);

    //! Read the Shader code from the file
	string vert_code = loadShaderFile(vert_shader_file);
	string fragCode = loadShaderFile(frag_shader_file);

    //! Compile Vertex Shader
    std::cout << "\nCompiling Vertex shader : " << vert_shader_file << std::endl; 
	compileShader(vert_shader, vert_code);
	if (!checkShader(vert_shader, vert_shader_file)) {
		throw std::runtime_error("Could not compile vertex shader!");
	}

	//! Compile Fragment Shader
	std::cout << "\nCompiling fragment shader : " << frag_shader_file << std::endl;
	compileShader(frag_shader, fragCode);
	if (!checkShader(frag_shader, frag_shader_file)) {
		throw std::runtime_error("Could not compile fragment shader");
	}

	//! Create the program
	std::cout << "Creating the program " << std::endl; 
	program = glCreateProgram();
	glAttachShader(program, vert_shader);
	glAttachShader(program, frag_shader);

    //! Setup Vertex Attributes
    glBindAttribLocation (program, 0, "in_vertex");

    //! Link the program
    std::cout << "Linking the program " << std::endl; 
	glLinkProgram(program);

	if (!checkProgram(program)) {
		throw std::runtime_error("Could, not create program");
	}
}

/**
 * @brief Shader compiler
 * 
 * @param shaderID 
 * @param shaderCode 
 */
void Shader::compileShader(GLuint shaderID, string shaderCode)  {
	char const *sourcePointer = shaderCode.c_str();
	glShaderSource(shaderID, 1, &sourcePointer, NULL);
	glCompileShader(shaderID);
}

/**
 * @brief Shader checker
 * 
 * @param shaderID 
 * @param shader_file 
 * @return GLboolean 
 */
GLboolean Shader::checkShader(GLuint shaderID, string shader_file) {
	GLint result = GL_FALSE;
	GLint logLength = 0;

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);

	if (logLength > 0) {
		std::cout << "--- " << shader_file  << ": " << std::endl; 
        vector<char> errorMsg(logLength);
		glGetShaderInfoLog(shaderID, logLength, NULL, &errorMsg[0]);
		std::cout << &errorMsg[0] << std::endl;
	}
	return result;
}

/**
 * @brief Check the shader program
 * 
 * @param program 
 * @return GLboolean 
 */
GLboolean Shader::checkProgram(GLuint program) {
	GLint result = GL_FALSE;
	GLint logLength = 1000;

	glGetProgramiv(program, GL_LINK_STATUS, &result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);

	vector<char> errorMsg(logLength + 1);
	glGetProgramInfoLog(program, logLength, NULL, &errorMsg[0]);
	std::cout << &errorMsg[0] << std::endl;
	return result;
}

/**
 * @brief Load a shader file
 * 
 * @param file 
 * @return string 
 */
string Shader::loadShaderFile(string file) {
	string shaderCode;

	ifstream codeStream(file, ios::in);
	if (codeStream.is_open()) {
		string line = "";
		while (getline(codeStream, line)) {
			shaderCode += "\n" + line;
		}
		codeStream.close();
	}
	else {
		throw std::invalid_argument("Shader file " + file);
	}

	return shaderCode;
}
