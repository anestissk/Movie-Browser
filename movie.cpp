#include "movie.h"
#include "graphics.h"
#include "config.h"

void Movie::draw()
{
	graphics::Brush br;
	
	float h = 1.0f * m_highlighted; 
	SETCOLOR(br.fill_color, h *0.7f, h, h); //set the highlighter's color only if the cursor hovers over a movie
	br.outline_opacity = 1.0f * m_active;
	graphics::drawRect(m_pos[0], m_pos[1], MOVIE_SIZE*1.03f , MOVIE_SIZE*1.03f , br);

	SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSET_PATH) + getImagepath(); // set the poster image for each movie in the canvas
	graphics::drawRect(m_pos[0], m_pos[1],MOVIE_SIZE, MOVIE_SIZE, br);


	drawText(m_pos[0] - 70.0f, m_pos[1] + 75.0f, MOVIE_SIZE * 0.12f, std::string(getTitle()) , br); // title of each movie under their poster
	
}


void Movie::update(){
}

bool Movie::contains(float x, float y) // a function for checking the coordinates of a Movie 
{
	return distance(x, y, m_pos[0], m_pos[1]) < MOVIE_SIZE - 50.f  ;
}
