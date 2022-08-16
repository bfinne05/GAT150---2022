#pragma once
#include"Renderer.h"
#include<vector>
#include <string>
#include "Resource/Resource.h"

namespace gre
{
	class Model : public Resource
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

		//bool Create(const std::string& filename, void* data = nullptr) override;
		bool Create(std::string filename, ...) override;

		void Draw(Renderer& renderer,const Vector2& position,float angle, const Vector2& scale);
		void Draw(Renderer& renderer, const Transform& transform);

		bool Load(const std::string& filename);
		float CalculateRadius();

		float getRadius() { return m_radius; }

	private:
		gre::Color m_color{ 0,0,0,0 };
		std::vector<gre::Vector2> m_points;

		float m_radius = 0;
	};
}