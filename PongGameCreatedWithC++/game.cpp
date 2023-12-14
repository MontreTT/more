#include "game.h"
#include "graphics.h"
#include "config.h"
#include <string>
#include <iostream>
#include "ball.h"

void Game::update(){
    //update player movement:
    if(player1){
        player1->update();
    }
    
    if(player2){
        player2->update();
    }
    //update ball movement:
    if(ball){ 

        //check for colision with player2
        if(ball->get_pos_x() + ball_ray >= player2->get_pos_x() + player_width/2 && ball->get_pos_y() + ball_ray >  player2->get_pos_y() - player_height/2 && ball->get_pos_y() + ball_ray < player2->get_pos_y() +  player_height/2 || ball->get_pos_x() + ball_ray >= player2->get_pos_x() + player_width/2 && ball->get_pos_y() - ball_ray >=  player2->get_pos_y() - player_height/2 && ball->get_pos_y() - ball_ray <= player2->get_pos_y() +  player_height/2 ){
            int temp = player2->get_pos_x()-2;
            ball->set_pos_x(temp);
            ball->change_x_speed();

       }
       // check for goal
        else if(ball->get_pos_x() + ball_ray > player2->get_pos_x() + player_width/2){
            std::cout <<"goal for player 1";
            scoreboard->update(player1);
            ball->set_pos_x(canvas_width/2);
            ball->set_pos_y(canvas_height/2);
       }
       //check for collision with player 1
       if(ball->get_pos_x() <  player1->get_pos_x() && ball->get_pos_y() + ball_ray >=  player1->get_pos_y() - player_height/2 && ball->get_pos_y() + ball_ray < player1->get_pos_y() +  player_height/2 || ball->get_pos_x() < player1->get_pos_x()  && ball->get_pos_y() - ball_ray >=  player1->get_pos_y() - player_height/2 && ball->get_pos_y() - ball_ray <= player1->get_pos_y() +  player_height/2 ){
            int temp = player1->get_pos_x()+player_width/2 +1;
            
            //std::cout << ball->get_pos_x();
            ball->set_pos_x(temp);
            //std::cout << player1->get_pos_x();
            ball->change_x_speed();
            //std::cout << player2->get_pos_x();
           // std::cout <<"poggers";

        }
        //check for goal 
        else if(ball->get_pos_x()  < player1->get_pos_x() ){
            std::cout <<"goal for player 2 ";
            scoreboard->update(player2);
            ball->set_pos_x(canvas_width/2);
            ball->set_pos_y(canvas_height/2);
       }
        
       int playerWon = scoreboard->getGameOver();
       if (playerWon == -1) {
          ball->update();
       }
    }

}

void Game::draw(){
    graphics::Brush br; // TODO: initialize it.
    br.texture = std::string(aset_path) + "spaceTheme.png";
    br.outline_opacity = 0.f; //perigramma gurw gurw width = 1
    float moving_width = canvas_width *sin(graphics::getGlobalTime()/50000)/2;
    //draw background
    graphics::drawRect(moving_width,moving_width,canvas_width*4,canvas_height*4,br ); // kentro width , kentro height , width height ,background 
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
    //draw players
    if(player1){
        player1->draw();
        
        
    }
    
    if(player2){
        player2->draw();
    }
    if(ball){
        ball->draw();
    }
    if(scoreboard){
        scoreboard->draw();
    }
    


}

void Game::init(){
graphics::playSound(std::string(aset_path) + sound_file,3,true )	;

}
//constructor game
Game::Game(){
    scoreboard = new Scoreboard();
    player1 = new Player();
    player2= new Player();
    player1->setPlayer(false);
    ball = new Ball();
}

Game::~Game(){
    if(player1){
        delete player1;

    }
    if(player2){ //akraia periptwsi na exei katastrafei kapou mesa sto game;
        delete player2;

    }
    if(ball){
        delete ball;
    }


}