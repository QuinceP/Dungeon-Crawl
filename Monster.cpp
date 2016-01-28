#include <iostream>
#include <string>
#include "Monster.h"

Monster::Monster(){
	dead = false;
	armed = false;
	IsUsingShield = false;
	CombatAction = "Standard";
	weapon = Weapon("claws", "Good ol' claws.", 0, 2);
}

Monster::Monster(std::string n, std::string p){
	dead = false;
	armed = false;
	name = n;
	profession = p;
	IsUsingShield = false;
	CombatAction = "Standard";
	weapon = Weapon("claws", "Good ol' claws.", 0, 2);
}

