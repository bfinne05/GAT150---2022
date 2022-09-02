#pragma once 
#include "FrameWork/Component.h"

namespace FMOD
{
	// !! forward declare FMOD Channel 
	class Channel;
}

namespace gre
{
	class AudioChannel 
	{
	public:
		AudioChannel() = default;
		AudioChannel(FMOD::Channel* channel) { m_channel = channel; }// !! set m_channel 

		bool IsPlaying();
		void Stop();

		// !! create SetPitch/GetPitch (takes float, returns float) 
		void SetPitch(float pitch);
		float GetPitch();
		// !! create SetVolume/GetVolume (takes float, returns float) 
		void SetVolume(float volume);
		float GetVolume();

	private:
		FMOD::Channel* m_channel = nullptr;
	};
}