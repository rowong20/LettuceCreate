#ifndef App_hpp
#define App_hpp
#include "../visualc15/Timer.h"
#include "GlutApp.h"
#include "TexRect.h"
#include "AnimatedRect.h"
#include "../visualc15/Ingredient.h"
#include "Sound.h"
#include "../visualc15/container.h"
class App: public GlutApp {
    // Maintain app state here
	Sound sound;
	irrklang::ISoundEngine* se;
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
	void mouseUp(float x, float y);
    void specialKeyPress(int key);
    
    void specialKeyUp(int key);
    
    void idle();
    
    TexRect* ball;
    
    container* platform;
    
    TexRect* background;
    
	Ingredient* tomato;
	Ingredient* s1;
	Ingredient* s2;

    AnimatedRect* gameOver;
    
    bool up;
    bool down;
    bool left;
    bool right;
    
    bool moving;
    bool game_over;

	
    
    
};

#endif
