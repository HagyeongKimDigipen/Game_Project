#pragma once
/*
 *juhye.son
 *10.1.2019
 *juhye.son990902@gmail.com
 *Shader.h
 *this is a shader header
 */
#include <map>
#include <string>
#include "external/glew/include/GL/glew.h"	


class Color4f;

class Mesh;

class [[nodiscard]] Shader
{
public:
	Shader();

	~Shader() noexcept = default;

	void BuildTextureShader();
	void BuildColorShader();
	

	void VertexShaderCompile();
	void VertexShaderColorCompile();


	void FragmentShaderCompile();
	void FragmentShaderColorCompile();


	void LinkShader();

	GLuint GetShaderID(void) noexcept;

	constexpr unsigned GetShaderHandler() const noexcept { return handleToShader; }

	void Delete() noexcept;

	Shader(const Shader & other) = delete;
	Shader(Shader && other) noexcept = delete;
	Shader& operator=(const Shader & other) = delete;
	Shader& operator=(Shader && other) noexcept = delete;

private:
	GLuint mShaderProgramID = 0;
	GLuint mVertexShaderProgramID = 0;
	GLuint mFragmentShaderProgramID = 0;

	unsigned int                   handleToShader = 0;
	std::map<std::string, int> uniformNameToLocation{};

};


