#ifndef container_h
#define container_h

#include "GlutApp.h"
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
	const char* defaultImage;
	std::vector<Ingredient*>ingredients;
	container();
	//each container will do different things
	void transfer(container* &input);
	virtual void cook();
	bool isFull();
	//to add an ingredient to the vector of ingredients
	void addIngredient(Ingredient* i);
	virtual void check()=0;
	//indicates if there is an object intersecting
	~container();
};
class pot :public container
{
	int maxIngredient;
	bool full;
	//indicates 0 for empty 1 for cooking 2 for perfect 3 for bad
	int Cooked;
public:
	pot(float, float, float, float);
	//indicates if the pot can cook
	bool cooking;

	//declared version of cooking
	void cook();
	void empty();
	void action(Ingredient*);
	void check();
};
class pan :public container
{
	int maxIngredient;
	bool full;
	//indicates 0 for empty 1 for cooking 2 for perfect 3 for bad
	int Cooked;
public:
	pan(float, float, float, float);
	void cook();
	//indicates if pot can cook
	bool cooking;
	//resets pan settings
	void empty();
	void action(Ingredient*);
	void check();
};
class board :public container
{
	int maxIngredient;
	bool full;
public:
	//indicates whether it is something can be cut
	bool cutting;
	board(float, float, float, float);
	void check();
	//used for ingredients to detect that they can be cut
	void action(Ingredient*);
};
class plate :public container
{
	int maxIngredient;
	bool full;
public:
	plate(float, float, float, float);
	void check();
};
#endif