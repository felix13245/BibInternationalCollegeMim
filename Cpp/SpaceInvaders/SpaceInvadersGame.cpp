#include "stdafx.h"
#include "SpaceInvadersGame.h"

using namespace CppGameEngine;

SpaceInvadersGame::SpaceInvadersGame() : Game("Space Invaders")
{
	int enemyNumber = 9;
	background = std::make_shared<Sprite>(std::make_shared<Texture>("Background.png"), 0, 0, 1.0f, 720.0f / 1280.0f);
	ship = std::make_shared<Sprite>(std::make_shared<Texture>("player_ship.png"), 0.5 - 0.07 / 2, 0.1 - 0.07 / 2, 0.07, 0.07);
	enemyTexture = std::make_shared<Texture>("spacecraft.png");
	missileTexture = std::make_shared<Texture>("player_ship.png");

	for (float y = 0.9f; y > 0.5f; y -= 0.13f)
		for (int i = 1; i < enemyNumber; i++)
		{
			enemies.push_back(std::make_shared<Sprite>(enemyTexture, 0.05 + i * 0.1 - 0.05 / 2, y, 0.05, 0.05));
		}
}

void SpaceInvadersGame::PlayGame()
{
	Run([&]()
	{
		ControlShip();
		MoveEnemies();
		MoveMissiles();
		background->Draw();
		ship->Draw();
		for (auto enemy : enemies)
		{
			enemy->Draw(enemiesPositionX, enemiesPositionY);
		}
		for (auto missile : missiles)
		{
			missile->Draw();
		}
	});
}
void SpaceInvadersGame::ControlShip()
{
	const float movementPerSecond = 1.0f / 2.5f;
	float movementPerFrame = movementPerSecond * GetTimeDelta();

	if (leftPressed && ship->GetXPos() >= 0.05 - ship->GetWidth() / 2)
		ship->SetXPos(ship->GetXPos() - movementPerFrame);
	if (rightPressed && ship->GetXPos() <= 0.95 - ship->GetWidth() / 2)
		ship->SetXPos(ship->GetXPos() + movementPerFrame);
	if (spacePressed)
		FireMissile();
}
void SpaceInvadersGame::FireMissile()
{
	missiles.push_back(std::make_shared<Sprite>(missileTexture, ship->GetXPos() + ship->GetWidth() / 2 - 0.01 / 2, ship->GetYPos() + ship->GetHeight() - 0.01 / 2, 0.01, 0.01));
}
void SpaceInvadersGame::MoveMissiles()
{
	const float movementPerSecond = 0.2;
	float movementPerFrame = movementPerSecond * GetTimeDelta();
	for (auto missile : missiles) {
		float currentX = missile->GetXPos();
		float currentY = missile->GetYPos() + movementPerFrame;
		missile->SetYPos(currentY);
		for (auto enemy : enemies) {
			if (currentX > enemy->GetXPos() + enemiesPositionX &&
				currentX < enemy->GetXPos() + enemiesPositionX + enemy->GetWidth() &&
				currentY > enemy->GetYPos() &&
				currentY < enemy->GetYPos() + enemy->GetHeight())
				enemy->SetYPos(-1);
		}
	}
}
void SpaceInvadersGame::MoveEnemies()
{
	const float movementPerSecond = 0.1234f;
	float movementPerFrame = movementPerSecond * GetTimeDelta();

	if (enemiesPositionX > 0.1f)
		enemiesMoveRight = false;
	if (enemiesPositionX < -0.1f)
		enemiesMoveRight = true;
	enemiesPositionX += (enemiesMoveRight ? 1 : -1) * movementPerFrame;

	/*float pos = enemies[0]->GetXPos();
	WCHAR buffer[128];
	swprintf(buffer, 128, L"pos=%f\n", pos);
	OutputDebugString(buffer);*/
}