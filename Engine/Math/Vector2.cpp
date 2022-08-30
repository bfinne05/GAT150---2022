#include "Vector2.h"

namespace gre
{
	const Vector2 Vector2::one{ 1,1 };
	const Vector2 Vector2::zero{ 0,0 };
	const Vector2 Vector2::up{ 0,-1 };
	const Vector2 Vector2::down{ 0,1 };
	const Vector2 Vector2::left{ -1,0 };
	const Vector2 Vector2::right{ 1,0 };


	std::istream& operator >> (std::istream& stream, Vector2& v)
	{
		std::string line;
		std::getline(stream, line);

		// { ##, ## }
		std::string xs = line.substr(line.find("{") + 1, line.find(",") - line.find("{") - 1);
		v.x = std::stof(xs);

		std::string ys = line.substr(line.find(",") + 1, line.find(",") - line.find("}") - 1);
		v.y = std::stof(ys);

		return stream;
	}

	std::ostream& operator<<(std::ostream& stream, const Vector2& v)
	{
		stream << v.x << " " << v.y;

		return stream;
	}

	inline float Vector2::Dot(const Vector2& v)
	{
		return x * v.x + y * v.y;
	}

	inline float Vector2::GetAngleBetween(const Vector2& v)
	{
		return std::acos(Dot(v));
	}

	inline float Vector2::GetSignedAngleBetween(const Vector2& v)
	{
		float y = x * v.y - y * v.x; // perpendicular dot product 
		float x = x * v.x + y * v.y; // dor product 

		return std::atan2(y, x);
	}
}