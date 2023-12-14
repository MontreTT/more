#pragma once
#include <cstdlib>
#include <ctime>
#include "gameobject.h"
#include "config.h"
#include "graphics.h"

class Ball : public GameObject{
    private:
        
        //int  a = int(graphics::getGlobalTime())*10000 % 2;
        //int  b = int(graphics::getGlobalTime())*10000 % 2;
        float x_speed = 1;//canvas ball speed
        float y_speed = 1;
        //bool x_to_right = a;
        //bool y_to_down = b;
        float pos_x = canvas_width/2;
        float pos_y =  canvas_height/2;

    public:
        void update() override;
        void draw() override ;
        void init() override;
        void change_x_speed();
        void change_y_speed();
        void set_pos_x(float);
        void set_pos_y(float);
        float get_pos_x();
        float get_pos_y();
        Ball();
        ~Ball();
};