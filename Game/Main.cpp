#include "Engine.h"
#include "BGame.h"
#include <iostream>

int main()

{

	gre::InitializeMemory();
	gre::setFilePath("../Assets");



	//initialize systems
	gre::g_renderer.Initialize();
	gre::g_inputSystem.Initialize();
	gre::g_audioSystem.Initialize();
	gre::g_resources.Initialize();
	gre::g_physicsSystem.Initialize();
	gre::g_eventManager.Initialize();

	gre::Engine::Instance().Register();


	//create window
	gre::g_renderer.CreateWindow("Neumont", 800, 600);
	gre::g_renderer.setClearColor(gre::Color{ 0,0,0,255 });
	
	//create game
	std::unique_ptr<BGame> game = std::make_unique<BGame>();
	game->Initialize();

	
	
		
		bool quit = false;
		while (!quit)
		{
			//update
			gre::g_time.Tick();
			gre::g_inputSystem.Update();
			gre::g_audioSystem.Update();
			gre::g_physicsSystem.Update();
			gre::g_eventManager.Update();

			if (gre::g_inputSystem.GetKeyState(gre::key_escape) == gre::InputSystem::KeyState::Pressed) quit = true;
			//spawn enemies
		
			//update scene
			game->Update();

			//render
			gre::g_renderer.BeginFrame();

			game->Draw(gre::g_renderer);
			
			

			gre::g_renderer.EndFrame();
		}
		game->Shutdown();
		//game->reset();
		gre::Factory::Instance().Shutdown();

	gre::g_resources.ShutDown();
	
	gre::g_physicsSystem.Shutdown();
	gre::g_renderer.Shutdown();
	gre::g_eventManager.Shutdown();
	gre::g_audioSystem.Shutdown();
	//gre::g_inputSystem.Shutdown();
}