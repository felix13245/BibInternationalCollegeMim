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
	explosionTexture = std::make_shared<Texture>("explosion.png");
	explosion = std::make_shared<SpriteSheet>(explosionTexture,
		0.2f, 0.3f, 0.1f, 0.1f, 47, 1);

	for (float y = 0.9f; y > 0.5f; y -= 0.13f)
		for (int i = 1; i < enemyNumber; i++)
		{
			enemies.push_back(std::make_shared<Sprite>(enemyTexture, 0.05 + i * 0.1 - 0.05 / 2, y, 0.05, 0.05));
		}
	shipPositionX = 0.f;
	shipPositionY = 0.f;
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

#define SHOOTINGDELAY 0.5

void SpaceInvadersGame::ControlShip()
{
	timePassed = timePassed + GetTimeDelta();
	const float movementPerSecond = 1.0f / 2.5f;
	float movementPerFrame = movementPerSecond * GetTimeDelta();

	if (leftPressed && ship->GetXPos() >= 0.05 - ship->GetWidth() / 2)
		ship->SetXPos(ship->GetXPos() - movementPerFrame);
	if (rightPressed && ship->GetXPos() <= 0.95 - ship->GetWidth() / 2)
		ship->SetXPos(ship->GetXPos() + movementPerFrame);
	if (spacePressed && timePassed >= SHOOTINGDELAY)
	{
		FireMissile();
		timePassed = 0.f;
	}
}
void SpaceInvadersGame::FireMissile()
{
	missiles.push_back(std::make_shared<Sprite>(missileTexture, ship->GetXPos() + ship->GetWidth() / 2 - 0.01 / 2, ship->GetYPos() + ship->GetHeight() - 0.01 / 2, 0.01, 0.01));
}
void SpaceInvadersGame::MoveMissiles()
{
	if (missiles.size() == 0)
		return;
	const float movementPerSecond = 0.2;
	float movementPerFrame = movementPerSecond * GetTimeDelta();
	float missileRadius = missiles[0]->GetWidth() / 2;
	float enemyRadius = enemies[0]->GetWidth() / 2;
	float squaredMinimumDistance = (missileRadius + enemyRadius) * (missileRadius + enemyRadius);
	for (auto missile : missiles) {
		Vector2D current = missile->getPosition() + Vector2D(0, movementPerFrame);
		missile->setPosition(current);
		for (auto enemy : enemies)
		{
			if (current.DistanceToSquared(enemy->getPosition() + Vector2D(enemiesPositionX, 0) + Vector2D(enemy->GetWidth() / 4, 0)) < squaredMinimumDistance)
			{
				explosion->Draw(enemy->GetXPos(), enemy->GetYPos());
				enemy->SetYPos(-1);
				missile->SetYPos(1);
			}
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