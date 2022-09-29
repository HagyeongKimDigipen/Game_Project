/*
 *juhye.son
 *10.14.2019
 *juhye.son990902@gmail.com
 *Image.h
 *for insert image
 */
#include "Image.h"
#include <algorithm>
#include <cassert>
#include <filesystem>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#pragma warning(push)
#pragma warning(disable : 4505) // unreferenced local function has been removed
#pragma warning(disable : 4100) // unreferenced formal parameter
#include "external/stb/include/stb_image.h"
#pragma warning(pop)

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBI_MSC_SECURE_CRT
#include "external/stb/include/stb_image_write.h"
#include "glew.h"
#include "Color.h"


	void Image::ResizeToPixelWidthHeight(int pixel_width, int pixel_height) noexcept
	{
		assert(pixel_height > 0 && pixel_width > 0);
		width = pixel_width;
		height = pixel_height;
		pixels.resize(width * height);
	}

	bool Image::LoadFromPNG(const std::filesystem::path& file_path) noexcept
	{
		int component = ChannelsPerColor;
		unsigned char* loadPNG = stbi_load(file_path.generic_string().c_str(), &width, &height, &component, STBI_rgb_alpha);
		if (loadPNG == nullptr)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < width * height * 4; i += 4)
			{
				Color4ub colorPNG = { loadPNG[i], loadPNG[i + 1], loadPNG[i + 2], loadPNG[i + 3] };
				pixels.push_back(colorPNG);
			}
			return true;
		}
	}

	void Image::SaveToPNG(const std::filesystem::path& file_path) const noexcept
	{
		stbi_write_png(file_path.generic_string().c_str(), width, height, ChannelsPerColor, GetPixelsPointer(), width * ChannelsPerColor);
	}

	int Image::GetWidth() const noexcept
	{
		return width;
	}

	int Image::GetHeight() const noexcept
	{
		return height;
	}

	void Image::SetPixel(int column, int row, Color4ub color) noexcept
	{
		assert(column >= 0 && row >= 0);
		pixels[column + row * width] = color;
	}

	Color4ub* Image::GetPixelsPointer() noexcept
	{
		return &pixels.front();
	}

	const Color4ub* Image::GetPixelsPointer() const noexcept
	{
		return &pixels.front();
	}

	int Image::GetPixelsBufferBytesSize() const noexcept
	{
		return width * height * sizeof(ChannelsPerColor);
	}

	void Image::FlipVertically() noexcept
	{

		std::vector<Color4ub> tempColorVector;
		tempColorVector.resize(width * height);

		for (int i = height - 1, j = 0; i >= 0; --i, ++j)
		{
			for (int k = 0; k < width; ++k)
			{
				tempColorVector[width * j + k] = pixels[width * i + k];
			}
		}

		pixels = tempColorVector;
	}
