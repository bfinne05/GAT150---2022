#pragma once
#include"Vector2.h"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "Math/MathUtils.h"
namespace gre
{
	struct Transform
	{
		Vector2 position;
		float rotation{0};
		Vector2 scale{ 1, 1 };

		Matrix3x3 matrix;

		void Update()
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreatetRotation(Math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreatetTranslation(position);

			matrix = (mxTranslation * mxRotation * mxScale);
		}


		void Update(const Matrix3x3& parent)
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreatetRotation(Math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreatetTranslation(position);

			matrix = (mxTranslation * mxRotation * mxScale);
			matrix = parent * matrix;
		}

		operator Matrix3x3 () const
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreatetRotation(Math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreatetTranslation(position);
			return (mxTranslation * mxRotation * mxScale);
		}
	};
}