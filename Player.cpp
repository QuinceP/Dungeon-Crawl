#include <iostream>
#include <string>
#include "Player.h"


//basic struct for base stats with their modifiers
void Stat::setType(std::string t){
		type = t;
	}
std::string Stat::getType(){
		return type;
	}

void Stat::setValue(int val){
		value = val;
	}
int Stat::getValue(){
		return value;
	}

void Stat::setModifier(int mod){
		modifier = mod;
	}

int Stat::getModifier(){
		return modifier;
	}

Stat::Stat(std::string t){
		type = t;
		value = 0;
		modifier = 0;
	}

//getters, setters
void Player::setSP(int money){
	sp = money;
}
int Player::getSP(){
	return sp;
}

void Player::setAlignment(std::string a){
	alignment = a;
}
std::string Player::getAlignment(){
	return alignment;
}

void Player::setLevel(int l){
	level = l;
}
int Player::getLevel(){
	return level;
}

void Player::setXP(int exp){
	XP = exp;
}
int Player::getXP(){
	return XP;
}

void Player::setXPtoNextLevel(int exp){
	Player::XPtoNextLevel = exp;
}
int Player::getXPtoNextLevel(){
	return Player::XPtoNextLevel;
}

void Player::setCombatAction(std::string ca){
	CombatAction = ca;
}
std::string Player::getCombatAction(){
	return CombatAction;
}

void Player::addToInventory(Item item){
	inventory.push_back(item);
}

void Player::equipWeapon(Weapon w){
	weapon = w;
	armed = true;
}

Player::Player(){
	dead = false;
	armed = false;
	IsUsingShield = false;
	sp = 0;
	CombatAction = "Standard";
	XP = 0;
	weapon = Weapon("fists", "Good ol' fisticuffs.", 0, 2);

}

Player Player::RollBaseStats(Player player){
	int totalmods = 0;
	do {

		//set stats and modifiers
		player.con.setValue(player.Dice(3, 6));
		player.con.setModifier(player.FindModifier(player.con.getValue()));

		player.dex.setValue(player.Dice(3, 6));
		player.dex.setModifier(player.FindModifier(player.dex.getValue()));

		player.itl.setValue(player.Dice(3, 6));
		player.itl.setModifier(player.FindModifier(player.itl.getValue()));

		player.str.setValue(player.Dice(3, 6));
		player.str.setModifier(player.FindModifier(player.str.getValue()));

		player.wis.setValue(player.Dice(3, 6));
		player.wis.setModifier(player.FindModifier(player.wis.getValue()));

		totalmods = player.con.getModifier() + player.dex.getModifier() + player.itl.getModifier() + player.str.getModifier() + player.wis.getModifier();

		if (totalmods < 0){
			//std::cout << "Stats too poor. Rolling again." << std::endl;
		}

	} while (totalmods < 0);

	return player;

}


Player Player::DetermineHP(Player player){

	std::string profession = player.getProfession();
	int roll = 0;

	if (profession == "Cleric"){
		roll = player.Dice(1, 6) + player.con.getModifier();
		if (roll < 4){
			player.setMaxHP(4);
			player.setHP(player.getMaxHP());
		}
		else{
			player.setMaxHP(roll);
			player.setHP(player.getMaxHP());
		}
	}

	else if (profession == "Fighter"){
		roll = player.Dice(1, 8) + player.con.getModifier();
		if (roll < 8){
			player.setMaxHP(8);
			player.setHP(player.getMaxHP());
		}
		else{
			player.setMaxHP(roll);
			player.setHP(player.getMaxHP());
		}
	}

	else if (profession == "Magic-User"){
		roll = player.Dice(1, 6) + player.con.getModifier();
		if (roll < 3){
			player.setMaxHP(3);
			player.setHP(player.getMaxHP());
		}
		else{
			player.setMaxHP(roll);
			player.setHP(player.getMaxHP());
		}
	}

	else if (profession == "Specialist"){
		roll = player.Dice(1, 6) + player.con.getModifier();
		if (roll < 4){
			player.setMaxHP(4);
			player.setHP(player.getMaxHP());
		}
		else{
			player.setMaxHP(roll);
			player.setHP(player.getMaxHP());
		}
	}

	else if (profession == "Dwarf"){
		roll = player.Dice(1, 10) + player.con.getModifier();
		if (roll < 6){
			player.setMaxHP(6);
			player.setHP(player.getMaxHP());
		}
		else{
			player.setMaxHP(roll);
			player.setHP(player.getMaxHP());
		}
	}

	else if (profession == "Elf"){
		roll = player.Dice(1, 6) + player.con.getModifier();
		if (roll < 4){
			player.setMaxHP(4);
			player.setHP(player.getMaxHP());
		}
		else{
			player.setMaxHP(roll);
			player.setHP(player.getMaxHP());
		}
	}

	else if (profession == "Halfling"){
		roll = player.Dice(1, 6) + player.con.getModifier();
		if (roll < 4){
			player.setMaxHP(4);
			player.setHP(player.getMaxHP());
		}
		else{
			player.setMaxHP(roll);
			player.setHP(player.getMaxHP());
		}
	}
	return player;
}

Player Player::DetermineSavingThrows(Player player){

	std::string profession = player.getProfession();
	int roll = 0;


	if (profession == "Cleric"){
		player.setParalyze(14);
		player.setPoison(11);
		player.setBreath(16);
		player.setMagicDevice(12);
		player.setMagic(15);
	}

	else if (profession == "Fighter"){
		player.setParalyze(14);
		player.setPoison(12);
		player.setBreath(15);
		player.setMagicDevice(13);
		player.setMagic(16);
	}

	else if (profession == "Magic-User"){
		player.setParalyze(1);
		player.setPoison(13);
		player.setBreath(16);
		player.setMagicDevice(13);
		player.setMagic(14);
	}

	else if (profession == "Specialist"){
		player.setParalyze(14);
		player.setPoison(16);
		player.setBreath(15);
		player.setMagicDevice(14);
		player.setMagic(14);
	}

	else if (profession == "Dwarf"){
		player.setParalyze(12);
		player.setPoison(10);
		player.setBreath(15);
		player.setMagicDevice(11);
		player.setMagic(14);
	}

	else if (profession == "Elf"){
		player.setParalyze(15);
		player.setPoison(14);
		player.setBreath(17);
		player.setMagicDevice(15);
		player.setMagic(17);
	}

	else if (profession == "Halfling"){
		player.setParalyze(12);
		player.setPoison(10);
		player.setBreath(15);
		player.setMagicDevice(11);
		player.setMagic(14);
	}


	return player;

}

Player Player::DetermineAB(Player player){
	std::string profession = player.getProfession();
	int roll = 0;

	if (profession == "Fighter"){
		player.setBase(player.getLevel() + 1);
		player.setMelee(player.getBase() + player.str.getModifier());
		player.setRanged(player.getBase() + player.dex.getModifier());
	}

	else{
		player.setBase(1);
		player.setMelee(player.getBase() + player.str.getModifier());
		player.setRanged(player.getBase() + player.dex.getModifier());
	}

	return player;
}

Player Player::DetermineAC(Player player){
	std::string profession = player.getProfession();

	player.setMeleeAC(player.dex.getModifier());
	if (player.ShieldStatus() == true){
		player.setRangedAC(player.getMeleeAC() + 1);
	}
	else{
		player.setRangedAC(player.getMeleeAC());
	}
	player.setNoshield(player.getMeleeAC());
	//Surprised AC is Mêlée without shield or Dexterity modifiers, with a further 2-point penalty.
	player.setSurprised(0);

	return player;
}
