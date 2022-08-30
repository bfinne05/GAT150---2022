#include "Matrix3x3.h"

namespace gre
{
	// 1 0 0
	// 0 1 0
	// 0 0 1

	const Matrix3x3 Matrix3x3::identity
	(
		Vector3(1, 0, 0),
		Vector3(0, 1, 0),
		Vector3(0, 0, 1)
	);
		const Matrix3x3 Matrix3x3::zero
	(
		Vector3(0, 0, 0),
		Vector3(0, 0, 0),
		Vector3(0, 0, 0)
	);

	inline Vector2 Matrix3x3::GetTranslation() const
	{
			// 1 0 x 
			// 0 1 y 
			// 0 0 1 

			return { rows[0][2], rows[1][2] };
	}

	inline float Matrix3x3::GetRotation() const
	{
		// cos -sin 0 
		// sin  cos 0 
		//  0    0  1 

		// y = sin(angle) = rows[1][0] 
		// x = cos(angle) = rows[0][0] 

		return std::atan2(rows[1][0], rows[0][0]);
	}

	inline Vector2 Matrix3x3::GetScale() const
	{
		Vector2 x = { rows[0][0], rows[0][1] };
		Vector2 y = { rows[1][0], rows[1][1] };

		return { x.Length(), y.Length() };
	}
}