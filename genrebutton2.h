
#pragma once
#include "widget.h"
#include "config.h"
#include "button.h"


class Genrebutton2 : public Button {

    float pos_x = CANVAS_WIDTH / 100.0f + 50.0f;
    float pos_y = CANVAS_HEIGHT / 4 + 170;

public:
    //overriding the draw,init,update functions which are inherited by the Button>Widget class
    void draw() override;
    void init() override;
    bool contains(float x, float y);
    void update() override;

};