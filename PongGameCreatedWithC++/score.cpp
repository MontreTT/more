#include "score.h"
#include "config.h"
#include  <iostream>

// isOne checks if score is for player1 or player2:
Score::Score(bool a){
    isOne = a;
    if (isOne) {
        centerX = canvas_width/2 - scoreboard_size;
    } else {
        centerX = canvas_width/2 + scoreboard_size;
    }
}

Score::~Score(){
   // std::cout << "Destructing Score\n";
}
//updates score 
void Score::update() {
    graphics::Brush br;
    score++;
    std::string imgPath = std::string(aset_path)  + std::to_string(score) + ".png";
    br.texture = imgPath;
    br.gradient = false;
    //coloers to fill
    br.fill_color[0] = 0.0f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 0.0f;
    br.fill_secondary_color[0] = 240.f;
    br.fill_secondary_color[1] = 0.0f;
    br.fill_secondary_color[2] = 0.0f;
    br.fill_opacity= 1.0f;
    br.fill_secondary_opacity = 0.0f;
    br.outline_opacity = 0.f;
    graphics::drawRect(centerX , 65,scoreboard_size,scoreboard_size,br);
    // br.texture="";
}

//draws first score 0.0
void Score:: draw(){ 

    graphics::Brush br;
    std::string imgPath = std::string(aset_path)  + std::to_string(score) + ".png";

    br.texture = imgPath;
    br.outline_opacity = 0.f;
    graphics::drawRect(centerX , 65 ,scoreboard_size,scoreboard_size,br);
    br.texture = "";
}

// void Score:: draw(){ 
//     graphics::Brush br;

//     if(isOne == true){
//         br.texture = std::string(aset_path) + "0.png";
//         br.outline_opacity = 0.f;
//         graphics::drawRect(canvas_width/2 - scoreboard_size , 65 ,scoreboard_size,scoreboard_size,br);
//         br.texture = "";
//     }
//     else{
        
//         br.texture = std::string(aset_path) + "0.png";
//         br.outline_opacity = 0.f;
//         graphics::drawRect(canvas_width/2 +scoreboard_size , 65 ,scoreboard_size,scoreboard_size,br);
//         br.texture="";

//     }
// }
void Score::init(){

}
//gives score number
int Score::get_score(){
    return score;
}
//sets score
void Score::set_score(int score){
    score = score;
}
