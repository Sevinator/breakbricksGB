typedef struct{
  int x, y; // Position
  int vx, vy; // Speed vector
  int size;
}Ball;

Ball b;

void initBall(){

  setBallInitialPosition();
    
  b.vx = -3;
  b.vy = -3;
  
  b.size = 3;
}

void setBallInitialPosition(){
  b.x = getPlayerPosition() + getPlayerSize() / 2;
  b.y = 39;
    
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

  if(b.x < b.size){
    b.x = b.size;
    b.vx = -b.vx;
  }else if(b.y < b.size){
    b.y = b.size;
    b.vy = -b.vy;
  }else if(b.x > LCDWIDTH - b.size){
    b.x = LCDWIDTH - b.size;
    b.vx = -b.vx;
  }else if(b.y > LCDHEIGHT - b.size){
    b.y = LCDHEIGHT - b.size;
    b.vy = -b.vy;
  }

  
}

