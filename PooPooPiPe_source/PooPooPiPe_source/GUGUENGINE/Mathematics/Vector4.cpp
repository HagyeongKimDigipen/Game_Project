/*
 *hakyung.kim
 *11.18.2019
 *digipen.hagyeong@gmail.com
 *Vector4.hpp
 * vector4 math custom library
 */
#include "Vector4.hpp"

//=============================================Constructor============================================
template <typename T>
Vector4<T>::Vector4() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}
template <typename T>
Vector4<T>::Vector4(const T& p_XValue, const T& p_YValue, const T& p_ZValue, const T& p_WValue) {
	this->x = p_XValue;
	this->y = p_YValue;
	this->z = p_ZValue;
	this->w = p_WValue;
}
//==============================================Addition==============================================
template <typename T>
Vector4<T> &Vector4<T>::Add(const Vector4<T> &p_Vector) {
	x += p_Vector.x;
	y += p_Vector.y;
	z += p_Vector.z;
	w += p_Vector.w;
	return *this;
}
//=============================================Subtraction============================================
template <typename T>
	Vector4<T> &Vector4<T>::Subtract(const Vector4<T> &p_Vector) {
	x -= p_Vector.x;
	y -= p_Vector.y;
	z -= p_Vector.z;
	w -= p_Vector.w;
	return *this;
}
//============================================Multiplication==========================================
	template <typename T>
	Vector4<T> &Vector4<T>::Multiply(const Vector4<T> &p_Vector) {
	x *= p_Vector.x;
	y *= p_Vector.y;
	z *= p_Vector.z;
	w *= p_Vector.w;
	return *this;
}
//===============================================Division=============================================
	template <typename T>
	Vector4<T> &Vector4<T>::Divide(const Vector4<T> &p_Vector) {
	x /= p_Vector.x;
	y /= p_Vector.y;
	z /= p_Vector.z;
	w /= p_Vector.w;
	return *this;
}
//=========================================+= Operator Override=======================================
	template <typename T>
	Vector4<T> &Vector4<T>::operator+=(const Vector4<T> &p_Vector) {
	return Add(p_Vector);
}
//=========================================-= Operator Override=======================================
	template <typename T>
	Vector4<T> &Vector4<T>::operator-=(const Vector4<T> &p_Vector) {
	return Subtract(p_Vector);
}
//=========================================*= Operator Override=======================================
	template <typename T>
	Vector4<T> &Vector4<T>::operator*=(const Vector4<T> &p_Vector) {
	return Multiply(p_Vector);
}
//=========================================/= Operator Override=======================================
	template <typename T>
	Vector4<T> &Vector4<T>::operator/=(const Vector4<T> &p_Vector) {
	return Divide(p_Vector);
}
//=========================================== Operator Override=======================================
	template <typename T>
	bool Vector4<T>::operator==(const Vector4<T> &p_Vector) {
	return (x == p_Vector.x && y == p_Vector.y && z == p_Vector.z && w == p_Vector.w);
}
//=========================================!= Operator Override=======================================
	template <typename T>
	bool Vector4<T>::operator!=(const Vector4<T> &p_Vector) {
	return !(*this == p_Vector);
}
//==========================================+ Operator Override=======================================
	template <typename T>
	Vector4<T> operator+(Vector4<T> p_LValue, const Vector4<T> &p_RValue) {
	return p_LValue.Add(p_RValue);
}
//==========================================- Operator Override=======================================
	template <typename T>
	Vector4<T> operator-(Vector4<T> p_LValue, const Vector4<T> &p_RValue) {
	return p_LValue.Subtract(p_RValue);
}
//==========================================* Operator Override=======================================
	template <typename T>
	Vector4<T> operator*(Vector4<T> p_LValue, const Vector4<T> &p_RValue) {
	return p_LValue.Multiply(p_RValue);
}
//==========================================/ Operator Override=======================================
	template <typename T>
	Vector4<T> operator/(Vector4<T> p_LValue, const Vector4<T> &p_RValue) {
	return p_LValue.Divide(p_RValue);
}
//=========================================<< Operator Override=======================================
template <typename T>
	std::ostream &operator<<(std::ostream &p_Stream, const Vector4<T> &p_Vector) {
	p_Stream << "[Vector4<T>] (" << p_Vector.x << ", " << p_Vector.y << ", " << p_Vector.z << ", " << p_Vector.w << ")";
	return p_Stream;
}
