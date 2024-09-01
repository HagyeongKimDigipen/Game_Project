#pragma once
/*
 *hakyung.kim
 *11.18.2019
 *digipen.hagyeong@gmail.com
 *Vector2.hpp
 *vector2 math custom library
 */
#include <iostream>
#include <cassert>


template <typename T>
	class Vector2 {
	public:
		
		//==============================================Components============================================
		T x;
		T y;
		//=============================================Constructor============================================
		T width = 800;
		T height = 800;
		Vector2();

		struct Edge
		{
			Edge() :start(0.f, 0.f), end(0.f, 0.f) {};
			Edge(Vector2<float> start, Vector2<float> end) : start(start), end(end) {}

			Vector2<float> start = { 0.f, 0.f };
			Vector2<float> end = { 0.f, 0.f };
		};

		Vector2(const T& p_XValue, const T& p_YValue);
		Vector2<T> rotate_by(float angle_in_radians, Vector2<T> v) noexcept;
		T magnitude(Vector2<T> a) noexcept;
		Vector2<T> normalize( Vector2<T> a) noexcept;
		T dot(Vector2<T> a, Vector2<T> b) noexcept;
		 T magnitude_squared(Vector2<T> a) noexcept;
		//==============================================Addition==============================================
		Vector2<T> &Add(const Vector2<T> &p_Vector);
		//=============================================Subtraction============================================
		Vector2<T> &Subtract(const Vector2<T> &p_Vector);
		//============================================Multiplication==========================================
		Vector2<T> &Multiply(const Vector2<T> &p_Vector);
		//===============================================Division=============================================
		Vector2<T> &Divide(const Vector2<T> &p_Vector);
		//=========================================+= Operator Override=======================================
		Vector2<T> &operator+=(const Vector2<T> &p_Vector);
		//=========================================-= Operator Override=======================================
		Vector2<T> &operator-=(const Vector2<T> &p_Vector);
		//=========================================*= Operator Override=======================================
		Vector2<T> &operator*=(const Vector2<T> &p_Vector);
		//=========================================/= Operator Override=======================================
		Vector2<T> &operator/=(const Vector2<T> &p_Vector);
		//=========================================== Operator Override=======================================
		bool operator==(const Vector2<T> &p_Vector);
		//=========================================!= Operator Override=======================================
		bool operator!=(const Vector2<T>&p_Vector);
		//==========================================+ Operator Override=======================================
		friend Vector2<T> operator+(Vector2<T> p_LValue, const Vector2<T>&p_RValue);
		//==========================================- Operator Override=======================================
		friend Vector2<T> operator-(Vector2<T> p_LValue, const Vector2<T>&p_RValue);
		//==========================================* Operator Override=======================================
		friend Vector2<T> operator*(Vector2<T> p_LValue, const Vector2<T>&p_RValue);
		//==========================================/ Operator Override=======================================
		friend Vector2<T> operator/(Vector2<T> p_LValue, const Vector2<T>&p_RValue);
		//=========================================<< Operator Override=======================================
		friend std::ostream &operator<<(std::ostream &p_Stream, const Vector2<T>&p_Vector);
};
	template <typename T>
	[[nodiscard]] T Vector2<T>::magnitude(const Vector2<T> a) noexcept
	{
		T magNotSquared;

		magNotSquared = std::sqrt(magnitude_squared(a));

		return magNotSquared;
	}
	template <typename T>
	T Vector2<T>::magnitude_squared(Vector2<T> a) noexcept
	{
		T magSquared;

		magSquared = (a.x) * (a.x) + (a.y) * (a.y);

		return magSquared;
	}

	template <typename T>
	Vector2<T> Vector2<T>::normalize(const Vector2<T> a) noexcept
	{
		Vector2<T> normVector;

		normVector.x = a.x / magnitude(a);
		normVector.y = a.y / magnitude(a);
		//assert(magnitude(a) != 0.0f);
		//{
		//	normVector.x = a.x / magnitude(a);
		//	normVector.y = a.y / magnitude(a);
		//}

		return normVector;
	}
	//=============================================Constructor============================================
	template <typename T>
	Vector2<T>::Vector2() {
		x = 0;
		y = 0;
	}
	template <typename T>
	Vector2<T>::Vector2(const T& p_XValue, const T& p_YValue) {
		this->x = p_XValue;
		this->y = p_YValue;
	}
	//==============================================Addition==============================================
	template <typename T>
	Vector2<T>& Vector2<T>::Add(const Vector2<T>& p_Vector) {
		x += p_Vector.x;
		y += p_Vector.y;
		return *this;
	}
	//=============================================Subtraction============================================
	template <typename T>
	Vector2<T>& Vector2<T>::Subtract(const Vector2<T>& p_Vector) {
		x -= p_Vector.x;
		y -= p_Vector.y;
		return *this;
	}
	//============================================Multiplication==========================================
	template <typename T>
	Vector2<T>& Vector2<T>::Multiply(const Vector2<T>& p_Vector) {
		x *= p_Vector.x;
		y *= p_Vector.y;
		return *this;
	}
	//===============================================Division=============================================
	template <typename T>
	Vector2<T>& Vector2<T>::Divide(const Vector2<T>& p_Vector) {
		x /= p_Vector.x;
		y /= p_Vector.y;
		return *this;
	}
	//=========================================+= Operator Override=======================================
	template <typename T>
	Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& p_Vector) {
		return Add(p_Vector);
	}
	//=========================================-= Operator Override=======================================
	template <typename T>
	Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& p_Vector) {
		return Subtract(p_Vector);
	}
	//=========================================*= Operator Override=======================================
	template <typename T>
	Vector2<T>& Vector2<T>::operator*=(const Vector2<T>& p_Vector) {
		return Multiply(p_Vector);
	}
	//=========================================/= Operator Override=======================================
	template <typename T>
	Vector2<T>& Vector2<T>::operator/=(const Vector2<T>& p_Vector) {
		return Divide(p_Vector);
	}
	//=========================================== Operator Override=======================================
	template <typename T>
	bool Vector2<T>::operator==(const Vector2<T>& p_Vector) {
		return (x == p_Vector.x && y == p_Vector.y);
	}
	//=========================================!= Operator Override=======================================
	template <typename T>
	bool Vector2<T>::operator!=(const Vector2<T>& p_Vector) {
		return !(*this == p_Vector);
	}
	//==========================================+ Operator Override=======================================
	template <typename T>
	Vector2<T> operator+(Vector2<T> p_LValue, const Vector2<T>& p_RValue) {
		return p_LValue.Add(p_RValue);
	}
	//==========================================- Operator Override=======================================
	template <typename T>
	Vector2<T> operator-(Vector2<T> p_LValue, const Vector2<T>& p_RValue) {
		return p_LValue.Subtract(p_RValue);
	}
	//==========================================* Operator Override=======================================
	template <typename T>
	Vector2<T> operator*(Vector2<T> p_LValue, const Vector2<T>& p_RValue) {
		return p_LValue.Multiply(p_RValue);
	}
	//==========================================/ Operator Override=======================================
	template <typename T>
	Vector2<T> operator/(Vector2<T> p_LValue, const Vector2<T>& p_RValue) {
		return p_LValue.Divide(p_RValue);
	}
	//=========================================<< Operator Override=======================================
	template <typename T>
	std::ostream& operator<<(std::ostream& p_Stream, const Vector2<T>& p_Vector) {
		p_Stream << "[Vector2<T>] (" << p_Vector.x << ", " << p_Vector.y << ")";
		return p_Stream;
	}
	template <typename T>
	Vector2<T> Vector2<T>::rotate_by(float angle_in_radians, Vector2<T> v) noexcept
	{
		Vector2<T> rotateBy;

		rotateBy.x = v.x * std::cos(angle_in_radians) - (v.y * std::sin(angle_in_radians));
		rotateBy.y = v.y * std::cos(angle_in_radians) + (v.x * std::sin(angle_in_radians));

		return rotateBy;
	}

	template <typename T>
	 T Vector2<T>::dot(Vector2<T> a, Vector2<T> b) noexcept
	{
		T dotProduct;

		dotProduct = a.x * b.x + a.y * b.y;

		return dotProduct;
	}
