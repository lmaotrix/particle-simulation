#include "../include/render.h"
#include <SDL2/SDL.h>
#include <stdio.h>

int init_renderer(SDL_Window **window, SDL_Renderer **renderer, int width,
                  int height) {
  (void)width;  // remove when using params
  (void)height; // remove when using params

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return -1;
  }

  *window =
      SDL_CreateWindow("Particle Simulator", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

  if (*window == NULL) {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    SDL_Quit();
    return -1;
  }

  *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
  if (*renderer == NULL) {
    SDL_DestroyWindow(*window);
    SDL_Quit();
    return -1;
  }

  return 0;
}

void render_particles(SDL_Renderer *renderer, Particle *particles, int n) {
  // rendering colors (white)
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  for (int i = 0; i < n; i++) {
    SDL_Rect rect = {(int)particles[i].x, (int)particles[i].y, 5, 5};
    SDL_RenderFillRect(renderer, &rect);
  }
}

void cleanup_renderer(SDL_Window *window, SDL_Renderer *renderer) {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}