#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "SDL.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

void FreeImages();
void Render();
bool ProgramIsRunning();

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 480

int main(int argc, char* args[])
{

  /* Initialize SDL */
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    printf("Failed to initialize SDL\n");
    return 1;
  }
  
  /* Create Window */
  window = SDL_CreateWindow(NULL, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
  if (!window) {
    printf("Could not create Window\n");
    return 1;
  }
  
  /* Create Renderer */
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer) {
      printf("Could not create Renderer\n");
      return 1;
  }  

  /* Main Loop */
  while(ProgramIsRunning()) {
    Render();
  }
  
  /* Quit SDL */  
  SDL_Quit();
  return 1;
}

void Render()
{
  /* Clear the screen */
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  /* Draw a Red Rectangle in Center of Window */
  SDL_Rect rect;
    rect.w = 18;
    rect.h = 18;
    rect.x = SCREEN_WIDTH / 2;
    rect.y = SCREEN_HEIGHT / 2;

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

  /*  Fill the rectangle in the color */
  SDL_RenderFillRect(renderer, &rect);

  /* Update Screen */
  SDL_RenderPresent(renderer);
}

bool ProgramIsRunning()
{
  SDL_Event event;
  bool running = true;
  while(SDL_PollEvent(&event))
  {
     if(event.type == SDL_QUIT)
       running =false;
  }
  return running;
}