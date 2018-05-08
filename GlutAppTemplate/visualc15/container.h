#ifndef container_h
#define container_h

#include "TexRect.h"
#include <vector>
#include "Ingredient.h"
//this class is for pots, pans, boards etc

class container :public TexRect
{
	//max Ingredients allowed in object (1 for pot/pan, 4 for plates)
	int maxIngredient;
	bool full;
public:	
	//array to show what ingredients are in there
	std::vector<Ingredient*>ingredients;
	container();
	//each container will do different things
	virtual void action() = 0;
	bool isFull();
	//to add an ingredient to the vector of ingredients
	void addIngredient(Ingredient* i);
	~container();
};
class pot :public container
{
	int maxIngredient;
	bool full;
public:
	pot(float, float, float, float);
	void action();
};
class pan :public container
{
	int maxIngredient;
	bool full;
public:
	pan(float, float, float, float);
	void action();
};
class board :public container
{
	int maxIngredient;
	bool full;
public:
	board(float, float, float, float);
	void action();
};
class plate :public container
{
	int maxIngredient;
	bool full;
public:
	plate(float, float, float, float);
	void action();
};
#endif