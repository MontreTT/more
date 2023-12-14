#include "scoreboard.h"
#include <iostream>
#include <string>

 void Scoreboard::update(Player* player) {
    if(player->getPlayer()== true){
        score2->update();
    }
    else{
        score1->update();
    }

    Score x(false);
    Score y = new Score(true);
 }

 int Scoreboard::getGameOver() {
     if (score1->get_score() == gameOverScore) {
         return 1;
     } else if (score2->get_score() == gameOverScore) {
         return 2;
     } else {
         return -1;
     }
 }


 void Scoreboard::draw() {
        graphics::Brush br1;
        //std::cout << "poggers";
        br1.texture = std::string(aset_path) + "score.png";
        br1.outline_opacity = 0.f;
        graphics::drawRect(canvas_width/2 , 20 ,2.5* scoreboard_size,scoreboard_size,br1);
        score1->draw();
        score2->draw();

        
        

 }
 void Scoreboard::update(){

 }
 void Scoreboard::init() {

 }

Scoreboard::Scoreboard(){
}

Scoreboard::~Scoreboard(){
    std::cout << "Destructing Scorebard\n";
}
int Scoreboard:: return_max_score(){
    return 0;
    // int k = 0;
    // if(){

    // }
}