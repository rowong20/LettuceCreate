#include "App.h"
    

static App* singleton;
Timer* pan1Timer;
Timer* pan2Timer;
int strikes = 0;
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
    
	background = new TexRect("../images/whiteback.png", -1, 1, 2, 2);
	pan1 = new pan( -0.8, 0.4, 0.2, 0.3);
	pot1 = new pot( -0.8, -0.1, 0.2, 0.3);
	board1 = new board( -0.1, 0.4, 0.3, 0.2);

	pan2 = new pan( -0.5, 0.4, 0.2, 0.3);
	pot2 = new pot( -0.5, -0.1, 0.2, 0.3);
	board2 = new board( -0.1, -0.1, 0.3, 0.2);

	plate1 = new plate( 0.3, 0.4, 0.2, 0.3);
	plate2 = new plate( 0.3, -0.1, 0.2, 0.3);

	containers.push_back(board1);
	containers.push_back(board2);
	containers.push_back(pan1);
	containers.push_back(pan2);
	containers.push_back(pot1);
	containers.push_back(pot2);
	
	containers.push_back(plate1);
	containers.push_back(plate2);
	trash = new TexRect("../images/trash.png", 0.7, -0.1, 0.2, 0.3);
	serve = new TexRect("../images/serve.png", 0.7, 0.4, 0.2, 0.3);


	//testing

	bun = new Bun(-0.9, -0.65, 0.2, 0.2);
	meat = new Meat(-0.6, -0.65, 0.2, 0.2);
	lettuce = new Lettuce(-0.3, -0.65, 0.2, 0.2);
	tomato = new Tomato(0.0, -0.65, 0.2, 0.2);
	mushroom = new Mushroom(0.3, -0.65, 0.2, 0.2);
	onion = new Onion(0.6, -0.65, 0.2, 0.2);

	ingredients.push_back(bun);
	ingredients.push_back(tomato);
	ingredients.push_back(onion);
	ingredients.push_back(lettuce);
	ingredients.push_back(meat);
	ingredients.push_back(mushroom);
	
	if (strikes == 0)
		gordon = new TexRect("../images/gordon_neutral.jpg", 0.7, 0.9, 0.3, 0.3);
	else if (strikes == 1)
		gordon = new TexRect("../images/gordon_mad.jpg", 0.7, 0.9, 0.3, 0.3);
	else if (strikes == 2)
		gordon = new TexRect("../images/gordon_burst.jpg", 0.7, 0.9, 0.3, 0.45);
	else
		game_over = true;

	
	
	
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
}/*
void App::reset(Ingredient* &processed) {
	Ingredient* brains;
	if (processed->getName() == "bun") {
		brains= new Bun(-0.9, -0.65, 0.2, 0.2);
	}
	if(processed->getName() == "meat")
		brains = new Meat(-0.6, -0.65, 0.2, 0.2);
	if (processed->getName() == "lettuce")
		brains = new Lettuce(-0.3, -0.65, 0.2, 0.2);
	if (processed->getName() == "tomato")
		brains = new Tomato(0.0, -0.65, 0.2, 0.2);
	if (processed->getName() == "mushroom")
		brains = new Mushroom(0.3, -0.65, 0.2, 0.2);
	if (processed->getName() == "onion")
		brains = new Onion(0.6, -0.65, 0.2, 0.2);
	redraw();
}
*/
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
	//platform->draw(-0.3);
	//ball->draw(-0.4);
	//tomato->draw(-0.5);

	serve->draw(-0.3);
	gordon->draw(-0.3);
	trash->draw(-0.3);

	for (int i = 0; i < containers.size(); i++) {
		containers[i]->draw(-0.5);
	}
	for (int i = 0; i < ingredients.size(); i++) {
		ingredients[i]->draw(-0.6);
	}

	gauge(0);
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state	
	//Cutting board code
	for (int i = 0; i < ingredients.size(); i++) {
		if (singleton->ingredients[i]->contains(x, y) && (board1->contains(ingredients[i]->x, ingredients[i]->y) || board2->contains(ingredients[i]->x, ingredients[i]->y))) {
			singleton->ingredients[i]->cut();
			sound.playS("../sounds/ChoppingVegetables.wav");
		}

	}
	//Pot code
	for (int i = 0; i < ingredients.size(); i++) {
		if (singleton->ingredients[i]->contains(x, y) && (pot1->contains(ingredients[i]->x, ingredients[i]->y))) {
			pot1->addIngredient(singleton->ingredients[i]);
			pot1->check();
			sound.playS("../sounds/PotBoiling.wav");
		}
		else if (singleton->ingredients[i]->contains(x, y) && pot2->contains(ingredients[i]->x, ingredients[i]->y))
		{
			pot2->addIngredient(singleton->ingredients[i]);
			pot2->check();
			sound.playS("../sounds/PotBoiling.wav");
		}

	}
	//pan
	for (int i = 0; i < ingredients.size(); i++) {
		if (singleton->ingredients[i]->contains(x, y) && (pan1->contains(ingredients[i]->x, ingredients[i]->y))) {
			pan1->addIngredient(singleton->ingredients[i]);
			pan1->check();
			sound.playS("../sounds/PanSizzle.wav");
		}
		else if (singleton->ingredients[i]->contains(x, y) && pan2->contains(ingredients[i]->x, ingredients[i]->y))
		{
			pan2->addIngredient(singleton->ingredients[i]);
			pan2->check();
			sound.playS("../sounds/PanSizzle.wav");
		}
	}
	//plate
	for (int i = 0; i < ingredients.size(); i++) {
		if (singleton->ingredients[i]->contains(x, y) && (plate1->contains(ingredients[i]->x, ingredients[i]->y))) {
			plate1->addIngredient(singleton->ingredients[i]);
			plate1->check();
		}
		else if (singleton->ingredients[i]->contains(x, y) && plate2->contains(ingredients[i]->x, ingredients[i]->y))
		{
			plate2->addIngredient(singleton->ingredients[i]);
			plate2->check();
		}
	}

}

void App::mouseDrag(float x, float y){
    // Update app state
    //mx = x;
    //my = y;
	//Cutting board code
	for (int i = 0; i < ingredients.size(); i++) {
		if (singleton->ingredients[i]->contains(x, y) && (board1->contains(ingredients[i]->x, ingredients[i]->y) || board2->contains(ingredients[i]->x, ingredients[i]->y))) {
			singleton->ingredients[i]->cut();
		}

	}
	//Pot code
	for (int i = 0; i < ingredients.size(); i++) {
		if (singleton->ingredients[i]->contains(x, y) && (pot1->contains(ingredients[i]->x, ingredients[i]->y))) {
			pot1->addIngredient(singleton->ingredients[i]);
			pot1->check();
			sound.playS("../sounds/PotBoiling.wav");
			//reset(ingredients[i]);
		}
		else if (singleton->ingredients[i]->contains(x, y) && pot2->contains(ingredients[i]->x, ingredients[i]->y))
		{
			pot2->addIngredient(singleton->ingredients[i]);
			pot2->check();
			sound.playS("../sounds/PotBoiling.wav");
			//reset(ingredients[i]);
		}

	}
	//pan
	for (int i = 0; i < ingredients.size(); i++) {
		if (singleton->ingredients[i]->contains(x, y) && (pan1->contains(ingredients[i]->x, ingredients[i]->y))) {
			pan1->addIngredient(singleton->ingredients[i]);
			pan1->check();
			sound.playS("../sounds/PanSizzle.wav");
			//reset(ingredients[i]);
		}
		else if (singleton->ingredients[i]->contains(x, y) && pan2->contains(ingredients[i]->x, ingredients[i]->y))
		{
			pan2->addIngredient(singleton->ingredients[i]);
			pan2->check();
			sound.playS("../sounds/PanSizzle.wav");
			//reset(ingredients[i]);
		}
	}
	//plate
	for (int i = 0; i < ingredients.size(); i++) {
		if (singleton->ingredients[i]->contains(x, y) && (plate1->contains(ingredients[i]->x, ingredients[i]->y))) {
			plate1->addIngredient(singleton->ingredients[i]);
			plate1->check();
			//reset(ingredients[i]);
		}
		else if (singleton->ingredients[i]->contains(x, y) && plate2->contains(ingredients[i]->x, ingredients[i]->y))
		{
			plate2->addIngredient(singleton->ingredients[i]);
			plate2->check();
			//reset(ingredients[i]);
		}
	}
	for (int i = 2; i < containers.size()-2; i++) {
		if (singleton->containers[i]->contains(x, y) && (plate1->contains(containers[i]->x, containers[i]->y))) {
			std::cout << "checking container" << std::endl;
			plate1->transfer(containers[i]);
			plate1->check();
			containers[i]->check();

		}
		else if (singleton->containers[i]->contains(x, y) && plate2->contains(containers[i]->x, containers[i]->y))
		{
			std::cout << "checking container" << std::endl;
			plate2->transfer(containers[i]);
			plate2->check();
			containers[i]->check();
		}
	}
	for (int i = 0; i < ingredients.size(); i++) {
		if (ingredients[i]->contains(x, y)) {
			ingredients[i]->x = x - ingredients[i]->w / 2;
			ingredients[i]->y = y + ingredients[i]->h / 2;
			redraw();
		}
	}
	for (int i = 2; i < containers.size(); i++) {
		if (containers[i]->contains(x, y)) {
			containers[i]->x = x - containers[i]->w / 2;
			containers[i]->y = y + containers[i]->h / 2;
			redraw();
		}
	}
	

}
void App::mouseUp(float x, float y) {
	// Update app state
	//mx = x;
	//my = y;
	//float objectx = tomato->x + tomato->w / 2;
	//float objecty = tomato->y - tomato->h / 2;
	//std::cout << "Coordinates of object is centered at: " << objectx << "," << objecty << std::endl;
	//if (platform->contains(objectx,objecty)){
//		std::cout << "adding ingredient" << singleton->tomato->getName()<<std::endl;
//		platform->addIngredient(tomato);
		//platform->addIngredient(s1);
		//platform->addIngredient(s2);
//platform->check();
		//delete tomato;
		
	//sound.playS("../sounds/GameOver.wav");


	//}
	
	redraw();
}

void App::idle(){

}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        
       // delete ball;
        //delete platform;
        delete gameOver;
      //  delete background;
        delete this;
        
        exit(0);
    }
	else if (key == 'a') {
		sound.playS("../sounds/MadLight.wav");
	}
	else if (key == 's') {
		sound.playS("../sounds/MadMedium.wav");
	}
	else if (key == 'd') {
		sound.playS("../sounds/GameOver.wav");
	}
	else if (key == 'z') {
		sound.playS("../sounds/GameWin.wav");
	}
	
}