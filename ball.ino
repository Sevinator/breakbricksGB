typedef struct{
  int x, y; // Position
  int vx, vy; // Speed vector
  int size;
}Ball;

Ball b;

void initBall(){

  setBallInitialPosition();
  
  b.size = 4;
}

void setBallInitialPosition(){
  b.x = getPlayerPositionX() + getPlayerSize() / 2 - b.size / 2;
  b.y = getPlayerPositionY() - b.size;
    
  b.vx = -3;
  b.vy = -3;
}

void drawBall(){
  gb.display.fillRect(b.x, b.y, b.size, b.size);
}

void updateBallPosition(){
  b.x = b.x + b.vx;
  b.y = b.y + b.vy;
}

void checkCollision(){

  bool brickCollison = checkBricksCollision(b.y, b.y, b.size);

  if(b.x < 0){
    b.x = b.size;
    b.vx = -b.vx;
  }else if(b.y < 0){
    b.y = b.size;
    b.vy = -b.vy;
  }else if(b.x > LCDWIDTH - b.size){
    b.x = LCDWIDTH - b.size;
    b.vx = -b.vx;
  }else if(isInCollision(b.x, b.y, b.size, b.size, getPlayerPositionX(), getPlayerPositionY(), getPlayerSize(), 1) != 0){ // Collision avec le joueur
    b.y = getPlayerPositionY() - b.size;
    b.vy = -b.vy;
  }else if(b.y > LCDHEIGHT - b.size){
//    started = false;
    b.vy = -b.vy;
  }

  
}

