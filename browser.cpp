#include "movie.h"
#include "graphics.h"
#include "config.h"
#include "browser.h"
#include "scancodes.h"
#include <string>
#include <iostream>
#include "widget.h"
#include "button.h"

void Browser::init() {

	graphics::setFont("assets\\BLKCHCRY.TTF");
	button = new Button();
	genrebutton1 = new Genrebutton1();
	genrebutton2 = new Genrebutton2();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			Movie* movie1 = new Movie("Taxi Driver", 1976, "Martin Scorsese", "Robert De Niro", "", "Crime", "Drama", "Vietnam vet Travis Bickle is a loner in the mean streets of New York City, slipping slowly into isolation and violent misanthropy.", "taxidriver1.png", "taxidriver2.png");
			Movie* movie2 = new Movie("Pulp Fiction", 1994, "Quentin Tarantino", "John Travolta", "Uma Thurman", "Crime", "Drama", "The lives of two mob hitmen, a boxer, a gangster and his wife,and a pair of diner bandits intertwine in four tales of violence and redemption.", "pulpfiction1.png", "pulpfiction2.png");
			Movie* movie3 = new Movie("Django Unchained", 2012, "Quentin Tarantino", "Jamie Foxx", "Christoph Waltz", "Drama", "Western", "With the help of a German bounty-hunter, a freed slave sets out to rescue his wife from a brutal plantation-owner in Mississippi.", "django1.png", "django2.png");
			Movie* movie4 = new Movie("The Hunt", 2012, "Thomas Vinterberg", "Mads Mikkelsen", "", "Drama", "", "A teacher lives a lonely life, all the while struggling over his son's custody. His life slowly gets better as he finds love and receives good news from his son, but his new luck is about to be brutally shattered by an innocent little lie. ", "thehunt1.png", "thehunt2.png");
			Movie* movie5 = new Movie("The Hunger Games", 2012, "Gary Ross", "Jennifer Lawrence", "Josh Hutcherson", "Action", "Adventure", "Katniss Everdeen joins the Hunger Games: a televised competition in which two teenagers from each of the twelve Districts of Panem are chosen at random to fight to the death. ", "hg1.png", "hg2.png");
			Movie* movie6 = new	Movie("The Hunger Games:Catching Fire", 2013, "Francis Lawrence", "Jennifer Lawrence", "Josh Hutcherson", "Action", "Adventure", "Katniss Everdeen and Peeta Mellark become targets of the Capitol after their victory sparks a rebellion in the Districts of Panem. ", "hgcf1.png", "hgcf2.png");
			Movie* movie7 = new Movie("Reservoir Dogs", 1992, "Quentin Tarantino", "Harvey Keitel", "Tim Roth", "Crime", "Thriller", "When a simple jewelry heist goes horribly wrong, the surviving criminals begin to suspect that one of them is a police informant. ", "resdogs1.png", "resdogs2.png");
			Movie* movie8 = new Movie("The Lighthouse", 2019, "Robert Eggers", "Robert Pattinson", "Willem Defoe", "Horror", "Thriller", "Two lighthouse keepers try to maintain their sanity while living on a remote and mysterious New England island in the 1890s. ", "thelighthouse1.png", "lighthouse2.png");
			Movie* movie9 = new Movie("Gone Girl", 2014, "David Fincher", "Rosamund Pike", "Ben Affleck", "Drama", "Thriller", "With his wife's, a man sees the spotlight turned on him when it's suspected that he may not be innocent.", "gonegirl1.png", "gonegirl2.png");
			Movie* movie10 = new Movie("The Social Network", 2010, "David Fincher", "Jesse Eisenberg", "Andrew Garfield", "Biography", "Drama", "As Harvard student Mark Zuckerberg creates the social networking site that would become known as Facebook.", "socialnetwork1.png", "socialnetwork2.png");
			Movie* movie11 = new Movie("Shutter Island", 2010, "Martin Scorsese", "Leonardo DiCaprio", "", "Mystery", "Thriller", "In 1954, a U.S. Marshal investigates the disappearance of a murderer who escaped from a hospital for the criminally insane.", "shutterisland1.png", "shutterisland2.png");
			Movie* movie12 = new Movie("Midsommar", 2019, "Ari Aster", "Florence Pugh", "Jack Reynor", "Horror", "Mystery", "A dysfunctional couple travels to Sweden for a midsummer festival, only to find themselves in the clutches of a sinister cult.", "midsommar.png", "midsommar2.png");
			Movie* movie13 = new Movie("Hereditary", 2018, "Ari Aster", "Toni Collette", "", "Horror", "Drama", "A grieving family is haunted by tragic and disturbing occurrences.", "hereditary.png", "hereditary2.png");
			Movie* movie14 = new Movie("The VVitch", 2015, "Robert Eggers", "Anya Taylor-Joy", "", "Horror", "Fantasy", "A family in 1630s New England is torn apart by the forces of witchcraft, black magic and possession.", "thewitch.png", "thewitch2.png");
			Movie* movie15 = new Movie("Everything Everywhere All at Once", 2022, "Dan Kwan", "Michelle Yeoh", "Stephanie Hsu", "Fantasy", "Action", "An aging Chinese immigrant is swept up in an insane adventure, in which she alone can save the world by exploring other universes.", "eeoao.png", "eeoao2.png");
			Movie* movie16 = new Movie("Whiplash", 2014, "Damien Chazelle", "Miles Teller", "J.K. Simmons", "Drama", "Music", "The film follows the ambitious music student and jazz drummer Andrew Neiman, who is pushed to his limit by his abusive instructor Fletcher.", "whiplash.png", "whiplash2.png");

			//add movies to the m_movies vector
			m_movies.push_back(movie1); m_movies.push_back(movie2);
			m_movies.push_back(movie3); m_movies.push_back(movie4); m_movies.push_back(movie5);
			m_movies.push_back(movie6); m_movies.push_back(movie7); m_movies.push_back(movie8); m_movies.push_back(movie9);
			m_movies.push_back(movie10); m_movies.push_back(movie11); m_movies.push_back(movie12); m_movies.push_back(movie13);
			m_movies.push_back(movie14); m_movies.push_back(movie15); m_movies.push_back(movie16);

			//Set position in the canvas for each movie in the m_movies vector
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					int index = 4 * i + j; // Calculate the index of the movie object in the vector
					m_movies[index]->setPosX(CANVAS_WIDTH * (i + 0.3f) / 4.0f);
					m_movies[index]->setPosY(CANVAS_HEIGHT * (j + 0.5f) / 4.0f);
					
				}
			}
		}
	}
}

//We couldn't finish this one. But the concept of the FilteredScreen is : if the selected genre (genre1 or genre2) is the same for some movies in the m_movies vector
// we insert these movies (with the push_back function) in the filteredMovies vector. Then we draw the filteredMovies like we did in the init function.
// the drwaFilteredScreen is drawn when we set the status to STATUS_FILTERED. So, in draw() if status==STATUS_FILTERED , drawFilteredScreen(std::vector<Movie*>, std::string(genre)) is called.


void Browser::drawFilteredScreen(std::vector<Movie*>, std::string(genre)) 
{
	for (auto movie : m_movies) {
		if (movie->getGenre1() == genre || movie->getGenre2() == genre) {
			filteredMovies.push_back(movie);
		}
	}
	for (int i = 0; i < 4; i++) {
		int index = i; 
		filteredMovies[index]->setPosX(CANVAS_WIDTH * (i + 0.3f) / 4.0f);
		filteredMovies[index]->setPosY(CANVAS_HEIGHT * (i + 0.5f) / 4.0f);
	}
	status = STATUS_FILTERED;
	
	graphics::Brush br;

	br.texture = ASSET_PATH + std::string("backround2.png");
	SETCOLOR(br.fill_color, 0.45, 0.15, 0.45);
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	//draw the movies from the filteredmovies vector, using draw() from the Movie Class
	for (auto movie : filteredMovies) {
		movie->draw();
	}
}

void Browser::updateFilteredScreen() // in this screen we can go back to the mainscreen by deleting the filter 
{
}

// draw a window which contains information about the current active movie
void Browser::drawMovieScreen(Movie* movie){

	graphics::Brush br;
	graphics::setFont("assets\\OpenSans-Bold.ttf");
	
	//draw background 	 
	br.texture = ASSET_PATH + std::string(m_active_movie->getImagepath2());
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	// give info for the selected-active movie .(director, year, genres, main actors/actresses and a summary)
	graphics::drawText(CANVAS_WIDTH / 80, CANVAS_HEIGHT /5, 50, m_active_movie->getTitle(), br);
	graphics::drawText(CANVAS_WIDTH / 80, CANVAS_HEIGHT / 4 + 100, 25, "Directed by : " + m_active_movie->getDirector() + ", " +std::to_string(m_active_movie->getYear()), br);
	graphics::drawText(CANVAS_WIDTH / 80, CANVAS_HEIGHT / 4 + 140, 15, m_active_movie->getGenre1() , br);
	graphics::drawText(CANVAS_WIDTH / 80, CANVAS_HEIGHT / 4 + 180, 15, m_active_movie->getGenre2(), br);
	graphics::drawText(CANVAS_WIDTH / 80, CANVAS_HEIGHT / 4 + 220, 25, "Starring : "+ m_active_movie->getMainActor1() +", " + m_active_movie->getMainActor2(), br);

		
	// create a backbutton and the genre buttons 
	if (button)
		button->draw();

	if (genrebutton1)
		genrebutton1->draw();
	
	if (m_active_movie->getGenre2() != "") {
		if (genrebutton2)
			genrebutton2->draw();
	}

	graphics::drawText(CANVAS_WIDTH / 80, CANVAS_HEIGHT / 4 + 260, 25, "Short Summary : " , br);
	graphics::drawText(CANVAS_WIDTH / 80, CANVAS_HEIGHT / 4 + 290, 15, m_active_movie->getSummary(), br);

	m_movies.clear(); // clear the m_movies vector everytime we select a movie and get off the main browser screen
}

//draw the main browser screen
void Browser::drawMainBrowser() {

	graphics::Brush br;

	br.texture = ASSET_PATH + std::string("backround2.png");
	SETCOLOR(br.fill_color, 0.45, 0.15, 0.45);
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	//draw the movies from the m_movies vector, using draw() from the Movie Class
	for (auto movie : m_movies) {
		movie->draw();
	}

}
void Browser::draw() {
	
	
	if (status == STATUS_SELECTED and m_active_movie) { //draw the Movie Screen which gives information about the selected movie
		drawMovieScreen(m_active_movie);

	}
	else if (status == STATUS_MAIN) { // draw the main browser screen ( no movie is selected )
		drawMainBrowser();
	}
	//else if (status == STATUS_FILTERED){
		//drawFilteredScreen(filteredMovies, cur_genrebutton)
	//}
}

void Browser::update()
{

	if (status == STATUS_MAIN)
	{

		updateMainBrowser();
	}
	else if(status == STATUS_SELECTED)
	{
		updateMovieScreen();
	}
	else {
		updateFilteredScreen();
	}

}

void Browser::updateMainBrowser() {
	for (auto movie : m_movies) {
		movie->update();
	}

	graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);


	// Çighlighô a movie when we hover over it
	Movie* cur_movie = nullptr;
	for (auto movie : m_movies) {
		if (movie->contains(mx, my)) { // check if the cursor is on a specific movie 

			movie->setHighlight(true);
			cur_movie = movie;
		}
		else { movie->setHighlight(false); }
	}

	//A movie becomes active when we left click on it
	if (ms.button_left_pressed && cur_movie) {

		m_active_movie = cur_movie;
		m_active_movie->setActive(true);
		status = STATUS_SELECTED;
		for (auto movie : m_movies) {
			if (movie != m_active_movie) {
				movie->setActive(false);
			}
		}

	}
}

void Browser::updateMovieScreen() { 
	
	graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);

	Button* cur_button = nullptr;
	

	if (graphics::getKeyState(graphics::SCANCODE_SPACE)) //use 'space' to return to the MainBrowser Screen by changing the status
	{
		status = STATUS_MAIN;
		init();
	}
	if (button->contains(mx, my)) { // check if the cursor is on a specific button
		cur_button = button;
	}
	if (ms.button_left_pressed && cur_button) {

		delete button;
		status = STATUS_MAIN;
		init();

	}

	//Currently the genrebuttons are used like the backbutton

	//but the concept for the genrebutton is that if we click on a specific genre-button , the status is changed to STATUS_FILTERED , so we call the
	//void Browser::drawFilteredScreen(std::vector<Movie*>, std::string(genre)) , where the genre would be the one we clicked on.
	// so it filters the m_movies vector based on the genrebutton.


	if (genrebutton1->contains(mx, my)) { // check if the cursor is on a specific button
		cur_button = genrebutton1;
	}	
	if (genrebutton2->contains(mx, my)) { // check if the cursor is on a specific button
		cur_button = genrebutton2;
	}
	
	
	if (ms.button_left_pressed && cur_button) {
		delete genrebutton1;
		delete genrebutton2;
		status = STATUS_MAIN;
		init();
	}

	

	
}
	


//browser destructor
Browser::~Browser()
{
	for (auto m : m_movies) {
		delete m;
	}
	m_movies.clear();
}

Browser* Browser::getInstance()
{
	if (!m_instance)
		m_instance = new Browser();
	return m_instance;

}

Browser* Browser::m_instance = nullptr;
