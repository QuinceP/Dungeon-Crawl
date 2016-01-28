#include <TGUI/TGUI.hpp>
#include "Character.h"

//getters, setters

void Character::setName(std::string n){
	name = n;
}
std::string Character::getName(){
	return name;
}

void Character::setProfession(std::string p){
	profession = p;
}
std::string Character::getProfession(){
	return profession;
}

void Character::setDesc(std::string d){
	desc = d;
}
std::string Character::getDesc(){
	return desc;
}

void Character::setLevel(int l){
	level = l;
}
int Character::getLevel(){
	return level;
}

void Character::setCombatAction(std::string ca){
	CombatAction = ca;
}
std::string Character::getCombatAction(){
	return CombatAction;
}

void Character::setMaxHP(int max){
	maxHP = max;
}
int Character::getMaxHP(){
	return maxHP;
}

void Character::setHP(int hp){
	HP = hp;
}
int Character::getHP(){
	return HP;
}

//saving throws
void Character::setParalyze(int n){
	paralyze = n;
}
int Character::getParalyze(){
	return paralyze;
}

void Character::setPoison(int n){
	poison = n;
}
int Character::getPoison(){
	return poison;
}

void Character::setBreath(int n){
	breath = n;
}
int Character::getBreath(){
	return breath;
}

void Character::setMagicDevice(int n){
	magicdevice = n;
}
int Character::getMagicDevice(){
	return magicdevice;
}

void Character::setMagic(int n){
	magic = n;
}
int Character::getMagic(){
	return magic;
}

//attack bonuses
void Character::setBase(int n){
	base = n;
}
int Character::getBase(){
	return base;
}

void Character::setMelee(int n){
	melee = n;
}
int Character::getMelee(){
	return melee;
}

void Character::setRanged(int n){
	ranged = n;
}
int Character::getRanged(){
	return ranged;
}

//armor class
void Character::setMeleeAC(int n){
	meleeAC = n;
}
int Character::getMeleeAC(){
	return meleeAC;
}

void Character::setRangedAC(int n){
	rangedAC = n;
}
int Character::getRangedAC(){
	return rangedAC;
}

void Character::setNoshield(int n){
	noshield = n;
}
int Character::getNoshield(){
	return noshield;
}

void Character::setSurprised(int n){
	surprised = n;
}
int Character::getSurprised(){
	return surprised;
}

void Character::EquipShield(){
	IsUsingShield = true;
}

void Character::UnequipShield(){
	IsUsingShield = false;
}

bool Character::ShieldStatus(){
	return IsUsingShield;
}

void Character::ParryOn(){
	CombatAction = "Parry";
	if (profession == "Fighter" || profession == "Dwarf" || profession == "Elf"){
		meleeAC += 4;
		rangedAC += 4;
		noshield += 4;
		surprised += 4;

	}
	else{
		meleeAC += 2;
		rangedAC += 2;
		noshield += 2;
		surprised += 2;
	}
}

void Character::ParryOff(){
	CombatAction = "Standard";
	if (profession == "Fighter" || profession == "Dwarf" || profession == "Elf"){
		meleeAC -= 4;
		rangedAC -= 4;
		noshield -= 4;
		surprised -= 4;

	}
	else{
		meleeAC -= 2;
		rangedAC -= 2;
		noshield -= 2;
		surprised -= 2;
	}
}

void Character::PressOn(){
	CombatAction = "Parry";
	if (profession == "Fighter" || profession == "Dwarf" || profession == "Elf"){
		meleeAC -= 4;
		rangedAC -= 4;
		noshield -= 4;
		surprised -= 4;

		base += 2;
		melee += 2;
		ranged += 2;

	}
	else{
	}
}

void Character::PressOff(){
	CombatAction = "Standard";
	if (profession == "Fighter" || profession == "Dwarf" || profession == "Elf"){
		meleeAC += 4;
		rangedAC += 4;
		noshield += 4;
		surprised += 4;

		base -= 2;
		melee -= 2;
		ranged -= 2;

	}
	else{
	}
}

void Character::DefenseOn(){
	CombatAction = "Defensive";
	if (profession == "Fighter" || profession == "Dwarf" || profession == "Elf"){
		meleeAC += 2;
		rangedAC += 2;
		noshield += 2;
		surprised += 2;

		base -= 4;
		melee -= 4;
		ranged -= 4;

	}
	else{
	}
}

void Character::DefenseOff(){
	CombatAction = "Standard";
	if (profession == "Fighter" || profession == "Dwarf" || profession == "Elf"){
		meleeAC -= 2;
		rangedAC -= 2;
		noshield -= 2;
		surprised -= 2;

		base += 4;
		melee += 4;
		ranged += 4;

	}
	else{
	}
}

void Character::TakeDamage(int dmg){
	if ((HP - dmg) <= 0){
		HP = 0;
		dead = true;
	}
	else{
		HP = HP - dmg;
	}
}

Character::Character(){
	dead = false;
	armed = false;
	IsUsingShield = false;
	CombatAction = "Standard";
	weapon = Weapon("fists", "Good ol' fisticuffs.", 0, 2);

}


void Character::equipWeapon(Weapon w){
	weapon = w;
	armed = true;
}


int Character::Dice(int numDice, int faces){
	int total = 0;

	for (int i = 0; i < numDice; i++){
		int roll = rand() % faces + 1;
		total += roll;
	}

	return total;
}

int Character::FindModifier(int abilityscore){
	int mod = 0;
	switch (abilityscore){
	case 3:
		mod = -3;
		break;

	case 4:
	case 5:
		mod = -2;
		break;

	case 6:
	case 7:
	case 8:
		mod = -1;
		break;

	case 9:
	case 10:
	case 11:
	case 12:
		mod = 0;
		break;

	case 13:
	case 14:
	case 15:
		mod = 1;
		break;

	case 16:
	case 17:
		mod = 2;
		break;

	case 18:
		mod = 3;
		break;

	default:
		mod = 0;
		break;
	}

	return mod;
}

Character Character::RollBaseStats(Character character){
	int totalmods = 0;
	do {

		//set stats and modifiers
		character.con.setValue(character.Dice(3, 6));
		character.con.setModifier(character.FindModifier(character.con.getValue()));

		character.dex.setValue(character.Dice(3, 6));
		character.dex.setModifier(character.FindModifier(character.dex.getValue()));

		character.itl.setValue(character.Dice(3, 6));
		character.itl.setModifier(character.FindModifier(character.itl.getValue()));

		character.str.setValue(character.Dice(3, 6));
		character.str.setModifier(character.FindModifier(character.str.getValue()));

		character.wis.setValue(character.Dice(3, 6));
		character.wis.setModifier(character.FindModifier(character.wis.getValue()));

		totalmods = character.con.getModifier() + character.dex.getModifier() + character.itl.getModifier() + character.str.getModifier() + character.wis.getModifier();

		if (totalmods < 0){
			//std::cout << "Stats too poor. Rolling again." << std::endl;
		}

	} while (totalmods < 0);

	return character;

}


Character Character::DetermineHP(Character character){

	std::string profession = character.getProfession();
	int roll = 0;

	if (profession == "Cleric"){
		roll = character.Dice(1, 6) + character.con.getModifier();
		if (roll < 4){
			character.setMaxHP(4);
			character.setHP(character.getMaxHP());
		}
		else{
			character.setMaxHP(roll);
			character.setHP(character.getMaxHP());
		}
	}

	else if (profession == "Fighter"){
		roll = character.Dice(1, 8) + character.con.getModifier();
		if (roll < 8){
			character.setMaxHP(8);
			character.setHP(character.getMaxHP());
		}
		else{
			character.setMaxHP(roll);
			character.setHP(character.getMaxHP());
		}
	}

	else if (profession == "Magic-User"){
		roll = character.Dice(1, 6) + character.con.getModifier();
		if (roll < 3){
			character.setMaxHP(3);
			character.setHP(character.getMaxHP());
		}
		else{
			character.setMaxHP(roll);
			character.setHP(character.getMaxHP());
		}
	}

	else if (profession == "Specialist"){
		roll = character.Dice(1, 6) + character.con.getModifier();
		if (roll < 4){
			character.setMaxHP(4);
			character.setHP(character.getMaxHP());
		}
		else{
			character.setMaxHP(roll);
			character.setHP(character.getMaxHP());
		}
	}

	else if (profession == "Dwarf"){
		roll = character.Dice(1, 10) + character.con.getModifier();
		if (roll < 6){
			character.setMaxHP(6);
			character.setHP(character.getMaxHP());
		}
		else{
			character.setMaxHP(roll);
			character.setHP(character.getMaxHP());
		}
	}

	else if (profession == "Elf"){
		roll = character.Dice(1, 6) + character.con.getModifier();
		if (roll < 4){
			character.setMaxHP(4);
			character.setHP(character.getMaxHP());
		}
		else{
			character.setMaxHP(roll);
			character.setHP(character.getMaxHP());
		}
	}

	else if (profession == "Halfling"){
		roll = character.Dice(1, 6) + character.con.getModifier();
		if (roll < 4){
			character.setMaxHP(4);
			character.setHP(character.getMaxHP());
		}
		else{
			character.setMaxHP(roll);
			character.setHP(character.getMaxHP());
		}
	}
	return character;
}

Character Character::DetermineSavingThrows(Character character){

	std::string profession = character.getProfession();
	int roll = 0;


	if (profession == "Cleric"){
		character.setParalyze(14);
		character.setPoison(11);
		character.setBreath(16);
		character.setMagicDevice(12);
		character.setMagic(15);
	}

	else if (profession == "Fighter"){
		character.setParalyze(14);
		character.setPoison(12);
		character.setBreath(15);
		character.setMagicDevice(13);
		character.setMagic(16);
	}

	else if (profession == "Magic-User"){
		character.setParalyze(1);
		character.setPoison(13);
		character.setBreath(16);
		character.setMagicDevice(13);
		character.setMagic(14);
	}

	else if (profession == "Specialist"){
		character.setParalyze(14);
		character.setPoison(16);
		character.setBreath(15);
		character.setMagicDevice(14);
		character.setMagic(14);
	}

	else if (profession == "Dwarf"){
		character.setParalyze(12);
		character.setPoison(10);
		character.setBreath(15);
		character.setMagicDevice(11);
		character.setMagic(14);
	}

	else if (profession == "Elf"){
		character.setParalyze(15);
		character.setPoison(14);
		character.setBreath(17);
		character.setMagicDevice(15);
		character.setMagic(17);
	}

	else if (profession == "Halfling"){
		character.setParalyze(12);
		character.setPoison(10);
		character.setBreath(15);
		character.setMagicDevice(11);
		character.setMagic(14);
	}


	return character;

}

Character Character::DetermineAB(Character character){
	std::string profession = character.getProfession();
	int roll = 0;

	if (profession == "Fighter"){
		character.setBase(character.getLevel() + 1);
		character.setMelee(character.getBase() + character.str.getModifier());
		character.setRanged(character.getBase() + character.dex.getModifier());
	}

	else{
		character.setBase(1);
		character.setMelee(character.getBase() + character.str.getModifier());
		character.setRanged(character.getBase() + character.dex.getModifier());
	}

	return character;
}

Character Character::DetermineAC(Character character){
	std::string profession = character.getProfession();

	character.setMeleeAC(character.dex.getModifier());
	if (character.ShieldStatus() == true){
		character.setRangedAC(character.getMeleeAC() + 1);
	}
	else{
		character.setRangedAC(character.getMeleeAC());
	}
	character.setNoshield(character.getMeleeAC());
	//Surprised AC is Mêlée without shield or Dexterity modifiers, with a further 2-point penalty.
	character.setSurprised(0);

	return character;
}
