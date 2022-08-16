#pragma once
#include "FrameWork/Component.h"
#include "Engine.h"
namespace gre
{

	class AudioComponent : public Component
	{

	public:
		AudioComponent() = default;

		void Update();

		void play();

		void stop();

		std::string m_soundName;
	private:
		bool m_playOnAwake = false;
		bool m_loop = false;
		float volume = 1;
		float m_pitch;
	};
}