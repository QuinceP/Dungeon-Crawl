#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"


//basic struct for base stats with their modifiers
struct Stat{
private:
	std::string type;
	int value;
	int modifier;

public:
	void setType(std::string t);
	std::string getType();
	void setValue(int val);
	int getValue();
	void setModifier(int mod);
	int getModifier();
	

	Stat(std::string t);
};

//any character, player or enemy
class Character{
public:
	//base stats
	Stat con = Stat("con"); //Constitution
	Stat dex = Stat("dex"); //Dexterity
	Stat itl = Stat("itl"); //Intelligence
	Stat str = Stat("str"); //Strength
	Stat wis = Stat("wis"); //Wisdom
	Weapon weapon;
	bool armed;
	bool dead;
	int Dice(int numDice, int faces);
	int FindModifier(int abilityscore);
	Character RollBaseStats(Character character);
	Character DetermineAC(Character character);
	Character DetermineAB(Character character);
	Character DetermineSavingThrows(Character character);
	Character DetermineHP(Character character);


protected:
	bool IsUsingShield;
	

	std::string name;
	std::string profession; //class
	std::string desc;
	int level;

	std::string CombatAction;

	int maxHP;
	int HP;

	//saving throws
	int paralyze;
	int poison;
	int breath;
	int magicdevice;
	int magic;

	//attack bonuses
	int base;
	int melee;
	int ranged;

	//armor class

	int meleeAC;
	int rangedAC;
	int noshield;
	int surprised;

public:

	//getters, setters

	void setName(std::string n);
	std::string getName();

	void setProfession(std::string p);
	std::string getProfession();

	void setDesc(std::string d);
	std::string getDesc();

	void setLevel(int l);
	int getLevel();

	void setCombatAction(std::string ca);
	std::string getCombatAction();

	void setMaxHP(int max);
	int getMaxHP();

	void setHP(int hp);
	int getHP();

	//saving throws
	void setParalyze(int n);
	int getParalyze();

	void setPoison(int n);
	int getPoison();

	void setBreath(int n);
	int getBreath();

	void setMagicDevice(int n);
	int getMagicDevice();

	void setMagic(int n);
	int getMagic();

	//attack bonuses
	void setBase(int n);
	int getBase();

	void setMelee(int n);
	int getMelee();

	void setRanged(int n);
	int getRanged();

	//armor class
	void setMeleeAC(int n);
	int getMeleeAC();

	void setRangedAC(int n);
	int getRangedAC();

	void setNoshield(int n);
	int getNoshield();

	void setSurprised(int n);
	int getSurprised();

	void EquipShield();
	void UnequipShield();

	bool ShieldStatus();

	void ParryOn();

	void ParryOff();

	void PressOn();

	void PressOff();

	void DefenseOn();

	void DefenseOff();

	void TakeDamage(int dmg);

	Character();
	void equipWeapon(Weapon w);
};



#endif

