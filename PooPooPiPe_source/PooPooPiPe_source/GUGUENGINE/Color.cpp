#include "Color.h"

	Color4ub::Color4ub(unsigned_byte grey, unsigned_byte alpha) noexcept :red(grey), green(grey), blue(grey), alpha(alpha) {};

	Color4ub::Color4ub(unsigned_byte red, unsigned_byte green, unsigned_byte blue, unsigned_byte alpha) noexcept : red(red), green(green), blue(blue), alpha(alpha) {};

	Color4ub to_color4ub(const Color4f& float_colors)//from float to ub
	{

		Color4ub a;

		if (float_colors.alpha < 1.0f&& float_colors.alpha> 0.0f)
		{
			a.alpha = static_cast<Color4ub::unsigned_byte>(float_colors.alpha) * 255;
			return a;
		}
		if (float_colors.red < 1.0f&& float_colors.red > 0.0f)
		{
			a.red = static_cast<Color4ub::unsigned_byte>(float_colors.red) * 255;
			return a;
		}
		if (float_colors.green< 1.0f&& float_colors.green > 0.0f)
		{
			a.green = static_cast<Color4ub::unsigned_byte>(float_colors.green) * 255;
			return a;
		}
		if (float_colors.blue <1.0f&& float_colors.blue >0.0f)
		{
			a.blue = static_cast<Color4ub::unsigned_byte>(float_colors.blue) * 255;
			return a;
		}


		return a;
	}

	Color4f::Color4f(float grey, float alpha) noexcept : red(grey), green(grey), blue(grey), alpha(alpha) {};

	Color4f::Color4f(float red, float green, float blue, float alpha) noexcept : red(red), green(green), blue(blue), alpha(alpha) {};

	Color4f to_color4f(const Color4ub & eight_bit_color)//from up to float
	{
		Color4f a;
		a.alpha = static_cast<float>(eight_bit_color.alpha) / 255;
		a.red = static_cast<float>(eight_bit_color.red) / 255;
		a.green = static_cast<float>(eight_bit_color.green) / 255;
		a.blue = static_cast<float>(eight_bit_color.blue) / 255;

		return a;
	}




