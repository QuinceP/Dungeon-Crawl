#pragma once
#ifndef CHARGEN_H
#define CHARGEN_H
#include <SFML\Audio.hpp>
#include "Game.h"
#include "GameState.h"
#include "Player.h"

class CharGen :public GameState{
public:

	std::string name;
	std::vector<std::string> names;

	void Draw(const float t);
	void Update(const float t);
	void HandleInput();
	void LoadWidgets(tgui::Gui& gui);
	void ShowStats();

	CharGen(Game* game);

	tgui::RadioButton::Ptr clericButton;
	tgui::RadioButton::Ptr fighterButton;
	tgui::RadioButton::Ptr magicuserButton;
	tgui::RadioButton::Ptr specialistButton;
	tgui::RadioButton::Ptr dwarfButton;
	tgui::RadioButton::Ptr elfButton;
	tgui::RadioButton::Ptr halflingButton;
	tgui::TextBox::Ptr statsBox;
	tgui::TextBox::Ptr savingBox;
	tgui::TextBox::Ptr abBox;
	tgui::TextBox::Ptr acBox;
	tgui::TextBox::Ptr textBox;
	tgui::Label::Ptr labelHP;

	sf::Music bgm;

private:
	tgui::Gui gui;
	Player player;
};

#endif /*CHARGEN_H*/