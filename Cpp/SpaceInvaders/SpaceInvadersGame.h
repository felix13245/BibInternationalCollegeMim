#pragma once
#include <../glfw-3.2.1.bin.WIN64/include/GLFW/glfw3.h>
#include "Game.h"
#include "SpriteSheet.h"

using namespace CppGameEngine;

class SpaceInvadersGame : public Game
{
public:
	SpaceInvadersGame();
	void PlayGame();
	void ControlShip();
	void MoveEnemies();
	void FireMissile();
	void MoveMissiles();

private:
	std::shared_ptr<Sprite> background;
	std::shared_ptr<Sprite> ship;
	std::shared_ptr<SpriteSheet> explosion;
	std::vector<std::shared_ptr<Sprite>> enemies;
	std::vector<std::shared_ptr<Sprite>> missiles;
	std::shared_ptr<Texture> enemyTexture;
	std::shared_ptr<Texture> missileTexture;
	std::shared_ptr<Texture> explosionTexture;
	float shipPositionX;
	float shipPositionY;
	float enemiesPositionX;
	float enemiesPositionY;
	float timePassed;
	bool enemiesMoveRight;
};