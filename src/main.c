#include "../include/particle.h"
#include "../include/physics.h"
#include "../include/render.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_PARTICLES 100

int main(int argc, char *argv[]) {
  // SDL Setup
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  // Initialize renderer and create window/renderer
  if (init_renderer(&window, &renderer, 800, 600) != 0) {
    return -1;
  }

  // Initialize particles
  Particle particles[NUM_PARTICLES];
  initialize_particles(particles, NUM_PARTICLES);

  // Main simulation loop
  int running = 1;
  float dt = 0.1f; // Time step
  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = 0;
      }
    }

    // physics update
    apply_forces(particles, NUM_PARTICLES);
    update_particles(particles, NUM_PARTICLES, dt);

    // rendering
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    render_particles(renderer, particles, NUM_PARTICLES);
    SDL_RenderPresent(renderer);

    SDL_Delay(16); // 60fps frame rate
  }

  cleanup_renderer(window, renderer);

  return 0;
}
