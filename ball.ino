typedef struct{
  int x, y; // Position
  int vx, vy; // Speed vector
  int size;
}Ball;

Ball b;

void initBall(){
    b.x = getPlayerPosition() + getPlayerSize() / 2;
    b.y = 39;
    b.vx = 3;
    b.vy = 3;
    b.size = 6;
}

void drawBall(){
  gb.display.fillRect(b.x, b.y, b.size, b.size);
}

void updateBallPosition(){
  int b.x = b.x + b.vx;
  int b.y = b.y + b.vy;
}


