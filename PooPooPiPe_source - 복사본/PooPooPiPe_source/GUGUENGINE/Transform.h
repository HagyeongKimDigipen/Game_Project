#pragma once

#include "Component.h"
#include "Mathematics/Vector3.hpp"
#include "Mathematics/Vector2.hpp"
#include "ComponentType.h"

class Transform : public Component
{
public:
	Transform() :Component(ComponentType::COMPONENTTYPE_TRANSFORM) {
		rotation = 0.f;
		translation = { 0.f, 0.f };
		scale = { 1.0f,1.0f };
	};

	void Initialize(void);
	void Update();
	Vector2<float> GetTranslation() const noexcept;
	Vector2<float> GetScale() const noexcept;
	void SetTranslation(const Vector2<float>& new_translation) noexcept;
	void AddTranslation(const Vector2<float>& new_translation) noexcept;
	void SetScale(const Vector2<float>& new_scale) noexcept;
	float GetRotation() const noexcept;
	void SetRotation(float new_rotation) noexcept;

private:

	Vector2<float> translation{};
	Vector2<float> scale{};
	float rotation;
};
