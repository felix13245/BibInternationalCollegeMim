#include "stdafx.h"
#include "SpaceInvaders.h"
#include <../glfw-3.2.1.bin.WIN64/include/GLFW/glfw3.h>
#include "Game.h"
using namespace CppGameEngine;
FILE _iob[] = { *stdin, *stdout, *stderr };
extern "C" FILE * __cdecl __iob_func(void)
{
	return _iob;
}

class SpaceInvadersGame : public Game
{
	public:
		SpaceInvadersGame() : Game("Space Invaders") 
		{
			int enemyNumber = 10;
			background = std::make_shared<Sprite>(std::make_shared<Texture>("Background.png"), 0, 0, 1.0f, 720.0f/1280.0f);
			ship = std::make_shared<Sprite>(std::make_shared<Texture>("player_ship.png"), 0.5, 0, 0.1, 0.1);
			enemyTexture = std::make_shared<Texture>("spacecraft.png");
			for (int i = 0; i < enemyNumber; i++)
			{
				enemies.push_back(std::make_shared<Sprite>(enemyTexture, -0.9 + i * 0.2, 0.8, 0.08, 0.08));
			}
		}
		void PlayGame()
		{
			Run([&]() {
				background->Draw();
				ship->Draw();
				for (auto enemy : enemies)
				{
					enemy->Draw();
				}
			});
		}
	private:
		std::shared_ptr<Sprite> background;
		std::shared_ptr<Sprite> ship;
		std::vector<std::shared_ptr<Sprite>> enemies;
		std::shared_ptr<Texture> enemyTexture;
};

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	auto game = new SpaceInvadersGame();
	game->PlayGame();
	return 0;
}
