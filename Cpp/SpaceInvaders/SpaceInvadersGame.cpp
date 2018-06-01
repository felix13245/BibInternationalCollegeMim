#include "stdafx.h"
#include "SpaceInvadersGame.h"
#include "Vector2D.h"

using namespace CppGameEngine;

SpaceInvadersGame::SpaceInvadersGame() : Game("Space Invaders")
{
	//------------------------------------------------------------------------------x, y, width, height
	background = std::make_shared<Sprite>(std::make_shared<Texture>("Background.png"), 0.0f, 0.0f, 1.0f, 720.0f / 1280.0f);
	ship = std::make_shared<Sprite>(std::make_shared<Texture>("Ship.png"), 0.5f - 0.1f / 2, 0.03f, 0.1f, 0.07f);

	auto enemyTexture = std::make_shared<Texture>("Enemy.png");
	missileTexture = std::make_shared<Texture>("Missile.png");

	for (float y = 0.87f; y > 0.5f; y -= 0.13f)
	for (int i = 1; i < 9; i++)
		enemies.push_back(std::make_shared<Sprite>(enemyTexture, 0.01f + i * 0.1f, y, 0.06f, 0.04f));
}

void SpaceInvadersGame::PlayGame()
{
	Run([&]()
	{
		ControllShip();
		MoveEnemies();
		MoveMissiles();

		background->Draw();
		ship->Draw();
		for (auto enemy : enemies)
			enemy->Draw(enemiesPositionX);
		for (auto missile : missiles)
			missile->Draw();
	});
}

#define COOLDOWN 0.5

void SpaceInvadersGame::ControllShip()
{
	const float movementPerSecond = 0.5;
	float movementPerFrame = movementPerSecond * GetTimeDelta();
	if (leftPressed && ship->GetPosition().X >= 0.05f - ship->GetWidth() / 2)
		ship->SetPosX(ship->GetPosition().X - movementPerFrame);
	if (rightPressed && ship->GetPosition().X <= 0.95f - ship->GetWidth() / 2)
		ship->SetPosX(ship->GetPosition().X + movementPerFrame);
	elapsedTime += GetTimeDelta();
	if (spacePressed && elapsedTime >= COOLDOWN)
	{
		FireMissile();
		elapsedTime = 0;
	}
}

void SpaceInvadersGame::FireMissile()
{
	missiles.push_back(std::make_shared<Sprite>(missileTexture,
		ship->GetPosition().X+ship->GetWidth()/2, ship->GetPosition().Y+ship->GetHeight(),
		0.03f, 0.03f));
}

void SpaceInvadersGame::MoveEnemies()
{
	const float movementPerSecond = 0.1234f;
	float movementPerFrame = movementPerSecond * GetTimeDelta();
	if (enemiesPositionX > 0.1f)
		enemiesMoveRight = false;
	else if (enemiesPositionX < -0.1f)
		enemiesMoveRight = true;
	enemiesPositionX += (enemiesMoveRight ? 1:-1)*movementPerFrame;
}

void SpaceInvadersGame::MoveMissiles()
{
	if (missiles.size() == 0)
		return;
	const float movementPerSecond = 1.2f;
	float movementPerFrame = movementPerSecond * GetTimeDelta();
	float missileRadius = missiles[0]->GetWidth() / 2;
	float enemyRadius = enemies[0]->GetWidth() / 4;
	float squaredMinimumDistance =
		(missileRadius + enemyRadius) * (missileRadius + enemyRadius);
	for (auto missile : missiles) {
		Vector2D current = missile->GetPosition() + Vector2D(0, movementPerFrame);
		missile->SetPosY(current.Y);
		for (auto enemy : enemies) {
			if (current.DistanceToSquared(enemy->GetPosition() + Vector2D(enemiesPositionX, 0)) <
				squaredMinimumDistance) {
				enemy->SetPosY(1);
				missile->SetPosY(1);
			}
		}
	}
}