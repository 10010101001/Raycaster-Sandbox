#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#define RESX 960
#define RESY 540
#define ROTATESPEED 0.03
#define MOVESPEED 0.08
#define STRAFEMOVESPEED 0.0565685424948
#define MAPSIZE 32
#define BGCOL 17
#define clipDistance 26
#define playerSize 1

char MAP[MAPSIZE][MAPSIZE] = {
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}};


struct pos {
  unsigned char x, y;
};

struct pvf {
  float x, y;
};

void main() {

  char placeDist = 3;
  
  SDL_Window* window = NULL; //init SDL
  SDL_Renderer* renderer = NULL;
  SDL_Surface* surface = NULL;

  bool running = true;

  if( SDL_Init( SDL_INIT_VIDEO ) < 0 )  {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    running = false;
  }
  
  window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, RESX, RESY, SDL_WINDOW_SHOWN );
  
  if( window==NULL) {
    printf( "SDL_Error: %s\n", SDL_GetError() );
    running = false;
  }
  
  surface = SDL_GetWindowSurface( window );
  renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
  
  if(renderer==NULL) {
    printf("Renderer error: %s\n", SDL_GetError() );
    running = false;
  }

  const Uint8* keystate = SDL_GetKeyboardState( NULL );
  int t1, t2;
  struct pvf pos;
  pos.x = 3; 
  pos.y = 4;
  struct pvf dir;
  dir.x = 1;
  dir.y = 0; //direction vector
  struct pvf plane;
  plane.x = 0;
  plane.y = 0.8;
  struct pvf vel;
  
  float time = 0;
  float oldtime = 0; //for FPS calculations

  void rotate(float rotspeed) {
    float oldDirX = dir.x;
    dir.x = dir.x * cos(rotspeed) - dir.y * sin(rotspeed);
    dir.y = oldDirX * sin(rotspeed) + dir.y * cos(rotspeed);
    float oldPlaneX = plane.x;
    plane.x = plane.x * cos(rotspeed) - plane.y * sin(rotspeed);
    plane.y = oldPlaneX * sin(rotspeed) + plane.y * cos(rotspeed);
  }

  void move() {
    float velocity = ((keystate[SDL_SCANCODE_D] ^ keystate[SDL_SCANCODE_A]) &&
                      (keystate[SDL_SCANCODE_W] ^ keystate[SDL_SCANCODE_S])) ? STRAFEMOVESPEED : MOVESPEED;
    struct pvf oldpos = pos;
    if(keystate[SDL_SCANCODE_D]) {
      pos.x -= dir.y * velocity;
      pos.y += dir.x * velocity;
    }
    if(keystate[SDL_SCANCODE_A]) {
      pos.x += dir.y * velocity;
      pos.y -= dir.x * velocity;
    }
    if(keystate[SDL_SCANCODE_W]) {
      pos.x += dir.x * velocity;
      pos.y += dir.y * velocity;
    } 
    if(keystate[SDL_SCANCODE_S]) {
      pos.x -= dir.x * velocity;
      pos.y -= dir.y * velocity;
    }
    
    if(MAP[(char)pos.x][(char)pos.y]) pos = oldpos;
  } //remove oldpos and velocity when not needed

  while( running ) {

    t1 = SDL_GetTicks();

    SDL_Event e;

    SDL_SetRenderDrawColor( renderer, BGCOL, BGCOL, BGCOL, 0xFF);
    SDL_RenderClear( renderer );

    running  = !(SDL_PollEvent( &e ) && e.type == SDL_QUIT);

    move();

    if(keystate[SDL_SCANCODE_LEFT]) {
      rotate(-ROTATESPEED);
    }
    if(keystate[SDL_SCANCODE_RIGHT]){
      rotate(ROTATESPEED);
    }

    if(keystate[SDL_SCANCODE_SPACE] && MAP[(char)(pos.x+dir.x*placeDist)][(char)(pos.y+dir.y*placeDist)] == 0) {
      MAP[(char)(pos.x+dir.x*placeDist)][(char)(pos.y+dir.y*placeDist)] =  1;
    }
    else if(keystate[SDL_SCANCODE_LCTRL] && MAP[(char)(pos.x+dir.x*placeDist)][(char)(pos.y+dir.y*placeDist)] == 1) {
      MAP[(char)(pos.x+dir.x*placeDist)][(char)(pos.y+dir.y*placeDist)] =  0;
    }

    SDL_Rect rect;
    rect.w = 1;

    for(int z = 0; z < RESX; z += 1 ) { //raycasting code 
      
      rect.x = z;
      float cameraX = 2 * z/(float)RESX -1; // ray direction from camera, -1 to 1
      struct pvf rayd;
      rayd.x = dir.x + plane.x * cameraX; // frustum thingy
      rayd.y = dir.y + plane.y * cameraX;

      struct pos map;
      map.x = (char)pos.x;
      map.y = (char)pos.y;

      
      float sdistX;
      float sdistY;
      
      float deltaX = fabsf(1/rayd.x);
      float deltaY = fabsf(1/rayd.y);
      float pWallDist;
      char stepX;
      char stepY;
      char side; //either 0 (NS), or 1 (EW)
      
      if(rayd.x < 0) {
        stepX = -1;
        sdistX = (pos.x - map.x) * deltaX; // one side
      }
      else {
        stepX = 1;
        sdistX = (map.x + 1.0 - pos.x) * deltaX; // have to round the other way for this side.
      }
      if(rayd.y < 0) {
        stepY = -1;
        sdistY = (pos.y - map.y) * deltaY; // one side
      }
      else {
        stepY = 1;
        sdistY = (map.y + 1.0 - pos.y) * deltaY; // have to round the other way for this side.
      }
      unsigned char step;
      for( step = 0; step < clipDistance; step +=1 ) {

        if(sdistX<sdistY){
          sdistX += deltaX;
          map.x += stepX;
          side = 0;
        }
        else {
          sdistY += deltaY;
          map.y += stepY;
          side = 1;
        }
        if(MAP[map.x][map.y] !=0) {
          break;
          printf("%d\n", step);
        }
      }
      
      if(side == 0) pWallDist = (map.x - pos.x + (1-stepX) / 2) / rayd.x;
      else pWallDist = (map.y - pos.y + (1-stepY) / 2) / rayd.y;

      signed int drawColour = 255-pWallDist*15;

      if(drawColour > BGCOL && step < clipDistance) {
        int lineHeight = (int)( RESY / pWallDist);
        rect.h = lineHeight*2;
        rect.y = (RESY/2 - lineHeight);
        SDL_SetRenderDrawColor( renderer, drawColour, drawColour, drawColour, 0xFF);
        SDL_RenderFillRect( renderer, &rect);
      }
    }

    SDL_RenderPresent( renderer );
    t2 = SDL_GetTicks();
    int ms = (float)(t2-t1);
    //printf("%d\n", ms );
    SDL_Delay(15);
    
  }
  SDL_DestroyWindow( window );
  SDL_Quit();
}
