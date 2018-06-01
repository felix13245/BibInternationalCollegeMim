#pragma once
#include <GLFW/glfw3.h>
#include "Game.h"
#include "SpriteSheet.h"
using namespace CppGameEngine;

class SpaceInvadersGame : public Game
{
public:
	SpaceInvadersGame();
	void PlayGame();
	void ControllShip();
	void MoveEnemies();
	void MoveMissiles();
	void FireMissile();

private:
	std::shared_ptr<Sprite> background;
	std::shared_ptr<Sprite> ship;
	std::vector<std::shared_ptr<Sprite>> enemies;
	std::shared_ptr<Texture> missileTexture;
	std::shared_ptr<Texture> explosionTexture;
	std::vector<std::shared_ptr<Sprite>> missiles;
	std::vector<std::shared_ptr<SpriteSheet>> explosions;
	float enemiesPositionX;
	bool enemiesMoveRight;
	float elapsedTime;
};