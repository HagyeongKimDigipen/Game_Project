#pragma once
/*
 *hakyung.kim
 *11.18.2019
 *digipen.hagyeong@gmail.com
 *Matrix3.hpp
 *Matrix3 math custom library
 */
#include "MathLibrary.hpp"



	
	template <typename T>
	class Matrix3 {
	public:
		//===========================================Union For Memory=========================================
		union {
			T Elements[3 * 3];
			Vector3<T> Column[3];
		};
		//=============================================Constructor============================================
		Matrix3();
		Matrix3(T p_Diagonal);
		//========================================Get Column of Matrix3========================================
		Vector3<T> GetColumn(int p_Index) {
			p_Index * 3;
			return Vector3<T>(Elements[p_Index], Elements[p_Index + 1], Elements[p_Index + 2]);
		}
		//============================================Multiplication==========================================
		
		Vector2<T> Multiply(const Vector2<T>& p_Vector) const;
		Vector3<T> Multiply(const Vector3<T>& p_Vector) const;
		Vector4<T> Multiply(const Vector4<T>& p_Vector) const;
		Matrix3<T>& Multiply(const Matrix3<T>& p_Matrix3);
		//=========================================*= Operator Override=======================================
		Matrix3<T>& operator*=(const Matrix3<T>& p_Matrix3);
		//==========================================* Operator Override=======================================

		//============================================Identity Matrix3=========================================
		static Matrix3<T> Identiy();
		//===============================================Rotation=============================================
		static Matrix3<T> Rotate(T p_Angle);
		//===============================================Translate============================================
		static Matrix3<T> Translate(const Vector3<T>& p_Translation);
		//=================================================Scale==============================================
		static Matrix3<T> Scale(const Vector3<T>& p_Scale);
	};

	template <typename T>
	Vector2<T> operator*(const Matrix3<T>& p_LValue, const Vector2<T>& p_RValue);
	template <typename T>
	Vector3<T> operator*(const Matrix3<T>& p_LValue, const Vector3<T>& p_RValue);
	template <typename T>
	Vector4<T> operator*(const Matrix3<T>& p_LValue, const Vector4<T>& p_RValue);
	template <typename T>
	Matrix3<T>  operator*(Matrix3<T> p_LValue, const Matrix3<T>& p_RValue);


	//=============================================Constructor============================================
	template <typename T>
	Matrix3<T>::Matrix3() {
		for (int i = 0; i < 3 * 3; i++) {
			Elements[i] = 0.0f;
		}
	}

	template <typename T>
	Matrix3<T>::Matrix3(T p_Diagonal) {
		for (int i = 0; i < 3 * 3; i++) {
			Elements[i] = 0.0f;
		}
		Elements[0 + 0 * 3] = p_Diagonal;
		Elements[1 + 1 * 3] = p_Diagonal;
		Elements[2 + 2 * 3] = p_Diagonal;
		/*
		 1 0 0
		 0 1 0
		 0 0 1
		 */
	}
	//============================================Multiplication==========================================
	template <typename T>
	Vector2<T> Matrix3<T>::Multiply(const Vector2<T>& p_Vector) const {
		return Vector2<T>(
			Column[0].x * p_Vector.x + Column[1].x * p_Vector.y + Column[2].x,
			Column[0].y * p_Vector.x + Column[1].y * p_Vector.y + Column[2].y
			);
	}
	template <typename T>
	Vector3<T> Matrix3<T>::Multiply(const Vector3<T>& p_Vector) const {
		return Vector3<T>(
			Column[0].x * p_Vector.x + Column[1].x * p_Vector.y + Column[2].x * p_Vector.z,
			Column[0].y * p_Vector.x + Column[1].y * p_Vector.y + Column[2].y * p_Vector.z,
			Column[0].z * p_Vector.x + Column[1].z * p_Vector.y + Column[2].z * p_Vector.z
			);
	}
	template <typename T>
	Vector4<T> Matrix3<T>::Multiply(const Vector4<T>& p_Vector) const {
		return Vector4<T>(
			Column[0].x * p_Vector.x + Column[1].x * p_Vector.y + Column[2].x * p_Vector.z,
			Column[0].y * p_Vector.x + Column[1].y * p_Vector.y + Column[2].y * p_Vector.z,
			Column[0].z * p_Vector.x + Column[1].z * p_Vector.y + Column[2].z * p_Vector.z,
			Column[0].WComponent * p_Vector.x + Column[1].WComponent * p_Vector.y + Column[2].WComponent * p_Vector.z
			);
	}
	template <typename T>
	Matrix3<T>& Matrix3<T>::Multiply(const Matrix3<T>& p_Matrix3) {
		T Matrix3Data[9];
		for (int mRow = 0; mRow < 3; mRow++) {
			for (int mColumn = 0; mColumn < 3; mColumn++) {
				T Sum = 0.0f;
				for (int Component = 0; Component < 3; Component++) {
					Sum += Elements[mColumn + Component * 3] * p_Matrix3.Elements[Component + mRow * 3];
				}
				Matrix3Data[mColumn + mRow * 3] = Sum;
			}
		}
		memcpy(Elements, Matrix3Data, 3 * 3 * sizeof(T));
		return *this;
	}
	//=========================================*= Operator Override=======================================
	template <typename T>
	Matrix3<T>& Matrix3<T>::operator*=(const Matrix3<T>& p_Matrix3) {
		return Multiply(p_Matrix3);
	}
	//==========================================* Operator Override=======================================
	template <typename T>
	 Vector2<T> operator*(const Matrix3<T>& p_LValue, const Vector2<T>& p_RValue) {
		return p_LValue.Multiply(p_RValue);
	}
	template <typename T>
	Vector3<T> operator*(const Matrix3<T>& p_LValue, const Vector3<T>& p_RValue) {
		return p_LValue.Multiply(p_RValue);
	}
	template <typename T>
	Vector4<T> operator*(const Matrix3<T>& p_LValue, const Vector4<T>& p_RValue) {
		return p_LValue.Multiply(p_RValue);
	}
	template <typename T>
	Matrix3<T> operator*(Matrix3<T> p_LValue, const Matrix3<T>& p_RValue) {
		return p_LValue.Multiply(p_RValue);
	}
	//============================================Identity Matrix3=========================================
	template <typename T>
	Matrix3<T> Matrix3<T>::Identiy() {
		return Matrix3<T>(1.0f);
	}

	//===============================================Rotation=============================================
	template <typename T>
	Matrix3<T> Matrix3<T>::Rotate(T p_Angle) {
		Matrix3<T> Result(1.0f);

		//T ValueRadian = DegreeToRadian(p_Angle);
		T ValueSine = sin(p_Angle);
		T ValueCosine = cos(p_Angle);

		Result.Elements[0] = ValueCosine;
		Result.Elements[3] = -ValueSine;
		Result.Elements[1] = ValueSine;
		Result.Elements[4] = ValueCosine;
		Result.Elements[8] = 1;

		return Result;
	}
	//===============================================Translate============================================
	template <typename T>
	Matrix3<T> Matrix3<T>::Translate(const Vector3<T>& p_Translation) {
		Matrix3<T> Result(1.0f);

		Result.Elements[6] = p_Translation.x;
		Result.Elements[7] = p_Translation.y;
		Result.Elements[8] = 1;
		return Result;
	}
	//=================================================Scale==============================================
	template <typename T>
	Matrix3<T> Matrix3<T>::Scale(const Vector3<T>& p_Scale) {
		Matrix3<T> Result(1.0f);

		Result.Elements[0 * 2] = p_Scale.x;
		Result.Elements[2 * 2] = p_Scale.y;
		Result.Elements[2 * 2 * 2] = 1;
		return Result;
	}

