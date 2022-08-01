#pragma once
#include"Renderer.h"
#include<vector>
#include <string>

namespace gre
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<gre::Vector2>& points,const gre::Color& color) : 
			m_points{points}, 
			m_color{color}
		{
		}
		Model(const std::string& filename);
		~Model() = default;


		void Draw(Renderer& renderer,const Vector2& position,float angle, float scale = 1);

		void Load(std::string filename);
		float CalculateRadius();

		float getRadius() { return m_radius; }

	private:
		gre::Color m_color{ 0,0,0,0 };
		std::vector<gre::Vector2> m_points;

		float m_radius = 0;
	};
}