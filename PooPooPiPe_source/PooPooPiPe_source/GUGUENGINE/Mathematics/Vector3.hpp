#pragma once
/*
 *hakyung.kim
 *11.18.2019
 *digipen.hagyeong@gmail.com
 *Vector3.hpp
 *vector3 math custom library
 */
#include <iostream>


	template <typename T>
	class Vector3 {
	public:
		//==============================================Components============================================
		T x;
		T y;
		T z;
		//=============================================Constructor============================================
		Vector3<T>();
		Vector3<T>(const T &p_XValue, const T &p_YValue, const T &p_ZValue);
		//==============================================Addition==============================================
		Vector3<T> &Add(const Vector3<T> &p_Vector);
		//=============================================Subtraction============================================
		Vector3<T> &Subtract(const Vector3<T> &p_Vector);
		//============================================Multiplication==========================================
		Vector3<T> &Multiply(const Vector3<T> &p_Vector);
		//===============================================Division=============================================
		Vector3<T> &Divide(const Vector3<T> &p_Vector);
		//=========================================+= Operator Override=======================================
		Vector3<T> &operator+=(const Vector3<T> &p_Vector);
		//=========================================-= Operator Override=======================================
		Vector3<T> &operator-=(const Vector3<T> &p_Vector);
		//=========================================*= Operator Override=======================================
		Vector3<T> &operator*=(const Vector3<T> &p_Vector);
		//=========================================/= Operator Override=======================================
		Vector3<T> &operator/=(const Vector3<T> &p_Vector);
		//=========================================== Operator Override=======================================
		bool operator==(const Vector3<T> &p_Vector);
		//=========================================!= Operator Override=======================================
		bool operator!=(const Vector3<T> &p_Vector);
		//==========================================+ Operator Override=======================================
		friend Vector3<T> operator+(Vector3<T> p_LValue, const Vector3<T> &p_RValue);
		//==========================================- Operator Override=======================================
		friend Vector3<T> operator-(Vector3<T> p_LValue, const Vector3<T> &p_RValue);
		//==========================================* Operator Override=======================================
		friend Vector3<T> operator*(Vector3<T> p_LValue, const Vector3<T> &p_RValue);
		//==========================================/ Operator Override=======================================
		friend Vector3<T> operator/(Vector3<T> p_LValue, const Vector3<T> &p_RValue);
		//=========================================<< Operator Override=======================================
		friend std::ostream &operator<<(std::ostream &p_Stream, const Vector3<T> &p_Vector);
};



	 //=============================================Constructor============================================
	 template <typename T>
	 Vector3<T>::Vector3() {
		 x = 0.0f;
		 y = 0.0f;
		 z = 0.0f;
	 }
	 template <typename T>
	 Vector3<T>::Vector3(const T& p_XValue, const T& p_YValue, const T& p_ZValue) {
		 this->x = p_XValue;
		 this->y = p_YValue;
		 this->z = p_ZValue;
	 }
	 //==============================================Addition==============================================
	 template <typename T>
	 Vector3<T>& Vector3<T>::Add(const Vector3<T>& p_Vector) {
		 x += p_Vector.x;
		 y += p_Vector.y;
		 z += p_Vector.z;
		 return *this;
	 }
	 //=============================================Subtraction============================================
	 template <typename T>
	 Vector3<T>& Vector3<T>::Subtract(const Vector3<T>& p_Vector) {
		 x -= p_Vector.x;
		 y -= p_Vector.y;
		 z -= p_Vector.z;
		 return *this;
	 }
	 //============================================Multiplication==========================================
	 template <typename T>
	 Vector3<T>& Vector3<T>::Multiply(const Vector3<T>& p_Vector) {
		 x *= p_Vector.x;
		 y *= p_Vector.y;
		 z *= p_Vector.z;
		 return *this;
	 }
	 //===============================================Division=============================================
	 template <typename T>
	 Vector3<T>& Vector3<T>::Divide(const Vector3<T>& p_Vector) {
		 x /= p_Vector.x;
		 y /= p_Vector.y;
		 z /= p_Vector.z;
		 return *this;
	 }
	 //=========================================+= Operator Override=======================================
	 template <typename T>
	 Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& p_Vector) {
		 return Add(p_Vector);
	 }
	 //=========================================-= Operator Override=======================================
	 template <typename T>
	 Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& p_Vector) {
		 return Subtract(p_Vector);
	 }
	 //=========================================*= Operator Override=======================================
	 template <typename T>
	 Vector3<T>& Vector3<T>::operator*=(const Vector3<T>& p_Vector) {
		 return Multiply(p_Vector);
	 }
	 //=========================================/= Operator Override=======================================
	 template <typename T>
	 Vector3<T>& Vector3<T>::operator/=(const Vector3<T>& p_Vector) {
		 return Divide(p_Vector);
	 }
	 //=========================================== Operator Override=======================================
	 template <typename T>
	 bool Vector3<T>::operator==(const Vector3<T>& p_Vector) {
		 return (x == p_Vector.x && y == p_Vector.y && z == p_Vector.z);
	 }
	 //=========================================!= Operator Override=======================================
	 template <typename T>
	 bool Vector3<T>::operator!=(const Vector3<T>& p_Vector) {
		 return !(*this == p_Vector);
	 }
	 //==========================================+ Operator Override=======================================
	 template <typename T>
	 Vector3<T> operator+(Vector3<T> p_LValue, const Vector3<T>& p_RValue) {
		 return p_LValue.Add(p_RValue);
	 }
	 //==========================================- Operator Override=======================================
	 template <typename T>
	 Vector3<T> operator-(Vector3<T> p_LValue, const Vector3<T>& p_RValue) {
		 return p_LValue.Subtract(p_RValue);
	 }
	 //==========================================* Operator Override=======================================
	 template <typename T>
	 Vector3<T> operator*(Vector3<T> p_LValue, const Vector3<T>& p_RValue) {
		 return p_LValue.Multiply(p_RValue);
	 }
	 //==========================================/ Operator Override=======================================
	 template <typename T>
	 Vector3<T> operator/(Vector3<T> p_LValue, const Vector3<T>& p_RValue) {
		 return p_LValue.Divide(p_RValue);
	 }
	 //=========================================<< Operator Override=======================================
	 template <typename T>
	 std::ostream& operator<<(std::ostream& p_Stream, const Vector3<T>& p_Vector) {
		 p_Stream << "[Vector3<T>] (" << p_Vector.x << ", " << p_Vector.y << ", " << p_Vector.z << ")";
		 return p_Stream;
	 }
 