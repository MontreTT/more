#include "graphics.h"
#include "game.h"
#include "config.h"
 
// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
   Game* game = reinterpret_cast<Game*>(graphics::getUserData());
   game->update();

}
 
// The window content drawing function.
void draw()
{
   Game* game = reinterpret_cast<Game*> (graphics::getUserData());
   game->draw();
}
 
int main()
{  //GAME 
    Game mygame;
    //window size
    graphics::createWindow(window_width,window_height ,"Pongers");
    
    graphics::setUserData(&mygame);
 
    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);
 
    graphics::setCanvasSize(canvas_width,canvas_height );
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
    
    graphics::Brush br; // TODO: Initialize it.
    br.fill_color[0] = 0.5f;
    br.fill_color[1] = 0.7f;
    br.fill_color[2] = 0.9f;
    graphics::setWindowBackground(br);
    
    graphics::setFont("assets\\orange juice 2.0.ttf");
    mygame.init();
    graphics::startMessageLoop();
 
    return 0;
}