#pragma once

#include "gameobject.h"
#include "graphics.h"

class Score:public GameObject{

private:
    bool isOne;
    int score = 0;
    int centerX = 0;
    bool winner_1;
public:
    
    void update() override;
    void draw() override ;
    void init() override;
    int get_score();
    void set_score(int);
    bool get_winner();
    Score(bool);
    ~Score();

};