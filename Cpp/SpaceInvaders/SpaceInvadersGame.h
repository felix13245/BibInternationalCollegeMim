#pragma once
#include <../glfw-3.2.1.bin.WIN64/include/GLFW/glfw3.h>
#include "Game.h"

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
	std::vector<std::shared_ptr<Sprite>> enemies;
	std::vector<std::shared_ptr<Sprite>> missiles;
	std::shared_ptr<Texture> enemyTexture;
	std::shared_ptr<Texture> missileTexture;
	float shipPosition;
	float enemiesPositionX;
	float enemiesPositionY;
	bool enemiesMoveRight;
};