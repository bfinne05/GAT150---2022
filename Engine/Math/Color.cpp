#include "Color.h"

namespace gre
{

	static const Color white;


	std::istream& operator >> (std::istream& stream, Color& color)
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
		str = line.substr(line.find(",") + 1);
		color.b = (uint8_t)(std::stof(str) * 255);

		color.a = 255;

		return stream;
	}

	std::ostream& operator<<(std::ostream& stream, const Color& color)
	{
		stream << (int)color.r << " " << (int)color.g << " " << (int)color.b << " " << (int)color.a;

		return stream;
	}
}