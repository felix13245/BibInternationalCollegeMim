#include "stdafx.h"
#include "SpaceInvadersGame.h"

using namespace CppGameEngine;

SpaceInvadersGame::SpaceInvadersGame() : Game("Space Invaders")
{
	//------------------------------------------------------------------------------x, y, width, height
	background = std::make_shared<Sprite>(std::make_shared<Texture>("Background.png"), 0.0f, 0.0f, 1.0f, 720.0f / 1280.0f);
	ship = std::make_shared<Sprite>(std::make_shared<Texture>("Ship.png"), 0.5f - 0.1f / 2, 0.03f, 0.1f, 0.07f);

	auto enemyTexture = std::make_shared<Texture>("Enemy.png");
	for (int i = 0; i < 10; i++)
		enemies.push_back(std::make_shared<Sprite>(enemyTexture, 0.01f + i * 0.1f, 0.87f, 0.08f, 0.05f));
}

void SpaceInvadersGame::PlayGame()
{
	Run([&]()
	{
		ControllShip();

		background->Draw();
		ship->Draw();
		for (auto enemy : enemies)
			enemy->Draw();
	});
}

void SpaceInvadersGame::ControllShip()
{
	if (leftPressed && ship->GetPosX() >= 0.05f - ship->GetWidth() / 2)
	{
		ship->SetPosX(ship->GetPosX() - 0.001f);
	}

	if (rightPressed && ship->GetPosX() <= 0.95f - ship->GetWidth() / 2)
	{
		ship->SetPosX(ship->GetPosX() + 0.001f);
	}
}

