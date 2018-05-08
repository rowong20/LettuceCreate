#include "App.h"

static App* singleton;
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
    
    singleton = this;
    mx = 0.0;
    my = 0.0;

	//background = new TexRect("../images/sky.png", -1, 1, 2, 2);
    background = new TexRect("../images/whiteback.png", -1, 1, 2, 2);

    bun = new TexRect("../images/bun_empty.png", -0.9, -0.65, 0.2, 0.2);
	meat = new TexRect("../images/meat_uncut.png", -0.6, -0.65, 0.2, 0.2);
	lettuce = new TexRect("../images/lettuce_uncut.png", -0.3, -0.65, 0.2, 0.2);
	tomato = new TexRect("../images/tomato_uncut.png", 0.0, -0.65, 0.2, 0.2);
	mushroom = new TexRect("../images/mushroom_uncut.png", 0.3, -0.65, 0.2, 0.2);
	onion = new TexRect("../images/onion_uncut.png", 0.6, -0.65, 0.2, 0.2);

	pan1 = new TexRect("../images/pan_empty.png", -0.8, 0.4, 0.2, 0.3);
	pot1 = new TexRect("../images/pot_empty.png", -0.8, -0.1, 0.2, 0.3);
    board1 = new TexRect("../images/board.png", -0.1, 0.4, 0.3, 0.2);

	pan2 = new TexRect("../images/pan_empty.png", -0.5, 0.4, 0.2, 0.3);
	pot2 = new TexRect("../images/pot_empty.png", -0.5, -0.1, 0.2, 0.3);
	board2 = new TexRect("../images/board.png", -0.1, -0.1, 0.3, 0.2);

	dish1 = new TexRect("../images/plate.png", 0.3, 0.4, 0.2, 0.3);
	dish2 = new TexRect("../images/plate.png", 0.3, -0.1, 0.2, 0.3);
	trash = new TexRect("../images/trash.png", 0.7, -0.1, 0.2, 0.3);
	serve = new TexRect("../images/serve.png", 0.7, 0.4, 0.2, 0.3);
    
    //gameOver = new AnimatedRect("../images/game_over.png", 7, 1, -1.0, 0.8, 2, 1.2);
    
    up = down = left = right = false;
    
    moving = true;
    game_over = false;
    
    //app_timer(1);

}

int potpanTimer(float x, float y, bool full)						//0 = undercooked; 1 = cooked; 2 = overcooked
{
	if (full)
	{
		
	}
	return 0;
}

int cuttingTimer(float x, float y, bool full)						//0 = uncut; 1 = cut
{
	if (full)
	{

	}
	return 0;
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
	serve->draw(-0.3);
	trash->draw(-0.3);
	dish1->draw(-0.3);
	dish2->draw(-0.3);
	pan1->draw(-0.3);
	pot1->draw(-0.3);
	board1->draw(-0.3);
	pan2->draw(-0.3);
	pot2->draw(-0.3);
	board2->draw(-0.3);
	bun->draw(-0.4);
	meat->draw(-0.4);
	lettuce->draw(-0.4);
	tomato->draw(-0.4);
	mushroom->draw(-0.4);
	onion->draw(-0.4);
	
	
   
    
	//gameOver->draw();
	
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;

	if (singleton->bun->contains(x, y)) {
		mouseDrag(x, y);
	}
	else if(singleton->meat->contains(x, y)) {
		mouseDrag(x, y);
	}
	else if (singleton->onion->contains(x, y)) {
		mouseDrag(x, y);
	}
	else if (singleton->tomato->contains(x, y)) {
		mouseDrag(x, y);
	}
	else if (singleton->mushroom->contains(x, y)) {
		mouseDrag(x, y);
	}
	else if (singleton->lettuce->contains(x, y)) {
		mouseDrag(x, y);
	}
}

void App::mouseDrag(float x, float y){
    // Update app state
    //mx = x;
    //my = y;
	if (singleton->bun->contains(x, y)) {
		singleton->bun->x = x - bun->w/2;
		singleton->bun->y = y + bun->h/2;
		redraw();
	}
	else if (singleton->meat->contains(x, y)) {
		singleton->meat->x = x - meat->w / 2;
		singleton->meat->y = y + meat->h / 2;
		redraw();
	}
	else if (singleton->lettuce->contains(x, y)) {
		singleton->lettuce->x = x - lettuce->w / 2;
		singleton->lettuce->y = y + lettuce->h / 2;
		redraw();
	}
	else if (singleton->tomato->contains(x, y)) {
		singleton->tomato->x = x - tomato->w / 2;
		singleton->tomato->y = y + tomato->h / 2;
		redraw();
	}
	else if (singleton->mushroom->contains(x, y)) {
		singleton->mushroom->x = x - mushroom->w / 2;
		singleton->mushroom->y = y + mushroom->h / 2;
		redraw();
	}
	else if (singleton->onion->contains(x, y)) {
		singleton->onion->x = x - onion->w / 2;
		singleton->onion->y = y + onion->h / 2;
		redraw();
	}

}

void App::idle(){

}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        
        delete bun;
		delete meat;
		delete lettuce;
		delete tomato;
		delete mushroom;
		delete onion;
        delete board1;
		delete pan1;
		delete pot1;
		delete dish1;
		delete dish2;
		delete serve;
		delete trash;
        //delete gameOver;
        delete background;
        delete this;
        
        exit(0);
    }
    
    if (key == ' '){
        bun->x = 0;
		bun->y = 0.67;
		bun->yinc = 0.01;
		bun->xinc = 0.01;
		bun->rising = false;
        game_over = false;
        //gameOver->stop();
        moving = true;
    }
}
