#include "stdafx.h"
#include "SpaceInvadersGame.h"

SpaceInvadersGame::SpaceInvadersGame() : Game("Space Invaders")
{
	background = std::make_shared<Sprite>(std::make_shared<Texture>("Background.png"),
		0.0f, 0.0f, 1.0f, 720.0f / 1280.0f);
	ship = std::make_shared<Sprite>(std::make_shared<Texture>("Ship.png"),
		0.5f - 0.07f / 2, 0.1f - 0.07f / 2, 0.07f, 0.07f);
	auto enemyTexture = std::make_shared<Texture>("Enemy.png");
	for (int i = 0; i < 10; i++)
		enemies.push_back(std::make_shared<Sprite>(enemyTexture,
			0.05f + i * 0.1f - 0.04f / 2, 0.9f - 0.04f / 2, 0.04f, 0.04f));
}

void SpaceInvadersGame::PlayGame() {
	Run([&]() {
		background->Draw();
		ship->Draw();
		for (auto enemy : enemies)
			enemy->Draw();
	});
}