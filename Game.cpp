#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <TGUI/TGUI.hpp>
#define THEME_CONFIG_FILE "TGUI/widgets/Black.conf"

#include "Game.h"
#include "GameStart.h"





void Game::ChangeState(GameState* state){
	if (states.empty()){
		PopState();
	}
	PushState(state);
}
void Game::PushState(GameState* state){

	states.push(state);
}
void Game::PopState(){
	delete states.top();
	states.pop();
}

GameState* Game::TopState(){
	if (states.empty()){
		return nullptr; }
	return this->states.top();
}

void Game::GameLoop(){
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float t = elapsed.asSeconds();

		if (TopState() == nullptr){
			continue;
		}
		TopState()->HandleInput();
		//TopState()->Update(t);
		window.clear();
		TopState()->Draw(t);

		window.display();
	}
}

Game::Game(){
	window.create(sf::VideoMode(1024, 768), "Dungeon Crawl");
	window.setFramerateLimit(60);
}



