#pragma once
#ifndef INGREDIENT_H
#define INGREDIENT_H
#include "TexRect.h"
class Ingredient :public TexRect
{
	int status;
	
public:
	//Returns status of ingredient
	//1 for whole, 2 for cut, 3 for undercooked, 4 for perfect, 5 overcooked
	int status() {
		return status;
	}
	void cook() {
		if (status == 2) {

		}
	}
	void cut() {

	}
	void changeImage(const char* filename)
	{
		
	}
	~Ingredient()
	{

		
	}
};

#endif