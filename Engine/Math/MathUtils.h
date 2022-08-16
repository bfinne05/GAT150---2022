#pragma once

namespace Math
{
	constexpr float Pi = 3.14159265359f; // 180
	constexpr float TwoPi = 6.28318530718f; // 360
	constexpr float HalfPi = 1.57079632679f; // 90

	constexpr float DegToRad(float degrees)
	{
		return degrees * (Pi / 180);
	}

	constexpr float RadToDeg(float radians)
	{
		return radians * (180 / Pi);
	}

	inline int sqr(int v) { return v * v; };
	inline int half(int v) { return v / 2; };

}
