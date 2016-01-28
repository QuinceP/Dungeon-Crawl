#pragma once
#ifndef BATTLE_H
#define BATTLE_H
#include <SFML\Audio.hpp>
#include "Game.h"
#include "Character.h"
#include "Player.h"
#include "GameState.h"
#include "Monster.h"

class Battle :public GameState{
public:

	void Draw(const float t);
	void Update(const float t);
	void HandleInput();
	void LoadWidgets(tgui::Gui& gui);

	Battle(Game* game);
	Battle(Game* game, Player player, Monster monster);
	Player player;
	Monster monster;

	bool win;								//did the player win or lose the battle?
	bool battleover;
	bool playersTurn;
	int choice;


	void StatusScreen(std::string action, sf::Color color);  //the screen showing the detail of the battle, customized for the action currently being taken

	bool AttackHit(Character target);		//determine whether or not the attack hits, depending on the stats of the target
	int DetermineDmg(Character attacker);	//determine the damage output of the attacker

	//returns a message to display to the status screen and handles the attack
	std::string MonsterAttack();
	std::string PlayerAttack();

	void turn();							//handles the events that happen in a single turn

	bool TakeTurn(Player player);			//player's turn
	void TakeTurn(Monster monster);			//monster's turn


	void battle();							//handle entire battle. check win conditions

	tgui::ChatBox::Ptr eventBox;
	tgui::RadioButton::Ptr attack;
	tgui::RadioButton::Ptr parry;
	tgui::RadioButton::Ptr combataction;
	tgui::RadioButton::Ptr item;
	tgui::RadioButton::Ptr spell;
	tgui::RadioButton::Ptr equip;
	tgui::LoadingBar::Ptr playerHP;
	tgui::LoadingBar::Ptr enemyHP;
	tgui::Picture::Ptr enemy;
	tgui::Picture::Ptr you;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Music bgm;
	
	
	
	bool turnprinted;
	
private:
	tgui::Gui gui;
};

#endif /*BATTLE_H*/