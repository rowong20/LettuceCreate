#ifndef container_h
#define container_h

#include "TexRect.h"
#include <vector>

//this class is for pots, pans, boards etc

class container
{
public:
	container(const char*, int, float, float, float, float);

	TexRect* object;
	//max Ingredients allowed in object (1 for pot, 4 for plates 
	int maxIngredient;
	//says if the object is full or not
	bool full;

	//array to show what ingredients are in there
	std::vector<int>ingredients;
	bool isFull();

	//to add an ingredient to the vector of ingredients
	void addIngredient(int i);


	~container();
};

#endif