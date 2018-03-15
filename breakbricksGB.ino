#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;

bool started = false;

void setup() {
  // put your setup code here, to run once:
  gb.begin(); //initialize the Gamebuino
  gb.titleScreen(F("Casse Briques")); //shows the main menu
  initPlayer();
  initBricks();
  initBall();
}

void loop() {
  if(gb.update()){

    if(gb.buttons.repeat(BTN_UP, 2)){

    }
    if(gb.buttons.repeat(BTN_LEFT, 2)){
      movePlayerOnLeft();
      gb.sound.playTick();
    }
    if(gb.buttons.repeat(BTN_RIGHT, 2)){
      movePlayerOnRight();
      gb.sound.playTick();
    }
    if(gb.buttons.repeat(BTN_DOWN, 2)){

    }

    if(gb.buttons.pressed(BTN_A)){
      started = true;
    }
    if(gb.buttons.pressed(BTN_B)){
      
    }
    if(gb.buttons.pressed(BTN_C)){
      started = false;
      gb.titleScreen(F("Casse Briques")); //shows the main menu
    }

    if(started){
      updateBallPosition();
      checkCollision();
    }else{
      setBallInitialPosition();
    }

    drawBricks();
    drawBall();
    drawPlayer();
  }
}


int isInCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2){
  int col = 0;
  if(!(x2 >= x1+w1 || x2+w2 <= x1 || y2 >= y1+h1 || y2+h2 <= y1 )){
    
    if(x1 + w1 >= x2){ // left
      col = 1;
      if(y1 + h1 == y2){ // corner top left
        col = 2;
      }else if(y1 == y2 + h2){ // corner bottom left
        col = 8;
      }
    }else if(x1 <= x2 + w2){ // right
      col = 5;
      if(y1 + h1 == y2){ // corner top right
        col = 4;
      }else if(y1 == y2 + h2){ // corner bottom right
        col = 6;
      }
    }else if(y1 + h1 >= y2){ // top
      col = 3;
      if(x1 + w1 == x2){ // corner top left
        col = 2;
      }else if(x1 == x2 + w2){ // corner top right
        col = 4;
      }
    }else if(y1 <= y2 + h2){ // bottom
      col = 7;
      if(x1 + w1 == x2){ // corner bottom left
        col = 8;
      }else if(x1 == x2 + w2){ // corner bottom right
        col = 6;
      }
    }
  }
  return col;  
}

