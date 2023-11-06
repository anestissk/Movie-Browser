#include "widget.h"
#include "graphics.h"
#include "genrebutton2.h"
#include "button.h"


void Genrebutton2::update()
{
}

void Genrebutton2::draw()
{
	graphics::Brush br;
	SETCOLOR(br.fill_color, 0.5f, 0.5f, 0.5f);
	br.outline_opacity = 0.5f;
	graphics::drawRect(pos_x, pos_y, BUTTON_SIZE * 2.0f, BUTTON_SIZE / 2.0f, br);

}

void Genrebutton2::init()
{
}
bool Genrebutton2::contains(float x, float y) // a function for checking the coordinates of a button
{
	return distance(x, y, pos_x, pos_y) < BUTTON_SIZE;
}
