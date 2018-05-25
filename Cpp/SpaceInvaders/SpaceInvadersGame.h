#pragma once
#include <../glfw-3.2.1.bin.WIN64/include/GLFW/glfw3.h>
#include "Game.h"

using namespace CppGameEngine;

class SpaceInvadersGame : public Game
{
public:
	SpaceInvadersGame();
	void PlayGame();
	void MoveShip();

private:
	std::shared_ptr<Sprite> background;
	std::shared_ptr<Sprite> ship;
	std::vector<std::shared_ptr<Sprite>> enemies;
	std::shared_ptr<Texture> enemyTexture;
	float shipPosition;
};