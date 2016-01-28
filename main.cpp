#include <SFML\Audio.hpp>
#include "Game.h"
#include "GameStart.h"
#include "CharGen.h"

int main(){
	srand(time(NULL));
	Game game;

	game.PushState(new GameStart(&game));
	game.GameLoop();

	return 0;
}