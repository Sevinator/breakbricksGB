#define Y 40

typedef struct {
  int x; // Position de la barre
  int size; // Taille de la barre
  int life; // Essais restants
}Player;

Player p;

void initPlayer(){
  p.size = 20;
  p.x = LCDWIDTH/2 - p.size/2;
  p.life = 5;
}

void drawPlayer(){
  gb.display.drawRect(p.x, Y, p.size, 1);
}

void checkPosition(){
  if(p.x < 0){
    p.x = 0;
  }else if(p.x > LCDWIDTH - p.size){
    p.x = LCDWIDTH - p.size;
  }
}

void movePlayerOnLeft(){
  p.x -= 1;
  checkPosition();
}

void movePlayerOnRight(){
  p.x += 1;  
  checkPosition();
}

