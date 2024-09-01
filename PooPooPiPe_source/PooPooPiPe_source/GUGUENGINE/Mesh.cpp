

#include <cmath>
#include <valarray>
#include "Mesh.h"
#include "Transform.h"
#include <iostream>
#include "Shader.h"
#include "Mathematics/MathLibrary.hpp"
#include <math.h>
#include "Application.h"

  //Returns the total amount of points representing the mesh
Transform* m;
int splitCheck = 0;
Mesh::Mesh() : Component(ComponentType::COMPONENTTYPE_MESH), mVertexArrayObject(0), mPositionVertexBufferObjectID(0), mColorVertexBufferObjectID(0), mTextureCoordinateBufferObjectID(0), meshType(MESHTYPE::hexagon)
{
	points.clear();
	colors.clear();
	textureCoordinates.clear();
	transform.Initialize();
}

Mesh::~Mesh()
{
	Delete();
}
void Mesh::setTransform(Vector2<float> mTrans)
{
	transform.SetTranslation({ mTrans.x, mTrans.y });
}
void Mesh::AddTransform(Vector2<float> mTrans)
{
	transform.AddTranslation({ mTrans.x, mTrans.y });
}
void Mesh::setRotation(float mRota)
{
	transform.SetRotation(mRota);
}
Vector2<float> Mesh::GetTransform()
{
	return { transform.GetTranslation().x, transform.GetTranslation().y };
}
Vector2<float> Mesh::GetVertex(int i)
{
	return { vertex.at(i).x, vertex.at(i).y };
}
void Mesh::InitializeTextureMesh(float width, float height)
{
    shapeSize = { width, height };
    SetOriginVertex(meshType);
	AddColor({ 1.0f, 1.0f, 0.f });
	SetVertex(originVertex);
	if (meshType == MESHTYPE::hexagon)
	{
		SetVertex(originVertex);
	}
	glGenVertexArrays(1, &mVertexArrayObject);
	glBindVertexArray(mVertexArrayObject);

	//Vertex Buffer Object(VBO)?
	glGenBuffers(1, &mPositionVertexBufferObjectID);
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, GetPointCount() * sizeof(float) * 3, &vertex.at(0), GL_DYNAMIC_DRAW);

	glGenBuffers(1, &mTextureCoordinateBufferObjectID);
	glBindBuffer(GL_ARRAY_BUFFER, mTextureCoordinateBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, GetPointCount() * sizeof(float) * 3, &textureCoordinates.at(0), GL_DYNAMIC_DRAW);

}
void Mesh::InitializeColorMesh()
{

    SetOriginVertex(meshType);
	AddColor({ 1.0f, 1.0f, 0.f });
	SetVertex(originVertex);
	glGenVertexArrays(1, &mVertexArrayObject);
	glBindVertexArray(mVertexArrayObject);

	//Vertex Buffer Object(VBO)?
	glGenBuffers(1, &mPositionVertexBufferObjectID);
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, GetPointCount() * sizeof(float) * 3, &vertex.at(0), GL_DYNAMIC_DRAW);

	glGenBuffers(1, &mTextureCoordinateBufferObjectID);
	glBindBuffer(GL_ARRAY_BUFFER, mTextureCoordinateBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, GetPointCount() * sizeof(float) * 3, &colors.at(0), GL_DYNAMIC_DRAW);

}
void Mesh::Update(unsigned shaderHandler, GLuint id)
{

	SetVertex(originVertex);

	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, GetPointCount() * sizeof(float) * 3, &vertex.at(0), GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vector3<float>), (GLvoid*)0);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, mTextureCoordinateBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, GetPointCount() * sizeof(float) * 3, &textureCoordinates.at(0), GL_DYNAMIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glUseProgram(shaderHandler);
	glBindTexture(GL_TEXTURE_2D, id);
	glDrawArrays(GetPointListPattern(), 0, static_cast<GLsizei>(GetPointCount()));

	float ndc[] = {
	2.f / APPLICATION->width, 0, 0,
	0, 2.f / APPLICATION->height, 0,
	0, 0, 1
	};

	int location = glGetUniformLocation(shaderHandler, "ndc");
	glUniformMatrix3fv(location, 1, GL_FALSE, ndc);
}

void Mesh::ColorMeshUpdate(unsigned shaderHandler)
{

	SetVertex(originVertex);

	glUseProgram(shaderHandler);
	glBindBuffer(GL_ARRAY_BUFFER, mPositionVertexBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, GetPointCount() * sizeof(float) * 3, &vertex.at(0), GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vector3<float>), (GLvoid*)0);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, mTextureCoordinateBufferObjectID);
	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(float) * 3, &colors.at(0), GL_DYNAMIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glDrawArrays(GetPointListPattern(), 0, static_cast<GLsizei>(GetPointCount()));
}

void Mesh::Delete()
{
	glDeleteBuffers(1, &mPositionVertexBufferObjectID);
	glDeleteBuffers(1, &mColorVertexBufferObjectID);
	glDeleteVertexArrays(1, &mVertexArrayObject);
}
GLuint* Mesh::GetVertexArrayObjectPointer(void) noexcept
{
	GLuint* vertexArr = &mVertexArrayObject;

	return vertexArr;
}
GLuint Mesh::GetVertexArrayObject(void) noexcept
{
	GLuint vertexOb = mVertexArrayObject;

	return vertexOb;
}
std::size_t Mesh::GetPointCount() const noexcept
{
	return originVertex.size();
}
//Returns the i th point in the mesh
std::vector<Vector3<float>> Mesh::GetPoint() const noexcept
{
	return vertex;
}

void Mesh::SetVertex(std::vector<Vector3<float>> shapeType)
{
	Matrix3<float> T = Matrix3<float>::Translate({ transform.GetTranslation().x,  transform.GetTranslation().y,1 });
	Matrix3<float> R = Matrix3<float>::Rotate(transform.GetRotation());
	Matrix3<float> S = Matrix3<float>::Scale({ 1.f, 1.f, 1.f });
	if (meshType == MESHTYPE::hexagon)
	{
		S = Matrix3<float>::Scale({ 100.f, 100.f, 1.f });
	}

	vertex = originVertex;

	for (unsigned int i = 0; i < vertex.size(); i++)
	{
		Vector3<float> mA = (/*CAMERA->CameraToWorld() */T * R * S) * vertex.at(i);
		vertex.at(i) = { mA.x, mA.y, 1 };
	}
}
void Mesh::SetOriginVertex(MESHTYPE meshType2)
{
    switch (meshType2)
    {
    case MESHTYPE::hexagon:
        originVertex = createHexagon();
        break;
    case MESHTYPE::box:
        originVertex = create_box();
        break;
    case MESHTYPE::wire_circle:
        originVertex = create_wire_circle();
        break;
    case MESHTYPE::wire_rectangle:
        originVertex = create_wire_rectangle();
        break;
    case MESHTYPE::rectangle:
        originVertex = create_rectangle();
        break;
    case MESHTYPE::triangle:
        originVertex = create_triangle();
        break;
    case MESHTYPE::line:
        originVertex = create_line();
        break;
    case MESHTYPE::ellipse:
        originVertex = createEllipse();
        break;
    }
}

/*Returns the i th texture coordinate in the mesh. As long as index is within the range [0,PointCount) then this will return a valid texture coordinate.
	   If the mesh actually has no texture coordinates then the {0,0} texture coordinate will be returned.
	   If the index �� texture coordinate size then the last (back) texture coordinate will be returned.*/
std::vector<Vector3<float>>  Mesh::GetTextureCoordinate()  const noexcept
{
	return textureCoordinates;
}
//Simple getter for pointListType
GLenum Mesh::GetPointListPattern()  const noexcept
{
	return pointListType;
}
//Simple setter for pointListType

//Adds a new color to the mesh
void Mesh::AddColor(Vector3<float> mColor) noexcept
{
	colors.clear();
	for (unsigned int i = 0; i < GetPointCount(); i++)
	{
		colors.push_back(mColor);
	}

}
void Mesh::SetColor(Vector3<float> mColor) noexcept
{
	colors.clear();
	for (unsigned int i = 0; i < GetPointCount(); i++)
	{
		colors.push_back(mColor);
	}

}
//Adds a new point to the mesh
void Mesh::AddPoint(Vector3<float>  point) noexcept
{
	points.push_back(point);

}
//Adds a new texture coordinate to the mesh
void Mesh::AddTextureCoordinate(Vector3<float> texture_coordinate) noexcept
{
	textureCoordinates.push_back(texture_coordinate);
}

//Remove all points, colors and texture coordinates from the mesh
void Mesh::Clear() noexcept
{
	colors.clear();
	points.clear();
	textureCoordinates.clear();
}
void Mesh::SplitAnimation() noexcept
{
	std::vector<Vector3<float>> tempTexture = textureCoordinates;

	textureCoordinates.clear();

	if (splitCheck == 0)
	{
		textureCoordinates.push_back({ 0, 1, 0 });
		textureCoordinates.push_back({ 0, 0, 0 });
		textureCoordinates.push_back({ 1 / 8.f, 0.f, 0 });
		textureCoordinates.push_back({ 1 / 8.f, 1.f, 0 });
		splitCheck++;
	}
	else if(splitCheck/30==8)
	{
		textureCoordinates.push_back({ 0, 1, 0 });
		textureCoordinates.push_back({ 0, 0, 0 });
		textureCoordinates.push_back({ 1 / 8.f, 0.f, 0 });
		textureCoordinates.push_back({ 1 / 8.f, 1.f, 0 });
		splitCheck = 0;

	}
	else if(splitCheck%31==0)
	{
		textureCoordinates.push_back(tempTexture.at(3));
		textureCoordinates.push_back(tempTexture.at(2));
		textureCoordinates.push_back({ tempTexture.at(2).x+(1/8.f), tempTexture.at(2).y, tempTexture.at(2).z });
		textureCoordinates.push_back({ tempTexture.at(3).x + (1 / 8.f), tempTexture.at(3).y, tempTexture.at(3).z });
		splitCheck++;
	}
	else
	{
		textureCoordinates = tempTexture;
		splitCheck++;
	}

}
std::vector<Vector3<float>> Mesh::createEllipse() noexcept
{
	std::vector<Vector3<float>> ellipseVector;
	SetPointListPattern(GL_TRIANGLE_FAN);

	float theta = static_cast<float>(M_PI * 2 / 25);

	Vector3<float> mA = { 0, 0,1 };
	ellipseVector.push_back(mA);
	for (int i = 0; i < 25; i++)
	{
		mA = Vector3<float>(sin(theta * i) * 2, cos(theta * i), 1);
		ellipseVector.push_back({ mA.x, mA.y, 1 });

	}
	ellipseVector.push_back({ sin(theta * 0) * 2, cos(theta * 0), 1 });


	return ellipseVector;
}
std::vector<Vector3<float>> Mesh::createHexagon() noexcept
{
	std::vector<Vector3<float>> hexaVector;
	pointListType = GL_TRIANGLE_FAN;

	float theta = static_cast<float>(M_PI * 2 / 6);

	Vector3<float> mA = { 0, 0,1 };
	hexaVector.push_back(mA);
	for (int i = 0; i < 6; i++)
	{
		mA = Vector3<float>(sin(theta * i), -cos(theta * i), 1);
		hexaVector.push_back({ mA.x, mA.y, 1 });

	}
	hexaVector.push_back({ sin(theta * 0), -cos(theta * 0), 1 });

	textureCoordinates.push_back({ 0.5f, 0.5f, 0 });
	textureCoordinates.push_back({ 0.5f, 0.0f ,0 });
	textureCoordinates.push_back({ 1.0f, 0.25f,0 });
	textureCoordinates.push_back({ 1.0f, 0.75f ,0 });
	textureCoordinates.push_back({ 0.5f, 1.0f,0 });
	textureCoordinates.push_back({ 0.0f, 0.75f,0 });
	textureCoordinates.push_back({ 0.0f, 0.25f ,0 });
	textureCoordinates.push_back({ 0.5f, 0.0f ,0 });

	return hexaVector;
}
std::vector<Vector3<float>> Mesh::create_wire_circle(float radius,
	std::size_t point_count) noexcept
{
	std::vector<Vector3<float>> wireCircle;
	pointListType = GL_LINE_LOOP;

	float theta  = static_cast<float>(M_PI * 2 / point_count);

	for (unsigned int i = 0; i < point_count; i++)
	{
		Vector3<float> mA = Vector3<float>(radius * sin(theta * i), radius * -cos(theta * i), 1);
		//Vector3<float>  point = { radius * sin(theta * i), radius * -cos(theta * i), 0 };
		wireCircle.push_back({ mA.x, mA.y, 1 });
	}

	return wireCircle;
}
std::vector<Vector3<float>> Mesh::create_box(float dimension) noexcept
{	
	std::vector<Vector3<float>> box;

	pointListType = GL_TRIANGLE_FAN;

	textureCoordinates.push_back({ 0,1 ,0 });
	textureCoordinates.push_back({ 0,0,0 });
	textureCoordinates.push_back({ 1,0 ,0 });
	textureCoordinates.push_back({ 1,1,0 });
;
	Vector3<float> mA = Vector3(-dimension / 2, -dimension / 2, 1.f);
	Vector3<float> mB = Vector3(-dimension / 2, dimension / 2, 1.f);
	Vector3<float> mC = Vector3(dimension / 2, dimension / 2, 1.f);
	Vector3<float> mD = Vector3(dimension / 2, -dimension / 2, 1.f);

	box.push_back({ mA.x, mA.y, 1 });
	box.push_back({ mB.x, mB.y, 1 });
	box.push_back({ mC.x, mC.y, 1 });
	box.push_back({ mD.x, mD.y, 1 });

	return box;

}
std::vector<Vector3<float>> Mesh::create_rectangle() noexcept
{
	std::vector<Vector3<float>> rectangle;

	pointListType = GL_TRIANGLE_FAN;

	textureCoordinates.push_back({ 0,1,0 });
	textureCoordinates.push_back({ 0,0 ,0 });
	textureCoordinates.push_back({ 1,0 ,0 });
	textureCoordinates.push_back({ 1,1 ,0 });


	Vector3<float> mA = Vector3(-shapeSize.x / 2, -shapeSize.y / 2, 1.f);
	Vector3<float> mB = Vector3(-shapeSize.x / 2, shapeSize.y / 2, 1.f);
	Vector3<float> mC = Vector3(shapeSize.x / 2, shapeSize.y / 2, 1.f);
	Vector3<float> mD = Vector3(shapeSize.x / 2, -shapeSize.y / 2, 1.f);

	rectangle.push_back({ mA.x, mA.y, 1 });
	rectangle.push_back({ mB.x, mB.y, 1 });
	rectangle.push_back({ mC.x, mC.y, 1 });
	rectangle.push_back({ mD.x, mD.y, 1 });

	return rectangle;

}
std::vector<Vector3<float>> Mesh::create_wire_rectangle() noexcept
{

	std::vector<Vector3<float>> rectangle;
	pointListType = GL_LINE_LOOP;

	textureCoordinates.push_back({ 0,1 ,0 });
	textureCoordinates.push_back({ 0,0 ,0 });
	textureCoordinates.push_back({ 1,0 ,0 });
	textureCoordinates.push_back({ 1,1 ,0 });


	Vector3<float> mA = Vector3(-shapeSize.x / 2, -shapeSize.y / 2, 1.f);
	Vector3<float> mB = Vector3(-shapeSize.x / 2, shapeSize.y / 2, 1.f);
	Vector3<float> mC = Vector3(shapeSize.x / 2, shapeSize.y / 2, 1.f);
	Vector3<float> mD = Vector3(shapeSize.x / 2, -shapeSize.y / 2, 1.f);

	rectangle.push_back({ mA.x, mA.y, 1 });
	rectangle.push_back({ mB.x, mB.y, 1 });
	rectangle.push_back({ mC.x, mC.y, 1 });
	rectangle.push_back({ mD.x, mD.y, 1 });

	return rectangle;

}

std::vector<Vector3<float>> Mesh::create_triangle(Vector3<float> a, Vector3<float> b, Vector3<float> c) noexcept
{
	std::vector<Vector3<float>> triangle;
	pointListType = GL_TRIANGLES;

	triangle.push_back(a);
	triangle.push_back(b);
	triangle.push_back(c);

	return triangle;
}

std::vector<Vector3<float>> Mesh::create_line(Vector2<float> a, Vector2<float> b) noexcept
{
	std::vector<Vector3<float>> line;
	pointListType = GL_LINES;

	line.push_back({ a.x, a.y, 1.f });
	line.push_back({ b.x, b.y, 1.f });

	return line;
}
