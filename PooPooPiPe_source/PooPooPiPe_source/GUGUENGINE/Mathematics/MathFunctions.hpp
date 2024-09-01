#pragma once
/*
 *hakyung.kim
 *11.18.2019
 *digipen.hagyeong@gmail.com
 *MathFunciont.hpp
 *that make degree to radian
 */
#define _USE_MATH_DEFINES
#include <math.h>


//======================================Convert Degree to Radian======================================
	inline float DegreeToRadian(float p_Degree) {
		return static_cast<float>(p_Degree * (M_PI / 180.0f));
	
}