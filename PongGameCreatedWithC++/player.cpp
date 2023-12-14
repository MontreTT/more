#include "player.h"
#include "graphics.h"
#include <iostream>
// isTwo check if player is player1 or player 2
void Player::update(){
    if(isTwo == false){
        //move player y axis;
        if (graphics::getKeyState(graphics::SCANCODE_W)){
        pos_y -= speed * graphics::getDeltaTime();

        }
        if (graphics::getKeyState(graphics::SCANCODE_S )){
        pos_y += speed * graphics::getDeltaTime();
        
        }
    
        if(pos_y < player_height/2 +1){
        pos_y = player_height/2 +1;
        }
        if(pos_y > canvas_height -player_height/2){
        pos_y= canvas_height -player_height/2 ;
        }
    }
    else if(isTwo == true){
        if (graphics::getKeyState(graphics::SCANCODE_UP)){
        pos_y -= speed * graphics::getDeltaTime();

        }
        if (graphics::getKeyState(graphics::SCANCODE_DOWN )){
        pos_y += speed * graphics::getDeltaTime();
        
        }
    
        if(pos_y < player_height/2 +1){
            pos_y = player_height/2 +1;
        }
        if(pos_y > canvas_height -player_height/2 ){
            pos_y= canvas_height -player_height/2 ;
        }
    }
}
// draw player start
void Player::draw(){

    if(isTwo== true){
    graphics::Brush br;
    br.texture = std::string(aset_path) + "pongplayer.png";
    
    br.texture = "";
    br.gradient = true;
    //coloers to fill
    br.fill_color[0] = 0.0f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 0.0f;
    br.fill_secondary_color[0] = 1.0f;
    br.fill_secondary_color[1] = 1.0f;
    br.fill_secondary_color[2] = 1.0f;
    br.fill_opacity= 1.0f;
    br.fill_secondary_opacity = 0.0f;
    graphics::drawRect(pos_x , pos_y,player_width,player_height,br);
    }
    else if(isTwo == false){
    graphics::Brush br;
    br.texture = std::string(aset_path) + "pongplayer.png";
    
    br.texture = "";
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
    pos_x = 50;
    graphics::drawRect(pos_x  , pos_y,player_width,player_height,br);
    
    }
    

}
void Player::init(){

}
void Player::setPlayer(bool a){
    isTwo = a ;
    

}
bool Player::getPlayer(){
    return isTwo;

}
float Player::get_pos_x(){
    return pos_x;

}
float Player::get_pos_y(){
    return pos_y;

}

Player::Player(){

}

Player::~Player(){
    std::cout << "Destructing Player\n";
}
