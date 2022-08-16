#include "AudioComponent.h"

namespace gre
{
	void gre::AudioComponent::Update()
	{

	}

	void AudioComponent::play()
	{
		g_audioSystem.PlayAudio(m_soundName, m_loop);

	}

	void AudioComponent::stop()
	{
	}

}
