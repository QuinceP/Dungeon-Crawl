#pragma once
#ifndef GAME_H
#define GAME_H

#include <stack>

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>



//forward declare gamestate class
class GameState;

//This is the basic engine of the game.
class Game{
public:
	sf::RenderWindow window;			//the window to which everything is drawn to

	std::stack<GameState*> states;		//Game states are battles, menu screen, character creation screen, etc. This is the stack of states.
										//the top state is the one shown to the player.

	void ChangeState(GameState* state);	//Change the current state
	void PushState(GameState* state);	//Push a state to the top of the state stack
	void PopState();					//Pop a lstate off the top of the stack
	void GameLoop();					//The main loop of the game
	GameState* TopState();				//retreives the top state of the game

	Game();								//constructor

	

};

#endif /* GAME_H */