#include "Engine.h"
#include "BGame.h"
#include "FrameWork/Event.h"
#include <iostream>


void BGame::Initialize()
{
	m_scene = std::make_unique<gre::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = {"Scenes/Prefabs.txt", "Scenes/Tilemap.txt" ,"Scenes/level.txt"};

	for (auto sceneName : sceneNames)
	{
		bool success = gre::json::Load(sceneName, document);
		if (!success)
		{
			LOG("could not load scene %s", sceneName);
			continue;
		}
		m_scene->Read(document);
	}
	m_scene->Initialize();

	gre::g_eventManager.Subscribe("Event Add Points", std::bind(&BGame::OnAddPoints, this, std::placeholders::_1));
}

void BGame::Shutdown()
{
	m_scene->RemoveAll();

}

void BGame::Update()
{
	m_scene->Update();

	switch (m_gameState)
	{
	case BGame::TitleScreen:
		if (gre::g_inputSystem.GetKeyState(gre::key_space) == gre::InputSystem::KeyState::Pressed)
		{
			m_scene->GetActorFromName("Title")->setActive(false);

			m_gameState = gameState::StartLevel;
		}
		break;
	case BGame::StartLevel:
		for (int i = 0; i < 10; i++)
		{
			auto actor = gre::Factory::Instance().Create<gre::Actor>("Coin");
			actor->m_transform.position = { gre::randomf(0,800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		m_gameState = gameState::game;
		break;
	case BGame::game:
		break;
	case BGame::playerDead:
		m_stateTimer -= gre::g_time.deltaTime;
		if (m_stateTimer <= 0)
		{
			m_gameState = (m_lives > 0) ? gameState::StartLevel : gameState::gameOver;
		}
		break;
	case BGame::gameOver:
		break;
	default:
		break;
	}
}

void BGame::Draw(gre::Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void BGame::OnAddPoints(const gre::Event& event)
{
	std::cout << event.name << std::endl;
	std::cout << GetScore() << std::endl;
}

void BGame::OnPlayerDead(const gre::Event& event)
{
	m_gameState = gameState::playerDead;
	m_lives--;
	m_stateTimer = 3.0f;
}
