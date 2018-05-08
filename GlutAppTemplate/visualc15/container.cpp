#include "container.h"
#include "GlutApp.h"
#include <iostream>

//abstract class container
container::container() {
	std::cout << "Creating Container" << std::endl;
}
void container::addIngredient(Ingredient* i) {
	//as long as container is not full, it adds an ingredient

	if (!isFull()) {
		std::cout << "Pushing ingredient" << std::endl;
		ingredients.push_back(i);
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

//transfers the contents of one container to the other, and clears the input container afterwards
void container::transfer(container* &input)
{
	this->ingredients = input->ingredients;
	input->ingredients.clear();
	input->changeImage(input->defaultImage);
}

container::~container()
{
}
pot::pot(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/pot_empty.png";
	defaultImage = filename;
	std::cout << " Creating Pot" << std::endl;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	texture_id = SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	
	//initialize first imagae
	this->Cooked = 0;
	this->cooking = false;
}

void pot::action(Ingredient* ingredient) {
	if (this->contains(ingredient->x, ingredient->y)) {
		cooking = true;
		cook();
	}
}

//added a cooking function to pot
void pot::cook() {
	/*
	if (cooking == true) {
		//immediately change to cooking the pot first image
		changeImage("../images/pot_onion1");
		
		int i = 0;
		while (i < 3) {
			//then iterate between the two images
			glutTimerFunc(200, app_timer, 1);
			changeImage("../images/pot_onion2");
			glutTimerFunc(200, app_timer, 1);
			changeImage("../images/pot_onion1");

			i++;
		}


		glutTimerFunc(100, app_timer, 1);
		changeImage("../images/pot_onion3");
		//perfect cooking
		this->Cooked = 1;
	}
	*/

}

void pot::empty() {
	//resets pot
	this->cooking = false;
	changeImage("../images/pot_empty");
}
void pot::check() {
	bool tomato = false, onion = false, mushroom = false;
	std::cout << "Checking ingredients" << std::endl;
	std::cout << ingredients[0]->getName() << std::endl;
	for (int i = 0; i < ingredients.size(); i++)
	{
		if (ingredients[i]->getName() == "tomato")
		{
			tomato = true;
		}
		if (ingredients[i]->getName() == "onion")
		{
			onion = true;
		}
		if (ingredients[i]->getName() == "mushroom")
		{
			onion = true;
		}
	}
	if (onion) {
		changeImage("../images/pot_onion3.png");
	}
	else if (mushroom) {
		changeImage("../images/pot_mushroom3.png");
	}
	else if (tomato) {
		changeImage("../images/pot_tomato3.png");
	}
	else
		changeImage("../images/pot_death.png");
}


pan::pan(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/pan_empty.png";
	defaultImage = filename;
	std::cout << " Creating Pot" << std::endl;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	texture_id = SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

	//is not cooking
	this->cooking = false; 
	//cooking is zero
	this->Cooked = 0;
}

void pan::action(Ingredient* ingredient) {
	if (this->contains(ingredient->x, ingredient->y)) {
		cooking = true;
		cook();
	}
}

void pan::cook() {

	if (this->cooking == true) {
		/*
		//changes to show meat on the pan
		changeImage("../images/pan_meat");

		//last image of completed cooking
		glutTimerFunc(1500, app_timer, 1);
		changeImage("../images/pan_cooked");
*/
	}

	//perfect cooking
	this->Cooked = 1;
	
	//needs a function to detect when food is taken off?
	//then calls empty pan function

}

void pan::empty() {
	//reset pan
	this->cooking == false;
	changeImage("../images/pan_empty");

}
void pan::check() {
	bool meat = 0;
	if (ingredients[0]->getName() == "meat")
	{
		meat = true;
	}
	if (meat) {
		changeImage("../images/pan_meat.png");
	}
}

board::board(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/board.png";
	defaultImage = filename;
	std::cout << " Creating Pot" << std::endl;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	texture_id = SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

	//theres no object to cut
	cutting = false;

}
void board::check() {
}

int board::action(Ingredient* ingredient) {
	//ingredients needs to detect object to cut
	//how to decide this?
	if (this->contains(ingredient->x, ingredient->y)) {
		cutting = true;
	}

	//not sure what to do but the cutting animation is handled by ingredients?
	
	//if statement indicates that this is a cutting board
	if (cutting) {
		return 1;
	}

}
plate::plate(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/plate.png";
	defaultImage = filename;
	std::cout << " Creating Plate" << std::endl;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	texture_id = SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void plate::check() {
	bool lettuce = false, tomato = false, bun = false, meat = false, onion = false,mushroom=false;
	std::cout << "Checking ingredients" << std::endl;
	std::cout << ingredients[0]->getName() << std::endl;
	for (int i = 0; i < ingredients.size(); i++)
	{
		if (ingredients[i]->getName() == "tomato")
		{
			tomato = true;
		}
		if (ingredients[i]->getName() == "lettuce")
		{
			lettuce = true;
		}
		if (ingredients[i]->getName() == "bun")
		{
			bun = true;
		}
		if (ingredients[i]->getName() == "meat")
		{
			meat = true;
		}
		if (ingredients[i]->getName() == "onion")
		{
			onion = true;
		}
		if (ingredients[i]->getName() == "mushroom")
		{
			onion = true;
		}
	}
	if (onion) {
		changeImage("../images/soup_onion.png");
	}
	else if (mushroom) {
		changeImage("../images/soup_mushroom.png");
	}
	else if (lettuce&&tomato) {
		changeImage("../images/salad_lettuce_tomato.png");
	}
	else if (lettuce) {
		changeImage("../images/salad_lettuce.png");
	}
	else if (tomato) {
		changeImage("../images/soup_tomato.png");
	}
	else if (bun&&lettuce&&tomato&&meat) {
		changeImage("../images/bun_full.png");
	}
	else if (bun&&lettuce&&meat) {
		changeImage("../images/bun_meat_lettuce.png");
	}
	else if (bun&&tomato&&meat) {
		changeImage("../images/bun_meat_tomato.png");
	}
	else if (bun&&meat) {
		changeImage("../images/bun_meat.png");
	}
	else if (bun) {
		changeImage("../images/bun_plate.png");
	}
	else
		std::cout << "kys"<<std::endl;
}

