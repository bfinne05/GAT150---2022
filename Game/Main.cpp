#include "Engine.h"
#include <iostream>

int main()
{
	gre::InitializeMemory();
	gre::setFilePath("../Assets");

	gre::g_renderer.Initialize();
	gre::g_inputSystem.Initialize();
	gre::g_audioSystem.Initialize();

	//create window
	gre::g_renderer.CreateWindow("Neumont", 800, 600);
	gre::g_renderer.setClearColor(gre::Color{ 0,0,0,255 });

	//create image
	std::shared_ptr<gre::Texture> texture = std::make_shared<gre::Texture>();
	texture->Create(gre::g_renderer, "pikachu.png");
	
		//create game
		
		bool quit = false;
		while (!quit)
		{
			//update
			gre::g_time.Tick();
			gre::g_inputSystem.Update();
			gre::g_audioSystem.Update();

			if (gre::g_inputSystem.GetKeyState(gre::key_escape) == gre::InputSystem::KeyState::Pressed) quit = true;
			//spawn enemies

		


			//render
			gre::g_renderer.BeginFrame();

			gre::g_renderer.Draw(texture, { 300, 300}, 0);

			gre::g_renderer.EndFrame();
		}

	

	gre::g_renderer.Shutdown();
	gre::g_audioSystem.Shutdown();
}