#pragma once
#include <cstdint>
#include <iostream>

namespace gre
{
	//typedef unsigned char u8_t;
	//using u8_t = unsigned char;
	
	struct Color
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};

	inline std::istream& operator >> (std::istream& stream, Color& color)
	{
		std::string line;
		std::getline(stream, line);

		std::string str;
		//find red in file
		str = line.substr(line.find("{") + 1);
		color.r = (uint8_t)(std::stof(str) * 255);
		//find green in file
		str = line.substr(line.find(",") + 1);
		color.g = (uint8_t)(std::stof(str) * 255);

		//read blue in file
		str = line.substr(line.find("}") - 1);
		color.b = (uint8_t)(std::stof(str) * 255);

		color.a = 255;
		
		return stream;
	}
}