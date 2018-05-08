#include "Ingredient.h"
#include <iostream>
Ingredient::Ingredient() {
	std::cout << "Creating Ingredient"<<std::endl;
}

Tomato::Tomato(float x = 0, float y = 0, float w = 0.5, float h = 0.5) {
	const char* filename = "../images/tomato_uncut.png";
	std::cout << " Creating Tomato"<<std::endl;
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
int Tomato::getStatus() {
	return status;
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
int Mushroom::getStatus() {
	return status;
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
int Onion::getStatus() {
	return status;
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
int Meat::getStatus() {
	return status;
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
int Lettuce::getStatus() {
	return status;
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
int Bun::getStatus() {
	return status;
}
void Bun::cut() {
	std::cout << "You can't cut Bread dummy" << std::endl;
}
void Bun::cooked(int quality) {
	std::cout << "You can't cook Bread dummy" << std::endl;
}