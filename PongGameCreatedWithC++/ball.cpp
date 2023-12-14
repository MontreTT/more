#include "ball.h"
#include "graphics.h"

void Ball::update(){
    //if ball is out of range left
    if (pos_x < ball_ray){
       change_x_speed();

    }
    // ball is out of position right
    else if (pos_x > canvas_width - ball_ray){
        change_x_speed();
        
    }
    //if ball out of position top
    if(pos_y < ball_ray + 1){
        change_y_speed();
    }
    //if ball out of position bottom
   else if(pos_y > canvas_height - ball_ray){
       change_y_speed();

   }
   pos_x += x_speed;
   pos_y += y_speed; 
}

//draw ball
void Ball::draw(){
    
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
    graphics::drawDisk(pos_x,pos_y,ball_ray,br);
    
}
void Ball::init(){

}
// changes ball direction x axis
void Ball::change_x_speed(){
    x_speed = -x_speed;
}
// changes ball direction y axis
void  Ball::change_y_speed(){
    y_speed = -y_speed;
}
//gets ball position x axis
float Ball::get_pos_x(){
    return pos_x;

}
// gets balls position y axis
float Ball::get_pos_y(){
    return pos_y;

}
//sets ball positions x axis;
void Ball::set_pos_x(float x){
    pos_x = x ;

}
//sets ball position y axis
void Ball::set_pos_y(float x){
    pos_y = x ;

}

Ball::Ball(){

}

Ball::~Ball(){
}
