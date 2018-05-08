#pragma once
#ifndef INGREDIENT_H
#define INGREDIENT_H
#include "TexRect.h"
class Ingredient :public TexRect
{
	int status;
public:
	Ingredient();
	//Returns status of ingredient
	//1 for whole, 2 for cut, 3 for undercooked, 4 for perfect, 5 overcooked
	virtual int getStatus() = 0;
	virtual void cut() = 0;
	virtual void cooked(int quality) = 0;
};

class Tomato :public Ingredient {
	int status;
public:
	Tomato(float, float, float, float);
	int getStatus();
	void cut();
	void cooked(int quality);
};

class Mushroom :public Ingredient {
	int status;
public:
	Mushroom(float, float, float, float);
	int getStatus();
	void cut();
	void cooked(int quality);
};
class Onion :public Ingredient {
	int status;
public:
	Onion(float, float, float, float);
	int getStatus();
	void cut();
	void cooked(int quality);
};
class Meat :public Ingredient {
	int status;
public:
	Meat(float, float, float, float);
	int getStatus();
	void cut();
	void cooked(int quality);
};
class Lettuce :public Ingredient {
	int status;
public:
	Lettuce(float, float, float, float);
	int getStatus();
	void cut();
	void cooked(int quality);
};
class Bun:public Ingredient {
	int status;
public:
	Bun(float, float, float, float);
	int getStatus();
	void cut();
	void cooked(int quality);
};
#endif