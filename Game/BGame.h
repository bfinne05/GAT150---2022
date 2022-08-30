#pragma once
#include "FrameWork/Game.h"


class BGame : public gre::Game
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

	void OnAddPoints(const gre::Event& event);
	void OnPlayerDead(const gre::Event& event);

private:
	gameState m_gameState = gameState::TitleScreen;
	float m_stateTimer = 0;
	int m_lives = 3;
};