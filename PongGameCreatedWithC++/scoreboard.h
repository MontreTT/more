#pragma once
#include "player.h"
#include "graphics.h"
#include "score.h"
//scoreboard has 2 score objercts one for player 1 ,one for player 2
class Scoreboard:public GameObject{

private:
    Score* score1 = new Score(true);
    Score* score2 = new Score(false);

public:
    int return_max_score();
    void update(Player* player) ;
    void update() override;
    void draw() override ;
    void init() override;
    int getGameOver();
    Scoreboard();
    ~Scoreboard();
};