#ifndef RENDER_H
#define RENDER_H

#include "particle.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// function to initialize the SDL window and renderer
int init_renderer(SDL_Window **window, SDL_Renderer **renderer, int width,
                  int height);

// function to render all particles to the screen
void render_particles(SDL_Renderer *renderer, Particle *particles, int n);

// function to render UI buttons
void render_buttons(SDL_Renderer *renderer, SimulationState sim_state);

void render_particle_counter(SDL_Renderer* renderer, TTF_Font* font, int count);

// function to clean up and close the SDL resources
void cleanup_renderer(SDL_Window *window, SDL_Renderer *renderer);
#endif // RENDER_H
