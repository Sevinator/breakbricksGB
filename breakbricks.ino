#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;

void setup() {
  // put your setup code here, to run once:
  gb.begin(); //initialize the Gamebuino
  gb.titleScreen(F("Casse Briques")); //shows the main menu
  initPlayer();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(gb.update()){
    
    if(gb.buttons.repeat(BTN_UP, 2)){
//      p.y -= 1;
//      gb.sound.playTick();
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
//      p.y += 1;
//      gb.sound.playTick();
    }

    
    
    if(gb.buttons.pressed(BTN_A)){

    }
    if(gb.buttons.pressed(BTN_B)){
      
    }
    if(gb.buttons.pressed(BTN_C)){
      gb.titleScreen(F("Casse Briques")); //shows the main menu
    }


    drawPlayer();
  }
}
