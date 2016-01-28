#pragma once
#ifndef GAMESTART_H
#define GAMESTART_H
#include <SFML\Audio.hpp>
#include "Game.h"
#include "GameState.h"

class GameStart :public GameState{
public:

	void Draw(const float t);
	void Update(const float t);
	void HandleInput();
	void LoadWidgets(tgui::Gui& gui);
	void StopMusic();

	GameStart(Game* game);
	sf::Music bgm;

private:
	tgui::Gui gui;
};


#endif /*GAME_H*/