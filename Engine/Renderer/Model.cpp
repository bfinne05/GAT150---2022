#include "Model.h"
#include "Core/File.h"
#include "Core/Logger.h"
#include "Math/Transform.h"
#include <sstream>
#include <iostream>
#include <cstdarg>

namespace gre
{
	Model::Model(const std::string& filename)
	{
		Load(filename);
		m_radius = CalculateRadius();
	}
	//bool Model::Create(const std::string& filename, void* data)
	//{
	//	if (!Load(filename))
	//	{
	//		LOG("Error could not read file %s", filename.c_str());
	//		return false;
	//	}
	//	return true;
	//}

	bool Model::Create(std::string filename, ...)
	{
		// create texture (returns true/false if successful) 
		return Load(filename);
	}

	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, const Vector2& scale)
	{
	
		//draw model
		for (int i = 0; i < m_points.size() - 1; i++)
		{
			gre::Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
			gre::Vector2 p2 = Vector2::Rotate((m_points[i + 1] * scale), angle) + position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}

	void Model::Draw(Renderer& renderer, const Transform& transform)
	{
		//draw model

		Matrix3x3 mx = transform.matrix;

		//if (m_points.size() == 0) return;

		for (int i = 0; i < m_points.size() - 1; i++)
		{
			gre::Vector2 p1 = mx * m_points[i];
			gre::Vector2 p2 = mx * m_points[i + 1];

			renderer.DrawLine(p1, p2, m_color);
		}
	}

	bool Model::Load(const std::string& filename)
	{
		std::string buffer;

		if (!gre::ReadFile(filename, buffer))
		{
			LOG("Error could not read file %s", filename.c_str());
			return false;
		}

		//read color
		std::istringstream stream(buffer);
		stream >> m_color;

		//read line
		std::string line;
		std::getline(stream, line);
		size_t numPoints = stoi(line); // string to int

		//read model points
		for (size_t i = 0; i < numPoints; i++)
		{
			Vector2 point;

			stream >> point;
			m_points.push_back(point);
		}
		return true;
	}

	float Model::CalculateRadius()
	{
		float radius = 0;

		//find the largest legnth (radius)
		for (auto point : m_points)
		{
			if (point.Length() > radius) radius = point.Length();

		}

		return radius;
	}

}
