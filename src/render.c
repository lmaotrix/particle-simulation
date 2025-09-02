#include "../include/render.h"
#include "../include/particle.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
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

      SDL_SetRenderDrawColor(renderer,
              particles[i].color.r,
              particles[i].color.g,
              particles[i].color.b,
              particles[i].color.a);
    SDL_Rect rect = {(int)particles[i].x, (int)particles[i].y, 5, 5};
    SDL_RenderFillRect(renderer, &rect);
  }
}

void cleanup_renderer(SDL_Window *window, SDL_Renderer *renderer) {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}


// render pause and play buttons
void render_buttons(SDL_Renderer *renderer, SimulationState sim_state) {
    // Pause button
    SDL_Rect pauseButton = { 20, 20, 100, 40 }; // Position + size
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red
    SDL_RenderFillRect(renderer, &pauseButton);

    // add particles button
    SDL_Rect addBtn = {140, 20, 100, 40};
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue
    SDL_RenderFillRect(renderer, &addBtn);

    // remove particles button
    SDL_Rect removeBtn = {260, 20, 100, 40};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &removeBtn);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White border
    SDL_RenderDrawRect(renderer, &pauseButton);
    SDL_RenderDrawRect(renderer, &addBtn);
    SDL_RenderDrawRect(renderer, &removeBtn);

}

// render particle counter
void render_particle_counter(SDL_Renderer* renderer, TTF_Font* font, int count) {
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "Particles: %d", count);

    SDL_Color white = {255, 255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Blended(font, buffer, white);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    // positioned just below the buttons
    SDL_Rect dst = {10, 70, surface->w, surface->h};

    SDL_RenderCopy(renderer, texture, NULL, &dst);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
