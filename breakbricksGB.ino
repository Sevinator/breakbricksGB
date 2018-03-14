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
  Serial.println("INIT !!");
}

void loop() {
  if(gb.update()){
    
    Serial.println("UPDATE !!");
    if(gb.buttons.repeat(BTN_UP, 2)){

    }
    if(gb.buttons.repeat(BTN_LEFT, 0.5)){
      movePlayerOnLeft();
      gb.sound.playTick();
    }
    if(gb.buttons.repeat(BTN_RIGHT, 0.5)){
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

    //drawBricks();
    drawBall();
    drawPlayer();
  }
}
