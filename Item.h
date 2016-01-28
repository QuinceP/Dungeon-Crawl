#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>




class Item{
protected:
	std::string name;
	std::string desc;
	int cost;

public:
	void setName(std::string n){
		name = n;
	}
	std::string getName(){
		return name;
	}

	void setDesc(std::string d){
		desc = d;
	}
	std::string getDesc(){
		return desc;
	}

	void setCost(int c){
		cost = c;
	}
	int getCost(){
		return cost;
	}

	Item(){
		name = "";
		desc = "";
		cost = 0;
	}

	Item(std::string n, std::string d, int c){
		name = n;
		desc = d;
		cost = c;
	}

};

class Weapon :public Item{
private:
	int damage;
public:
	void setDamage(int d){
		damage = d;
	}

	int getDamage(){
		return damage;
	}

	Weapon(std::string n, std::string d, int c, int dmg) : Item(n, d, c), damage(dmg){}
	Weapon(){
		damage = 0;
	}

	Weapon(int dmg){
		damage = dmg;
	}
};



#endif
