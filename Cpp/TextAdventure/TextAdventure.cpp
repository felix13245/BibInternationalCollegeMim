// Visual C++ plugin (kostet Geld) ist aber Praktisch
#include "stdafx.h"
#include <iostream>
#define string const char*
#define output std::cout
#define input std::cin
#define lb "\r\n"

int main()
{
	string text = "Hallo. Bitte gib deinen Spielernamen ein. \r\n";
	char playerName[30];
	output << (text);
	input >> playerName;
	output << "Spielername: " << playerName << lb;
	output << "Du bist im Wald aufgewacht, dir ist schwindelig" << lb;
	output << "Was moechtest du tun? 1 fuer rechts gehen, 2 fuer links gehen." << lb;
	int option;
	do
	{
		input >> option;
		if (option < 1 || option > 2)
			output << "Ungueltige Eingabe, try again Saftsack." << lb;
		else
			break;
	} while (true);
	if (option == 1)
		output << "Du wurdest gefressen!" << lb << "Try again.";
	if (option == 2)
		output << "Du bist noch am Leben." << lb << "Wenn das Spiel weitergehen soll dann fuettere den Programmierer.";
	return 0;
}