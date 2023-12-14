#pragma once

#include "gameobject.h"
#include "config.h"

class Player : public GameObject
{ 
private:  
    bool isTwo = true ;
    float speed = 1 ; //random canvas speed
    float pos_x = canvas_width-50;
    float pos_y = canvas_height/2 ;
    
public:
    void update() override;
    void draw() override ;
    void init() override;
    void setPlayer(bool a);
    bool getPlayer();
    float get_pos_x();
    float get_pos_y();
    Player();
    ~Player();

};
