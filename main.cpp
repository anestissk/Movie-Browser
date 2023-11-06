#include "graphics.h"
#include <vector>
#include "movie.h"
#include "filter.h"
#include "config.h"
#include <string>
#include <iostream>
#include "browser.h"

using namespace std;

void draw() {
	Browser* mybrowser = Browser::getInstance(); // use the instance of the Browser class
	
	mybrowser->draw();
}

void update(float ms) {
	Browser* mybrowser = Browser::getInstance();

	mybrowser->update();
}


int main(int argc , char ** argv) {
	//creating the window app and setting the canvas size
	graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Movie Browser"); 


	Browser* browser = Browser::getInstance();
	
	browser->init();
	graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
	
	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);


	graphics::startMessageLoop();
	
	delete browser; // delete the browser when we exit the app
	
	return 0;

}

	
