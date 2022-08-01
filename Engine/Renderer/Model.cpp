#include "Model.h"
#include "../Core/File.h"
#include <sstream>
#include <iostream>

namespace gre
{
	Model::Model(const std::string& filename)
	{
		Load(filename);
		m_radius = CalculateRadius();
	}
	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, float scale)
	{
	
		//draw model
		for (int i = 0; i < m_points.size() - 1; i++)
		{
			gre::Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
			gre::Vector2 p2 = Vector2::Rotate((m_points[i + 1] * scale), angle) + position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}

	void Model::Load(std::string filename)
	{
		std::string buffer;

		gre::ReadFile(filename, buffer);

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
