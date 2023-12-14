#pragma once

#include "ball.h"
#include "player.h"
#include "config.h"
#include "scoreboard.h"

class Game { 

private:
    Scoreboard* scoreboard;
    Player* player1;
    Player* player2;
    Ball* ball;

public:
    void update();
    void draw();
    void init();
    Game();
    ~Game();

};


