#include "button.h"
#include "browser.h"
#include "graphics.h"
#include "config.h"


void Button::update()
{
}

void Button::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "backbutton.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(pos_x, pos_y, BUTTON_SIZE, BUTTON_SIZE,br);
}

void Button::init()
{
}
bool Button::contains(float x, float y) // a function for checking the coordinates of a button
{
	return distance(x, y, pos_x, pos_y) < BUTTON_SIZE;
}
