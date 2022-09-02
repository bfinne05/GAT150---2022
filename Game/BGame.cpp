#include "Engine.h"
#include "Math/Random.h"
#include "BGame.h"
#include "FrameWork/Event.h"
#include "GameComponents/EnemyComponent.h"
#include <iostream>


void BGame::Initialize()
{
	REGISTER_CLASS(EnemyComponent);
	gre::g_audioSystem.AddAudio("sword", "audio/sword.wav");
	gre::g_audioSystem.AddAudio("music", "audio/epic.mp3");
	gre::g_audioSystem.AddAudio("destroy", "audio/enemy-destroyed.wav");
	gre::g_audioSystem.AddAudio("jump", "audio/jump.wav");

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

	gre::g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&BGame::OnAddPoints, this, std::placeholders::_1));
	gre::g_eventManager.Subscribe("EVENT_DROP", std::bind(&BGame::OnAddPoints, this, std::placeholders::_1));
	gre::g_eventManager.Subscribe("EVENT_PLAYER_DEAD", std::bind(&BGame::OnAddPoints, this, std::placeholders::_1));
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
		for (int i = 0; i < 10; i++)
		{
			auto actor = gre::Factory::Instance().Create<gre::Actor>("Ghost");
			actor->m_transform.position = { gre::randomf(0,800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		for (int i = 0; i < 1; i++)
		{
			auto actor = gre::Factory::Instance().Create<gre::Actor>("Dog");
			actor->m_transform.position = { gre::randomf(200,800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		m_gameState = gameState::game;
		break;
	case BGame::game:
	{
		if (m_SpawnTimer)
		{
			m_SpawnTimer -= gre::g_time.deltaTime;
			if (m_SpawnTimer <= 0)
			{
				for (int numEnemies = gre::random(1, 5); numEnemies > 0; numEnemies--)
				{
					auto actor = gre::Factory::Instance().Create<gre::Actor>("Ghost");
					actor->m_transform.position = { gre::randomf(0,800), 100.0f };
					actor->Initialize();

					m_scene->Add(std::move(actor));
				}
				for (int numEnemies = gre::random(1, 3); numEnemies > 0; numEnemies--)
				{
					auto actor = gre::Factory::Instance().Create<gre::Actor>("Dog");
					actor->m_transform.position = { gre::randomf(0,800), 100.0f };
					actor->Initialize();

					m_scene->Add(std::move(actor));
				}
				m_SpawnTimer = 7;
			}
		}
		//show score in game
		auto actor = m_scene->GetActorFromName("Score");
		auto component = actor->GetComponent<gre::TextComponent>();
		component->SetText(std::to_string(m_score));
		break;
	}
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
void BGame::EVENT_DROP(const gre::Event& event)
{
	int chance = gre::random(1, 6);
	std::cout << chance << std::endl;
	if (chance >= 3)
	{
		std::cout << "Coin Dropped" << std::endl;
		auto actor = gre::Factory::Instance().Create<gre::Actor>("Coin");
		actor->m_transform.position = { gre::randomf(0,800), 100.0f };
		actor->Initialize();

		m_scene->Add(std::move(actor));
	}
}


void BGame::OnNotify(const gre::Event& event)
{
	if (event.name == "EVENT_ADD_POINTS")
	{
		AddPoints(std::get<int>(event.data));
	}
	if (event.name == "EVENT_PLAYER_DEAD")
	{
		m_gameState = gameState::playerDead;
		m_lives--;
		m_stateTimer = 3;
	}
	if (event.name == "EVENT_DROP")
	{
		int chance = gre::random(1, 6);
		std::cout << chance << std::endl;
		if (chance >= 3)
		{
			std::cout << "Coin Dropped" << std::endl;
			auto actor = gre::Factory::Instance().Create<gre::Actor>("Coin");
			actor->m_transform.position = { gre::randomf(0,800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
	}
}
