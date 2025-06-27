#include "../include/particle.h"
#include "../include/physics.h"
#include "../include/render.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_PARTICLES 100

// Simulation state for pause and play

SimulationState sim_state = STATE_RUNNING;

int main(int argc, char *argv[])
{
  // SDL Setup
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  if (init_renderer(&window, &renderer, 800, 600) != 0)
  {
    return -1;
  }

  // Initialize particles
  Particle particles[NUM_PARTICLES];
  initialize_particles(particles, NUM_PARTICLES);

  // Simulation control
  int running = 1;
  float dt = 0.1f;

  while (running)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        running = 0;
      }
      else if (event.type == SDL_KEYDOWN)
      {
        if (event.key.keysym.sym == SDLK_SPACE)
        {
          // Toggle simulation state
          sim_state = (sim_state == STATE_RUNNING) ? STATE_PAUSED : STATE_RUNNING;
        }
      }
      else if (event.type == SDL_MOUSEBUTTONDOWN)
      {
        int x = event.button.x;
        int y = event.button.y;

        // Check if pause/resume button is clicked
        if (x >= 20 && x <= 120 && y >= 20 && y <= 60)
        {
          sim_state = (sim_state == STATE_RUNNING) ? STATE_PAUSED : STATE_RUNNING;
        }
      }
    }

    // Physics update
    apply_forces(particles, NUM_PARTICLES);
    if (sim_state == STATE_RUNNING)
    {
      update_particles(particles, NUM_PARTICLES, dt);
    }

    // Rendering
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    render_particles(renderer, particles, NUM_PARTICLES);
    render_buttons(renderer, sim_state);  // Make sure this is defined!
    SDL_RenderPresent(renderer);

    SDL_Delay(16); // ~60 FPS
  }

  cleanup_renderer(window, renderer);
  return 0;
}
