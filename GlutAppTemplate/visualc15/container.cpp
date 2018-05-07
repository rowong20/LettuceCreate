#include "container.h"



container::container(const char* filename, int numIngredients, float x = 0, float y = 0, float w = 0.3, float h = 0.3)
{
	//number of ingredients allowed to be on the object 
	//1 for pots, pans, etc
	//4 for plates
	//don't need to initialize the vector of ingredients
	TexRect* object = new TexRect(filename, x, y, w, h);

	this->maxIngredient = numIngredients;
	this->full = false;
}


void container::addIngredient(int i) {
	//as long as container is not full, it adds an ingredient

	if (!isFull()) {
		this->ingredients.push_back(i);

	}
}

bool container::isFull() {

	//if the size of the ingredient vector is less than the max ingredients allowed, the object is full
	if (this->ingredients.size() >= this->maxIngredient) {
		full = true;
	}
	else {
		full = false;
	}
	return full;
}

container::~container()
{
}
