#pragma once
#include "graphics.h"
#include "movie.h"
#include <vector>
#include "widget.h"
#include "backbutton.h"
#include "genrebutton.h"
#include "genrebutton2.h"

class Browser {

	static Browser* m_instance; // create a browser instance
	typedef enum { STATUS_MAIN, STATUS_SELECTED, STATUS_FILTERED } status_t; // STATUS_MAIN: when we are browsing in the main screen ,STATUS_SELECTED: when we are browsing in the movie info screen
	std::vector <Movie*> m_movies;  //create a vector where movies will be stored
	std::vector<Movie*> filteredMovies; // vector for filtered movies
	Movie* m_active_movie = nullptr; //create a active movie from Movie ptr , initially setting it to null
	Button* button = nullptr;	//create a button from Button ptr, initially setting it to null
	Genrebutton1* genrebutton1 = nullptr;
	Genrebutton2* genrebutton2 = nullptr;
	
	Browser() {}
public:
	void draw();
	void init();
	void update();
	void drawMovieScreen(Movie* movie);
	void drawMainBrowser();
	void updateMainBrowser();
	void drawFilteredScreen(std::vector<Movie*>, std::string(genre));
	void updateFilteredScreen();
	void updateMovieScreen();
	status_t status = STATUS_MAIN; // initial status = STATUS_MAIN (draw the main browser screen)


	~Browser();

	static Browser* getInstance();

};

