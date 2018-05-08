#include "container.h"
#include "GlutApp.h"
#include <iostream>
#include <time.h>
#include <ctime>

#define CLOCKS_PER_SEC ((clock_t)1000)

void delay(float secs)
{
	float end = clock() / CLOCKS_PER_SEC + secs;
	while ((clock() / CLOCKS_PER_SEC) < end);
}

//abstract class container
container::container() {
	std::cout << "Creating Container" << std::endl;
}
void container::addIngredient(Ingredient* i) {
	//as long as container is not full, it adds an ingredient

	if (!this->isFull()) {
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

//checks if intersecting
/*bool container::contains(float x, float y) {
	//checks if the ingredients intersect with the board
	return x >= this->x && x <= this->x + this->w && y <= this->y && y >= this->y - this->h;
<<<<<<< HEAD
}*/

=======
}
//transfers the contents of one container to the other, and clears the input container afterwards
void container::transfer(container* &input)
{
	this->ingredients = input->ingredients;
	input->ingredients.clear();
	input->changeImage(input->defaultImage);
}
>>>>>>> 8df773405994eaeb2796eee4a780613feb19d247
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

	if (cooking == true) {
		//immediately change to cooking the pot first image
		changeImage("../images/pot_onion1");
		
		int i = 0;
		while (i < 3) {
			//then iterate between the two images
			delay(1);
			changeImage("../images/pot_onion2");
			delay(1);
			changeImage("../images/pot_onion1");

			i++;
		}

		changeImage("../images/pot_onion3");
		//perfect cooking
		this->Cooked = 1;
	}

}

void pot::empty() {
	//resets pot
	this->cooking = false;
	changeImage("../images/pot_empty");
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

		//changes to show meat on the pan
		changeImage("../images/pan_meat");

		//last image of completed cooking
		delay(7);
		changeImage("../images/pan_cooked");

	}

	//perfect cooking
	this->Cooked = 1;
	
	//needs a function to detect when food is taken off?
	//then calls empty pan function

}

void pan::empty() {
	//reset pan
	this->cooking = false;
	changeImage("../images/pan_empty");

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


void board::action(Ingredient* ingredient) {
	//ingredients needs to detect object to cut
	//how to decide this?
	if (this->contains(ingredient->x, ingredient->y)) {
		cutting = true;
	}

	//not sure what to do but the cutting animation is handled by ingredients?
	
	//if statement indicates that this is a cutting board
}

void board::empty() {

}
plate::plate(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/plate.png";
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



}
void plate::empty() {
	delay(1);
	changeImage("../images/plate");
}
void plate::action() {



}


