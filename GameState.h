#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"


class GameState{
public:

	Game* game;

	virtual void Draw(const float t) = 0;
	virtual void Update(const float t) = 0;
	virtual void HandleInput() = 0;
	virtual void LoadWidgets(tgui::Gui& gui) = 0;
};

#endif /*GAMESTATE_H*/