#define BRICKS_NB 30
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
  int tmp = 1;
  
  for(int i = 0; i < BRICKS_NB; ++i){
    bricks[i].x = posX;
    bricks[i].y = posY;
    
    posX += BRICKS_SIZE + 1;
    
    if(posX >= LCDWIDTH){
      posY += BRICKS_SIZE + 1;
      posX = 1;
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

bool checkBricksCollision(int x, int y, int size){
  for(int i = 0; i < BRICKS_NB; ++i){
    if(isInCollision(x, y, size, size, bricks[i].x, bricks[i].y, BRICKS_SIZE, BRICKS_SIZE) != 0){
      bricks[i].broken = true;
      return true;
    }
  }
}

