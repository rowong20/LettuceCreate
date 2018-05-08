#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "TexRect.h"
#include "AnimatedRect.h"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
    
    void specialKeyPress(int key);
    
    void specialKeyUp(int key);
    
    void idle();
    
    TexRect* bun;
	TexRect* meat;
	TexRect* lettuce;
	TexRect* mushroom;
	TexRect* onion;
	TexRect* tomato;
    
    TexRect* pan1;
	TexRect* pot1;
	TexRect* board1;

	TexRect* pan2;
	TexRect* pot2;
	TexRect* board2;

	TexRect* dish1;
	TexRect* dish2;
	TexRect* trash;
	TexRect* serve;
    
    TexRect* background;
    
    //AnimatedRect* gameOver;
    
    bool up;
    bool down;
    bool left;
    bool right;
    
    bool moving;
    bool game_over;

	
    
    
};

#endif
