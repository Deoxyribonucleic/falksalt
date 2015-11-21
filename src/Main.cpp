#include <iostream>

#include "game/Game.hpp"

int main(int argc, char** argv)
{
	falksalt::Game game(&argc, argv);
	game.start();
}

