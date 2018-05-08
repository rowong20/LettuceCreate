#include "container.h"
#include <iostream>

//abstract class container
container::container() {
	std::cout << "Creating Container" << std::endl;
}
void container::addIngredient(Ingredient* i) {
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
pot::pot(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/pot_empty.png";
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
void pot::action() {

}
pan::pan(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/pan_empty.png";
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
void pan::action() {

}
board::board(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/board.png";
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
void board::action() {

}
plate::plate(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/plate.png";
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
void plate::action() {

}


