#pragma once
#include "FrameWork/Game.h"
#include "FrameWork/Event.h"


class BGame : public gre::Game, public gre::INotify
{
public:
	enum gameState
	{
		TitleScreen,
		StartLevel,
		game,
		playerDead,
		gameOver
	};

	// Inherited via Game
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(gre::Renderer& renderer) override;
	virtual void OnNotify(const gre::Event& event) override;

	void OnAddPoints(const gre::Event& event);
	void OnPlayerDead(const gre::Event& event);
	void EVENT_DROP(const gre::Event& event);

private:
	gameState m_gameState = gameState::TitleScreen;
	float m_stateTimer = 0;
	float m_SpawnTimer = 7;
	int m_lives = 3;

	// Inherited via INotify
};