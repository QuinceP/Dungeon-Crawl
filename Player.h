#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Character.h"


class Player:public Character{
private:
	std::vector<Item> inventory;
	int sp; //silver pieces

	std::string alignment;

	int level;
	int XP;
	int XPtoNextLevel;

	std::string CombatAction;

public:

	Player RollBaseStats(Player player);
	Player DetermineAC(Player player);
	Player DetermineAB(Player player);
	Player DetermineSavingThrows(Player player);
	Player DetermineHP(Player player);

	//getters, setters
	void setSP(int money);
	int getSP();

	void setAlignment(std::string a);
	std::string getAlignment();

	void setLevel(int l);
	int getLevel();

	void setXP(int exp);
	int getXP();

	void setXPtoNextLevel(int exp);
	int getXPtoNextLevel();

	void setCombatAction(std::string ca);
	std::string getCombatAction();

	void addToInventory(Item item);

	void equipWeapon(Weapon w);

	Player();
};
#endif

