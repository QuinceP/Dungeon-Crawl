#pragma once
#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <string>
#include "Character.h"

class Monster:public Character{
public:
	Monster();
	Monster(std::string n, std::string p);
};
#endif

