
#include <cassert>
#include <iostream>
#include "glew.h"
#include "Shader.h"

const GLchar* vertex_shader_source =
"#version 330 core\n"
"in vec2 positionAttribute;"
"in vec2 textureCoordinateAttribute;"
"out vec2 passTextureCoordinateAttribute;"
"uniform mat3 ndc;"
"void main()"
"{"
//"gl_Position = vec4(positionAttribute.xy, 0.0, 1.0);"
"vec3 p = ndc * vec3(positionAttribute.xy, 1.0);"
"gl_Position = vec4(p.xy, 0.0, 1.0);"
"passTextureCoordinateAttribute = textureCoordinateAttribute;"
"}";

const GLchar* vertex_shader_color_source =
"#version 330 core\n"
"in vec2 positionAttribute;"
"in vec3 colorAttribute;"
"out vec3 passColorAttribute;"
"void main()"
"{"
"gl_Position = vec4(positionAttribute.xy, 0.0, 1.0);"
"passColorAttribute = colorAttribute;"
"}";

const GLchar* fragment_shader_source =
"#version 330 core\n"
"in vec2 passTextureCoordinateAttribute;"
"out vec4 fragmentColor;"
"uniform sampler2D tex;"
"void main()"
"{"
"fragmentColor = texture(tex, passTextureCoordinateAttribute);"
"}";

const GLchar* fragment_shader_color_source =
"#version 330 core\n"
"in vec3 passColorAttribute;"
"out vec4 fragmentColor;"
"uniform sampler2D tex;"
"void main()"
"{"
"fragmentColor = vec4(passColorAttribute.xyz, 1.0);"
"}";

Shader::Shader()
{
	mShaderProgramID = 0;
	mVertexShaderProgramID = 0;
	mFragmentShaderProgramID = 0;
}

void Shader::BuildTextureShader()
{
	mShaderProgramID = glCreateProgram();

	VertexShaderCompile();
	FragmentShaderCompile();
	LinkShader();
}

void Shader::BuildColorShader()
{
	mShaderProgramID = glCreateProgram();

	VertexShaderColorCompile();
	FragmentShaderColorCompile();
	LinkShader();
}

void Shader::VertexShaderCompile()
{
	mVertexShaderProgramID = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(mVertexShaderProgramID, 1, &vertex_shader_source, NULL);
	glCompileShader(mVertexShaderProgramID);

	GLint vertex_compiled;
	glGetShaderiv(mVertexShaderProgramID, GL_COMPILE_STATUS, &vertex_compiled);
	if (vertex_compiled != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetShaderInfoLog(mVertexShaderProgramID, 1024, &log_length, message);
		glDeleteShader(mVertexShaderProgramID);

		printf("%s\n", &(message[0]));
		printf("Vertex Shader_Error: fail to compile!\n");

	}
}

void Shader::VertexShaderColorCompile()
{
	mVertexShaderProgramID = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(mVertexShaderProgramID, 1, &vertex_shader_color_source, NULL);
	glCompileShader(mVertexShaderProgramID);

	GLint vertex_compiled;
	glGetShaderiv(mVertexShaderProgramID, GL_COMPILE_STATUS, &vertex_compiled);
	if (vertex_compiled != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetShaderInfoLog(mVertexShaderProgramID, 1024, &log_length, message);
		glDeleteShader(mVertexShaderProgramID);

		printf("%s\n", &(message[0]));
		printf("Vertex Shader_Error: fail to compile!\n");

	}
}

void Shader::FragmentShaderCompile()
{
	mFragmentShaderProgramID = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(mFragmentShaderProgramID, 1, &fragment_shader_source, NULL);// fragment_shader_source is a GLchar* containing glsl shader source code
	glCompileShader(mFragmentShaderProgramID);

	GLint fragment_compiled;
	glGetShaderiv(mFragmentShaderProgramID, GL_COMPILE_STATUS, &fragment_compiled);
	if (fragment_compiled != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetShaderInfoLog(mFragmentShaderProgramID, 1024, &log_length, message);
		glDeleteShader(mFragmentShaderProgramID);

		printf("%s\n", &(message[0]));
		printf("Fragment Shader_Error: fail to compile!\n");
	}
}

void Shader::FragmentShaderColorCompile()
{
	mFragmentShaderProgramID = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(mFragmentShaderProgramID, 1, &fragment_shader_color_source, NULL);// fragment_shader_source is a GLchar* containing glsl shader source code
	glCompileShader(mFragmentShaderProgramID);

	GLint fragment_compiled;
	glGetShaderiv(mFragmentShaderProgramID, GL_COMPILE_STATUS, &fragment_compiled);
	if (fragment_compiled != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetShaderInfoLog(mFragmentShaderProgramID, 1024, &log_length, message);
		glDeleteShader(mFragmentShaderProgramID);

		printf("%s\n", &(message[0]));
		printf("Fragment Shader_Error: fail to compile!\n");
	}
}

void Shader::LinkShader()
{
	glAttachShader(mShaderProgramID, mVertexShaderProgramID);
	glAttachShader(mShaderProgramID, mFragmentShaderProgramID);

	glLinkProgram(mShaderProgramID);
	glUseProgram(mShaderProgramID);

	handleToShader = mShaderProgramID;

	glDeleteShader(mVertexShaderProgramID);
	glDeleteShader(mFragmentShaderProgramID);

}
void Shader::Delete() noexcept
{
	glDeleteProgram(handleToShader);
}
GLuint Shader::GetShaderID(void) noexcept
{
	GLuint mShader = mShaderProgramID;
	return mShader;
}
