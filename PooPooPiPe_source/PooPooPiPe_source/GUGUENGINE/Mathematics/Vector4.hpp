#pragma once
#include <iostream>
/*
 *hakyung.kim
 *11.18.2019
 *digipen.hagyeong@gmail.com
 *Vector4.hpp
 *vector4 math custom library
 */

	template <typename T>
	class Vector4 {
	public:
		//==============================================Components============================================
		T x;
		T y;
		T z;
		T w;
		//=============================================Constructor============================================
		Vector4<T>();
		Vector4<T>(const T& p_XValue, const T& p_YValue, const T& p_ZValue, const T& p_WValue);
		//==============================================Addition==============================================
		Vector4<T> &Add(const Vector4<T> &p_Vector);
		//=============================================Subtraction============================================
		Vector4<T> &Subtract(const Vector4<T> &p_Vector);
		//============================================Multiplication==========================================
		Vector4<T> &Multiply(const Vector4<T> &p_Vector);
		//===============================================Division=============================================
		Vector4<T> &Divide(const Vector4<T> &p_Vector);
		//=========================================+= Operator Override=======================================
		Vector4<T> &operator+=(const Vector4<T> &p_Vector);
		//=========================================-= Operator Override=======================================
		Vector4<T> &operator-=(const Vector4<T> &p_Vector);
		//=========================================*= Operator Override=======================================
		Vector4<T> &operator*=(const Vector4<T> &p_Vector);
		//=========================================/= Operator Override=======================================
		Vector4<T> &operator/=(const Vector4<T> &p_Vector);
		//=========================================== Operator Override=======================================
		bool operator==(const Vector4<T> &p_Vector);
		//=========================================!= Operator Override=======================================
		bool operator!=(const Vector4<T> &p_Vector);
		//==========================================+ Operator Override=======================================
		friend Vector4<T> operator+(Vector4<T> p_LValue, const Vector4<T> &p_RValue);
		//==========================================- Operator Override=======================================
		friend Vector4<T> operator-(Vector4<T> p_LValue, const Vector4<T> &p_RValue);
		//==========================================* Operator Override=======================================
		friend Vector4<T> operator*(Vector4<T> p_LValue, const Vector4<T> &p_RValue);
		//==========================================/ Operator Override=======================================
		friend Vector4<T> operator/(Vector4<T> p_LValue, const Vector4<T> &p_RValue);
		//=========================================<< Operator Override=======================================
		friend std::ostream &operator<<(std::ostream &p_Stream, const Vector4<T> &p_Vector);
};
