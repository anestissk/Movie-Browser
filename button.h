#pragma once
#include "widget.h"
#include "config.h"
class Button : public Widget {

    float pos_x = CANVAS_WIDTH / 2 + 450;
    float pos_y = CANVAS_HEIGHT / 2 - 250;

public:
    //overriding the draw,init,update functions which are inherited by the Widget abstract class
    void draw() override;
    void init() override;
    bool contains(float x, float y);
    void update() override;

};