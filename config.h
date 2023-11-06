#pragma once

#define ASSET_PATH "assets\\"
#define WINDOW_WIDTH 1100
#define WINDOW_HEIGHT 700
#define CANVAS_WIDTH 1000
#define CANVAS_HEIGHT 600
#define MOVIE_SIZE 125.0f
#define BUTTON_SIZE 50.0f
#define SETCOLOR(c,r,g,b){c[0]=r,c[1]=g;c[2]=b;}

inline float distance(float x1, float y1, float x2, float y2) {

	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx + dy * dy);

}