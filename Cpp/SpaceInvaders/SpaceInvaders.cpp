#include "stdafx.h"
#include "SpaceInvaders.h"
#include <GLFW/glfw3.h>
#include "Game.h"
#include "Texture.h"
using namespace CppGameEngine;
FILE _iob[] = { *stdin, *stdout, *stderr };

extern "C" FILE * __cdecl __iob_func(void)
{
	return _iob;
}

class SpaceInvadersGame : public Game {
public:
	SpaceInvadersGame() : Game("Space Invaders")
	{
		background = std::make_shared<Sprite>(std::make_shared<Texture>("Background.png"),
			0.0f, 0.0f, 1.0f, 720.0f/1280.0f);
		ship = std::make_shared<Sprite>(std::make_shared<Texture>("Ship.png"),
			0.0f, -0.7f, 0.1f, 0.1f);
		auto enemyTexture = std::make_shared<Texture>("Enemy.png");
		for (int i=0; i<10; i++)
			enemies.push_back(std::make_shared<Sprite>(enemyTexture, -0.9f+i*0.2f, 0.8f, 0.08f, 0.08f));
	}

	void PlayGame() {
		Run([&]() {
			background->Draw();
			ship->Draw();
			//foreach (var enemy in enemies)
			for (auto enemy : enemies)
				enemy->Draw();
		});
	}
private:
	std::shared_ptr<Sprite> background;
	std::shared_ptr<Sprite> ship;
	std::vector<std::shared_ptr<Sprite>> enemies;
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
