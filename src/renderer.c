#include "../include/particle.h"
#include <SDL2/SDL.h>

void render_particles(SDL_Renderer *renderer, Particle *particles, int n) {
  for (int i = 0; i < n; i++) {
    SDL_Rect rect = {(int)particles[i].y, 5, 5};
    SDL_RenderFillRect(renderer, &rect);
  }
}
