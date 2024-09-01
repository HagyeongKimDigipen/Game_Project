#pragma once
/*
 *hakyung.kim
 *11.18.2019
 *digipen.hagyeong@gmail.com
 *Matrix4.hpp
 *Matrix4 math custom library
 */
#include "MathLibrary.hpp"

	template <typename T>
	class Matrix4 {
	public:
		//===========================================Union For Memory=========================================
		union {
			T Elements[4 * 4];
			Vector4<T> Column[4];
		};
		//=============================================Constructor============================================
		Matrix4();
		Matrix4(T p_Diagonal);
		//========================================Get Column of Matrix4========================================
		Vector4<T> GetColumn(int p_Index) {
			p_Index * 4;
			return Vector4<T>(Elements[p_Index], Elements[p_Index + 1], Elements[p_Index + 2], Elements[p_Index + 3]);
		}
		//============================================Multiplication==========================================
		Vector2<T> Multiply(const Vector2<T> &p_Vector) const;
		Vector3<T> Multiply(const Vector3<T> &p_Vector) const;
		Vector4<T> Multiply(const Vector4<T> &p_Vector) const;
		Matrix4<T> &Multiply(const Matrix4<T>  &p_Matrix4);
		//=========================================*= Operator Override=======================================
		Matrix4<T> &operator*=(const Matrix4<T> &p_Matrix4);
		//==========================================* Operator Override=======================================
		friend Vector2<T> operator*(const Matrix4<T>& p_LValue, const Vector2<T>& p_RValue);
		//Vector2<T> operator*(const Matrix4<T> &p_LValue, const Vector2<T> &p_RValue);
		friend Vector3<T> operator*(const Matrix4<T> &p_LValue, const Vector3<T> &p_RValue);
		friend Vector4<T> operator*(const Matrix4<T> &p_LValue, const Vector4<T> &p_RValue);
		friend Matrix4<T>  operator*(Matrix4<T> p_LValue, const Matrix4<T> &p_RValue);
		//============================================Identity Matrix4=========================================
		static Matrix4<T> Identiy();
		//==============================================Orthographic==========================================
		static Matrix4<T> Orthographic(T p_Left, T p_Right, T p_Bottom, T p_Top, T p_Near, T p_Far);
		//==============================================Perspective===========================================
		static Matrix4<T> Perspective(T p_FieldOfView, T p_AspectRatio, T p_Near, T p_Far);
		//===============================================Rotation=============================================
		static Matrix4<T> Rotate(T p_Angle, const Vector3<T> &p_Axis);
		//===============================================Translate============================================
		static Matrix4<T> Translate(const Vector3<T> &p_Translation);
		//=================================================Scale==============================================
		static Matrix4<T> Scale(const Vector3<T> &p_Scale);
	};




	//=============================================Constructor============================================
	template <typename T>
	Matrix4<T>::Matrix4() {
		for (int i = 0; i < 4 * 4; i++) {
			Elements[i] = 0.0f;
		}
	}
	template <typename T>
	Matrix4<T>::Matrix4(T p_Diagonal) {
		for (int i = 0; i < 4 * 4; i++) {
			Elements[i] = 0.0f;
		}
		Elements[0 + 0 * 4] = p_Diagonal;
		Elements[1 + 1 * 4] = p_Diagonal;
		Elements[2 + 2 * 4] = p_Diagonal;
		Elements[3 + 3 * 4] = p_Diagonal;
	}
	//============================================Multiplication==========================================
	template <typename T>
	Vector2<T> Matrix4<T>::Multiply(const Vector2<T>& p_Vector) const {
		return Vector2<T>(
			Column[0].x * p_Vector.x + Column[1].x * p_Vector.y + Column[2].x + Column[3].x,
			Column[0].y * p_Vector.x + Column[1].y * p_Vector.y + Column[2].y + Column[3].y
			);
	}
	template <typename T>
	Vector3<T> Matrix4<T>::Multiply(const Vector3<T>& p_Vector) const {
		return Vector3<T>(
			Column[0].x * p_Vector.x + Column[1].x * p_Vector.y + Column[2].x * p_Vector.z + Column[3].x,
			Column[0].y * p_Vector.x + Column[1].y * p_Vector.y + Column[2].y * p_Vector.z + Column[3].y,
			Column[0].z * p_Vector.x + Column[1].z * p_Vector.y + Column[2].z * p_Vector.z + Column[3].z
			);
	}
	template <typename T>
	Vector4<T> Matrix4<T>::Multiply(const Vector4<T>& p_Vector) const {
		return Vector4<T>(
			Column[0].x * p_Vector.x + Column[1].x * p_Vector.y + Column[2].x * p_Vector.z + Column[3].x * p_Vector.w,
			Column[0].y * p_Vector.x + Column[1].y * p_Vector.y + Column[2].y * p_Vector.z + Column[3].y * p_Vector.w,
			Column[0].z * p_Vector.x + Column[1].z * p_Vector.y + Column[2].z * p_Vector.z + Column[3].z * p_Vector.w,
			Column[0].w * p_Vector.x + Column[1].w * p_Vector.y + Column[2].w * p_Vector.z + Column[3].w * p_Vector.w
			);
	}
	template <typename T>
	Matrix4<T>& Matrix4<T>::Multiply(const Matrix4<T>& p_Matrix4) {
		T Matrix4Data[16];
		for (int Row = 0; Row < 4; Row++) {
			for (int Column = 0; Column < 4; Column++) {
				T Sum = 0.0f;
				for (int Component = 0; Component < 4; Component++) {
					Sum += Elements[Column + Component * 4] * p_Matrix4.Elements[Component + Row * 4];
				}
				Matrix4Data[Column + Row * 4] = Sum;
			}
		}
		memcpy(Elements, Matrix4Data, 4 * 4 * sizeof(float));
		return *this;
	}
	//=========================================*= Operator Override=======================================
	template <typename T>
	Matrix4<T>& Matrix4<T>::operator*=(const Matrix4<T>& p_Matrix4) {
		return Multiply(p_Matrix4);
	}



	//==========================================* Operator Override=======================================
	template <typename T>
	Vector2<T> operator*(const Matrix4<T>& p_LValue, const Vector2<T>& p_RValue) {
		return p_LValue.Multiply(p_RValue);
	}
	template <typename T>
	Vector3<T> operator*(const Matrix4<T>& p_LValue, const Vector3<T>& p_RValue) {
		return p_LValue.Multiply(p_RValue);
	}
	template <typename T>
	Vector4<T> operator*(const Matrix4<T>& p_LValue, const Vector4<T>& p_RValue) {
		return p_LValue.Multiply(p_RValue);
	}
	template <typename T>
	Matrix4<T> operator*(Matrix4<T> p_LValue, const Matrix4<T>& p_RValue) {
		return p_LValue.Multiply(p_RValue);
	}
	//============================================Identity Matrix4=========================================
	template <typename T>
	Matrix4<T> Matrix4<T>::Identiy() {
		return Matrix4<T>(1.0f);
	}
	//==============================================Orthographic==========================================
	template <typename T>
	Matrix4<T> Matrix4<T>::Orthographic(T p_Left, T p_Right, T p_Bottom, T p_Top, T p_Near, T p_Far) {
		Matrix4<T> Result(1.0f);

		Result.Elements[0 + 0 * 4] = 2.0f / (p_Right - p_Left);
		Result.Elements[1 + 1 * 4] = 2.0f / (p_Top - p_Bottom);
		Result.Elements[2 + 2 * 4] = 2.0f / (p_Near - p_Far);

		Result.Elements[0 + 3 * 4] = (p_Left + p_Right) / (p_Left - p_Right);
		Result.Elements[1 + 3 * 4] = (p_Bottom + p_Top) / (p_Bottom - p_Top);
		Result.Elements[2 + 3 * 4] = (p_Far + p_Near) / (p_Far - p_Near);
		return Result;
	}
	//==============================================Perspective===========================================
	template <typename T>
	Matrix4<T> Matrix4<T>::Perspective(T p_FieldOfView, T p_AspectRatio, T p_Near, T p_Far) {
		Matrix4<T> Result(1.0f);

		T ValueQ = 1.0f / tan(DegreeToRadian(0.5f * p_FieldOfView));
		T ValueA = ValueQ / p_AspectRatio;
		T ValueB = (p_Near + p_Far) / (p_Near - p_Far);
		T ValueC = (2.0f * p_Near * p_Far) / (p_Near - p_Far);

		Result.Elements[0 + 0 * 4] = ValueA;
		Result.Elements[1 + 1 * 4] = ValueQ;
		Result.Elements[2 + 2 * 4] = ValueB;
		Result.Elements[3 + 2 * 4] = -1.0f;
		Result.Elements[2 + 3 * 4] = ValueC;
		return Result;
	}
	//===============================================Rotation=============================================
	template <typename T>
	Matrix4<T> Matrix4<T>::Rotate(T p_Angle, const Vector3<T>& p_Axis) {
		Matrix4<T> Result(1.0f);

		T ValueX = p_Axis.x;
		T ValueY = p_Axis.y;
		T ValueZ = p_Axis.z;
		T ValueRadian = DegreeToRadian(p_Angle);
		T ValueSine = sin(ValueRadian);
		T ValueCosine = cos(ValueRadian);
		T OneMinusCosine = 1.0f - ValueCosine;

		Result.Elements[0 + 0 * 4] = ValueX * OneMinusCosine + ValueCosine;
		Result.Elements[1 + 0 * 4] = ValueX * ValueY * OneMinusCosine + ValueZ * ValueSine;
		Result.Elements[2 + 0 * 4] = ValueX * ValueZ * OneMinusCosine - ValueY * ValueSine;

		Result.Elements[0 + 1 * 4] = ValueX * ValueY * OneMinusCosine - ValueZ * ValueSine;
		Result.Elements[1 + 1 * 4] = ValueY * OneMinusCosine + ValueCosine;
		Result.Elements[2 + 1 * 4] = ValueY * ValueZ * OneMinusCosine + ValueX * ValueSine;

		Result.Elements[0 + 2 * 4] = ValueX * ValueZ * OneMinusCosine + ValueY * ValueSine;
		Result.Elements[1 + 2 * 4] = ValueY * ValueZ * OneMinusCosine - ValueX * ValueSine;
		Result.Elements[2 + 2 * 4] = ValueZ * OneMinusCosine + ValueCosine;
		return Result;
	}
	//===============================================Translate============================================
	template <typename T>
	Matrix4<T> Matrix4<T>::Translate(const Vector3<T>& p_Translation) {
		Matrix4<T> Result(1.0f);

		Result.Elements[0 + 3 * 4] = p_Translation.x;
		Result.Elements[1 + 3 * 4] = p_Translation.y;
		Result.Elements[2 + 3 * 4] = p_Translation.z;
		return Result;
	}
	//=================================================Scale==============================================
	template <typename T>
	Matrix4<T> Matrix4<T>::Scale(const Vector3<T>& p_Scale) {
		Matrix4<T> Result(1.0f);

		Result.Elements[0 + 0 * 4] = p_Scale.x;
		Result.Elements[1 + 1 * 4] = p_Scale.y;
		Result.Elements[2 + 2 * 4] = p_Scale.z;
		return Result;
	}
