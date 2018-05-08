#pragma once
#ifndef INGREDIENT_H
#define INGREDIENT_H
#include "TexRect.h"
#include <string>
class Ingredient :public TexRect
{
	int status;
public:
	std::string name;
	Ingredient();
	//Returns status of ingredient
	//1 for whole, 2 for cut, 3 for undercooked, 4 for perfect, 5 overcooked
	virtual std::string getName() = 0;
	virtual void cut() = 0;
	virtual void cooked(int quality) = 0;
};

class Tomato :public Ingredient {
	int status;
public:
	std::string name;
	Tomato(float, float, float, float);
	std::string getName();
	void cut();
	void cooked(int quality);
};

class Mushroom :public Ingredient {
	int status;
public:
	std::string name;
	Mushroom(float, float, float, float);
	std::string getName();
	void cut();
	void cooked(int quality);
};
class Onion :public Ingredient {
	int status;
public:
	std::string name;
	Onion(float, float, float, float);
	std::string getName();
	void cut();
	void cooked(int quality);
};
class Meat :public Ingredient {
	int status;
public:
	std::string name;
	Meat(float, float, float, float);
	std::string getName();
	void cut();
	void cooked(int quality);
};
class Lettuce :public Ingredient {
	int status;
public:
	std::string name;
	Lettuce(float, float, float, float);
	std::string getName();
	void cut();
	void cooked(int quality);
};
class Bun:public Ingredient {
	int status;
public:
	std::string name;
	Bun(float, float, float, float);
	std::string getName();
	void cut();
	void cooked(int quality);
};
#endif