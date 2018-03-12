#define BRICKS_NB 10
#define BRICKS_SIZE 5

typedef struct {
  int x, y;
  int times;
  bool broken;
}Brick;

Brick bricks[BRICKS_NB];

void initBricks(){
  int posX = 1;
  int posY = 1;
  
  for(int i = 0; i < BRICKS_NB; ++i){
    bricks[i].x = posX;
    bricks[i].y = posY;
    
    posX += BRICKS_SIZE + 1;

    if(posX >= LCDWIDTH / (BRICKS_SIZE + 1)){
      posY += BRICKS_SIZE + 1;
    }
  }
}

void drawBricks(){
  for(int i = 0; i < BRICKS_NB; ++i){
    if(!bricks[i].broken){
      gb.display.fillRect(bricks[i].x, bricks[i].y, BRICKS_SIZE, BRICKS_SIZE);
    }
  }
}

