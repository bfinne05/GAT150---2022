#pragma once
#include"Actor.h"
#include <list>
#include <memory>

namespace gre
{
	//forward declaration
	class Actor;
	class Renderer;
	class Game;

	class Scene
	{
	public:
		Scene() = default;
		~Scene() = default;

		Scene(Game* game) : m_game{ game } {}

		void Update();
		void Draw(Renderer& renderer);

		void Add(std::unique_ptr<Actor> actor);

	
		template<typename T>
		T* GetActor();


		Game* GetGame() { return m_game; }
	private:
		Game* m_game;
		std::list<std::unique_ptr<Actor>> m_actors;
	};

	template<typename T>
	inline T* Scene::GetActor()
	{
		//int i = 45;
		//float f = float(34) // 45 ->45.0f
		for (auto& actor : m_actors)
		{
			//T* result = dynamic_cast<T*>(actor.get())
				//if (result) return result;

		}
		return nullptr;
	}
}