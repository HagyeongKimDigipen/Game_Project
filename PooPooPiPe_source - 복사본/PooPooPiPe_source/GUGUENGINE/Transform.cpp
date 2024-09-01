
#include "Transform.h"
#include "Mathematics/Vector3.hpp"


void Transform::Initialize(void)
{
	rotation = 0.f;
	translation = { 0.f, 0.f };
	scale = { 1.0f,1.0f };
}

void Transform::Update()
{
	float time = 0;
	time++;
}

Vector2<float> Transform::GetTranslation() const noexcept
{
	return translation;
}
Vector2<float> Transform::GetScale() const noexcept
{
	return scale;
}
void Transform::SetTranslation(const Vector2<float>& new_translation) noexcept
{
	translation = new_translation;
}
void Transform::AddTranslation(const Vector2<float>& new_translation) noexcept
{
	translation += new_translation;
}
void Transform::SetScale(const Vector2<float>& new_scale) noexcept
{
	scale = new_scale;
}
float Transform::GetRotation() const noexcept
{
	return rotation;
}
void Transform::SetRotation(float new_rotation) noexcept
{
	rotation = new_rotation;
}

