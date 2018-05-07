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
	SpaceInvadersGame() : Game("Space Invaders") {}
	void PlayGame() {}
};

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	auto game = new SpaceInvadersGame();
	auto texture = std::make_shared<Texture>("Background.png");
	game->Run([]() {
		glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0);
		glVertex2f(-1, -1);
		glColor3f(0, 1, 0);
		glVertex2f(1, -1);
		glColor3f(0, 0, 1);
		glVertex2f(0, 1);
		glEnd();
	});
	return 0;
}