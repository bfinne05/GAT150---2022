#pragma once
#include "FrameWork/Component.h"
#include "Audio/AudioChannel.h"

namespace gre
{

	class AudioComponent : public Component
	{

	public:
		AudioComponent() = default;
		~AudioComponent();

		CLASS_DECLARATION(AudioComponent)

		void Initialize() override;
		void Update();

		void Play();

		void Stop();

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		std::string m_soundName;

	public:
		AudioChannel m_channel;

		// !! your names do not have to be the same 
		std::string sound_name;
		float volume = 1;
		float pitch = 1;
		bool play_on_start = false;
		bool loop = false;

	};
}