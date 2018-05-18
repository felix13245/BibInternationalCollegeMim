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
			background = std::make_shared<Sprite>(std::make_shared<Texture>("Background.png"), 0, 0, 1, 0.5);
			ship = std::make_shared<Sprite>(std::make_shared<Texture>("Player_Ship.png"), 0, -0.8, 0.1, 0.1);
			enemy = std::make_shared<Sprite>(std::make_shared<Texture>("Spacecraft.png"), 0, 0.8, 0.1, 0.1);
		}
		void PlayGame()
		{
			Run([&]() {
				background->Draw();
				ship->Draw();
				enemy->Draw();
			});
		}
	private:
		std::shared_ptr<Sprite> background;
		std::shared_ptr<Sprite> ship;
		std::shared_ptr<Sprite> enemy;
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
