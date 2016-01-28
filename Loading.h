#pragma once
#ifndef LOADING_H
#define LOADING_H
#include <SFML\Audio.hpp>
#include "Game.h"
#include "GameState.h"

class Loading :public GameState{
public:

	void Draw(const float t);
	void Update(const float t);
	void HandleInput();
	void LoadWidgets(tgui::Gui& gui);

	tgui::Picture::Ptr text;

	Loading(Game* game);
	

private:
	tgui::Gui gui;
};


#endif /*Loading_H*/