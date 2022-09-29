/*
 *juhye.son
 *9.23.2019
 *juhye.son990902@gmail.com
 *Mesh.h
 *this is mesh header
 */
#pragma once

#include "glew.h"
#include <cstddef>
#include <vector>
#include "Component.h"
#include "Transform.h"
#include "Mathematics/Vector2.hpp"
#include "Mathematics/Vector3.hpp"
#include "Shader.h"

enum class MESHTYPE
{
	hexagon,
	wire_circle,
	box,
	rectangle,
	wire_rectangle,
	wire_box,
	line,
	triangle,
	ellipse
};
class Shader;

class [[nodiscard]] Mesh :public Component
{
public:
	Mesh();
	~Mesh() override;


	void Update(unsigned shaderHandler, GLuint id);
	void Delete();

	std::size_t                            GetPointCount() const noexcept;
	std::vector<Vector3<float>>   GetPoint() const noexcept;
	std::vector<Vector3<float>>   GetTextureCoordinate() const noexcept;
	GLenum                     GetPointListPattern() const noexcept;
	Vector2<float>                      GetTransform();
	Vector2<float>                      GetVertex(int i);

	void InitializeTextureMesh(float width = 1, float height = 1);
	void InitializeColorMesh();
	void ColorMeshUpdate(unsigned shaderHandler);
	void	SetPoint(std::vector<Vector3<float>> point);
	void setRotation(float mRota);
	void SetVertex(std::vector<Vector3<float>> shapeType);
	void SetOriginVertex(MESHTYPE meshType);
	void SetMeshType(MESHTYPE mMeshType2)
	{
		meshType = mMeshType2;
	}
	void SetPointListPattern(GLenum mPattern)
	{
		pointListType = mPattern;
	}
	void SetColor(Vector3<float> mColor) noexcept;
    void SetSize(Vector2<float> mSize) noexcept {
        shapeSize = { mSize.x, mSize.y };
    }
	void AddColor(Vector3<float> mColor) noexcept;
	void AddPoint(Vector3<float>  point) noexcept;
	void AddTextureCoordinate(Vector3<float>  texture_coordinate) noexcept;

	void setTransform(Vector2<float> mTrans);
	void AddTransform(Vector2<float> mTrans);
	void Clear() noexcept;

	GLuint* GetVertexArrayObjectPointer(void) noexcept;
	std::vector<Vector3<float>> createHexagon() noexcept;
	GLuint GetVertexArrayObject(void) noexcept;

	std::vector<Vector3<float>> create_wire_circle(float radius = 1, std::size_t point_count = 30) noexcept;
	std::vector<Vector3<float>> create_box(float dimension = 1) noexcept;
	std::vector<Vector3<float>> create_rectangle() noexcept;
	std::vector<Vector3<float>> create_wire_rectangle() noexcept;
    void SplitAnimation() noexcept;
	std::vector<Vector3<float>> create_line(Vector2<float>  start = { 0.0f, 0.0f }, Vector2<float>  end = { 1.0f, -1.0f }) noexcept;
	std::vector<Vector3<float>> create_triangle(Vector3<float> a = { -1.0f,-1.0f, 1.0f }, Vector3<float> b = { 1.0f,-1.0f, 1.0f, }, Vector3<float> c = { 0.f,1.0f, 1.0f, }) noexcept;
	std::vector<Vector3<float>> createEllipse() noexcept;
private:
	std::vector<Vector3<float>> originVertex;
	std::vector<Vector3<float>> vertex;

	std::vector<Vector3<float>>  points{};
	std::vector<Vector3<float>> colors{};
	std::vector<Vector3<float>>  textureCoordinates{};
	GLenum      pointListType = GL_TRIANGLE_FAN;
	GLuint mVertexArrayObject;
	GLuint mPositionVertexBufferObjectID, mColorVertexBufferObjectID;
	GLuint mTextureCoordinateBufferObjectID;
	MESHTYPE meshType;
	Transform transform;
    Vector2<float> shapeSize = { 1.f, 1.f };
};