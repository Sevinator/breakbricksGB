#define Y_player 40
#define speed_player 3

typedef struct {
  int x, y; // Position de la barre
  int size; // Taille de la barre
  int life; // Essais restants
}Player;

Player p;

void initPlayer(){
  p.size = 25;
  p.x = LCDWIDTH/2 - p.size/2;
  p.y = Y_player;
  p.life = 5;
}

int getPlayerSize(){
  return p.size;
}

int getPlayerPositionX(){
  return p.x;
}

int getPlayerPositionY(){
  return p.y;
}

void drawPlayer(){
  gb.display.drawRect(p.x, p.y, p.size, 1);
}

void checkPosition(){
  if(p.x < 0){
    p.x = 0;
  }else if(p.x > LCDWIDTH - p.size){
    p.x = LCDWIDTH - p.size;
  }
}

void movePlayerOnLeft(){
  p.x -= speed_player;
  checkPosition();
}

void movePlayerOnRight(){
  p.x += speed_player;  
  checkPosition();
}

void increaseLife(){
  ++p.life;
}

void decreaseLife(){
  --p.life;
}











