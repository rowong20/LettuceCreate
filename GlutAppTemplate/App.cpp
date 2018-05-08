#include "App.h"
    

static App* singleton;
Timer* pan1Timer;
Timer* pan2Timer;
/*/
void app_timer(int value){
    if (singleton->game_over){
        singleton->gameOver->advance();
    }
    
    if (singleton->moving){
        singleton->ball->jump();
        float bx = singleton->ball->x + singleton->ball->w/2;
        float by = singleton->ball->y - singleton->ball->h + 0.1;
        if (singleton->platform->contains(bx, by)){
            singleton->ball->rising = true;
            singleton->ball->yinc +=0.005;
            singleton->ball->xinc = singleton->ball->yinc;
            if (singleton->ball->yinc > 0.15){
                singleton->ball->yinc = 0.15;
            }
        }
        
        if (singleton->ball->y - singleton->ball->h < -0.99){
            singleton->moving = false;
            singleton->game_over = true;
            singleton->gameOver->animate();
            
        }
    }
    if (singleton->up){
        singleton->platform->moveUp(0.05);
    }
    if (singleton->down){
        singleton->platform->moveDown(0.05);
    }
    if (singleton->left){
        singleton->platform->moveLeft(0.05);
    }
    if (singleton->right){
        singleton->platform->moveRight(0.05);
    }
    
    if (singleton->game_over){
        singleton->redraw();
        glutTimerFunc(100, app_timer, value);
    }
    else{
        if (singleton->up || singleton->down || singleton->left || singleton->right || singleton->moving && !singleton->game_over){
            singleton->redraw();
            glutTimerFunc(16, app_timer, value);
        }
    }
    
    
}*/

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
	sound.init("../sounds/OvercookedBGM.wav");
    singleton = this;
    mx = 0.0;
    my = 0.0;
    
    background = new TexRect("../images/board.png", -1, 1, 2, 2);
    ball = new TexRect("../images/mushroom_uncut.png", 0, 0.67, 0.2, 0.2);
	tomato = new Lettuce(.2, -0.7, 0.2, 0.2);
    platform = new pot( 0, 0, 0.4, 0.4);
    s1=new Meat(.3, -0.7, 0.2, 0.2);
	s2=new Tomato(.4 , -0.7, 0.2, 0.2);
    gameOver = new AnimatedRect("../images/knife.png", 7, 1, -1.0, 0.8, 2, 1.2);
    
	pan1Timer = new Timer(-0.8, 0.05);
	pan2Timer = new Timer(-0.5, 0.05);

    up = down = left = right = false;
    
    moving = true;
    game_over = false;
    
    //app_timer(1);

}

void gauge(int value)
{
	if (!pan1Timer->done()) {
		pan1Timer->advanceGauge();
		pan1Timer->drawPotGauge();
		glutPostRedisplay();
		glutTimerFunc(10000, gauge, value);
	}
	if (!pan2Timer->done()) {
		pan2Timer->advanceGauge();
		pan2Timer->drawPotGauge();
		glutPostRedisplay();
		glutTimerFunc(10000, gauge, value);
	}
	//cout << "w after advance: " << w << endl;				//testing
}

void App::specialKeyPress(int key){
    if (!game_over){
        if (key == 100){
            left = true;
        }
        if (key == 101){
            //up = true;
        }
        if (key == 102){
            right = true;
        }
        if (key == 103){
            //down = true;
        }
    }
}

void App::specialKeyUp(int key){
    if (key == 100) {
        left = false;
    }
    if (key == 101) {
        up = false;
    }
    if (key == 102) {
        right = false;
    }
    if (key == 103) {
        down = false;
    }
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	background->draw(0.1);

	glColor3f(1,1,1);
	platform->draw(-0.3);
	ball->draw(-0.4);
	tomato->draw(-0.5);
	gauge(0);
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
	if (singleton->tomato->contains(x, y)) {
		singleton->mouseDrag(x,y);
	}
}

void App::mouseDrag(float x, float y){
    // Update app state
    //mx = x;
    //my = y;
	if (singleton->tomato->contains(x, y)) {
		singleton->tomato->x = x- tomato->w/2;
		singleton->tomato->y = y + tomato->h/2;
		redraw();
	}

}
void App::mouseUp(float x, float y) {
	// Update app state
	//mx = x;
	//my = y;
	float objectx = tomato->x + tomato->w / 2;
	float objecty = tomato->y - tomato->h / 2;
	std::cout << "Coordinates of object is centered at: " << objectx << "," << objecty << std::endl;
	if (platform->contains(objectx,objecty)){
		std::cout << "adding ingredient" << singleton->tomato->getName()<<std::endl;
		platform->addIngredient(tomato);
		//platform->addIngredient(s1);
		//platform->addIngredient(s2);
		platform->check();
		delete tomato;
		sound.playS("../sounds/GameOver.wav");
	}
	redraw();

}

void App::idle(){

}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        
        delete ball;
        delete platform;
        delete gameOver;
        delete background;
        delete this;
        
        exit(0);
    }
	else if (key == 'p') {
		sound.playS("../sounds/PanSizzle.wav");
	}
    if (key == ' '){
        ball->x = 0;
        ball->y = 0.67;
        ball->yinc = 0.01;
        ball->xinc = 0.01;
        ball->rising = false;
        game_over = false;
        gameOver->stop();
        moving = true;
    }
}