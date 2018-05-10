#include "Ingredient.h"
#include <iostream>

Ingredient::Ingredient() {
	std::cout << "Creating Ingredient"<<std::endl;
}

Tomato::Tomato(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/tomato_uncut.png";
	std::cout << " Creating Tomato"<<std::endl;
	name = "tomato";
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
std::string Tomato::getName() {
	return name;
}
void Tomato::cut() {
	status = 2;
	changeImage("../images/tomato_cut.png");
}
void Tomato::cooked(int quality) {
	status = quality;
}


Mushroom::Mushroom(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/mushroom_uncut.png";
	std::cout << " Creating Mushroom" << std::endl;
	name = "mushroom";
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
std::string Mushroom::getName() {
	return name;
}
void Mushroom::cut() {
	status = 2;
	changeImage("../images/mushroom_cut.png");
}
void Mushroom::cooked(int quality) {
	status = quality;
}

Onion::Onion(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/onion_uncut.png";
	name = "onion";
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
std::string Onion::getName() {
	return name;
}
void Onion::cut() {
	status = 2;
	changeImage("../images/onion_cut.png");
}
void Onion::cooked(int quality) {
	status = quality;
}
Meat::Meat(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/meat_uncut.png";
	name = "meat";
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
std::string Meat::getName() {
	return name;
}
void Meat::cut() {
	status = 2;
	changeImage("../images/meat_cut.png");
}
void Meat::cooked(int quality) {
	status = quality;
}
Lettuce::Lettuce(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/lettuce_uncut.png";
	name = "lettuce";
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
std::string Lettuce::getName() {
	return name;
}
void Lettuce::cut() {
	status = 2;
	changeImage("../images/lettuce_cut.png");
}
void Lettuce::cooked(int quality) {
	status = quality;
}
Bun::Bun(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/bun_empty.png";
	name = "bun";
	std::cout << "initializing " << name << std:: endl;
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
std::string Bun::getName() {
	return name;
}
void Bun::cut() {
	std::cout << "You can't cut Bread dummy" <<std::endl;
}
void Bun::cooked(int quality) {
	std::cout << "You can't cook Bread dummy" << std::endl;
}