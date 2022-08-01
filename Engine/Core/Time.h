#pragma once
#include <chrono>
namespace gre 
{
	class Time
	{
	private:
		using clock = std::chrono::high_resolution_clock;
		using clock_duration = clock::duration;
		using clock_rep = clock::rep;

	public:
		Time() : 
			m_startTimePoint{ clock::now() },
			m_frameTimePoint{ clock::now() } 
		{}
		~Time() = default;
		void Tick();
		void Reset() { m_startTimePoint = clock::now(); }
	public:
		float deltaTime = 0;
		float time = 0;

	private:
		clock::time_point m_startTimePoint; // start of the application
		clock::time_point m_frameTimePoint; // time point at the start of the game

	};
}