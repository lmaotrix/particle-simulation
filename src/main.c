#include "../include/particle.h"
#include "../include/physics.h"
#include "../include/render.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define INITIAL_PARTICLES 10
#define MAX_PARTICLES 1000
#define PARTICLES_INCREMENT 10

// Set initial number of particles
int num_particles = INITIAL_PARTICLES;
// Simulation state for pause and play
SimulationState sim_state = STATE_RUNNING;
int gravity_enabled = 1; // 1 = ON, 0 = OFF
int attraction_enabled = 0; // 1 for attract, -1 for repel, 0 for OFF
int mouse_down = 0; // checks for mouse button held down 
int mouse_x = 0;
int mouse_y = 0;

int main(int argc, char *argv[])
{
    // SDL Setup
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (init_renderer(&window, &renderer, 800, 600) != 0)
    {
        return -1;
    }

    // Initialize fonts
    if (TTF_Init() != 0) {
        fprintf(stderr, "TTF_Init failed: %s\n", TTF_GetError());
        return -1;
    }

    TTF_Font* font = TTF_OpenFont("assets/fonts/OpenSans-Regular.ttf", 16);
    if (!font) {
        fprintf(stderr, "Failed to load font %s\n", TTF_GetError());
        return -1;
    }

    srand((unsigned)time(NULL));

    // Initialize particles
    Particle particles[MAX_PARTICLES];
    initialize_particles(particles, num_particles);

    // Simulation control
    int running = 1;
    float dt = 0.1f;

    while (running)
    {

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    running = 0;
                    break;

                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_SPACE)
                    {
                        // Toggle simulation state
                        sim_state = (sim_state == STATE_RUNNING) ? STATE_PAUSED : STATE_RUNNING;
                    }
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    mouse_down = 1;
                    SDL_GetMouseState(&mouse_x, &mouse_y);

                    // Check buttons
                    if (mouse_x >= 20 && mouse_x <= 120 && mouse_y >= 20 && mouse_y <= 60)
                        sim_state = (sim_state == STATE_RUNNING) ? STATE_PAUSED : STATE_RUNNING;

                    if (mouse_x >= 140 && mouse_x <= 240 && mouse_y >= 20 && mouse_y <= 60)
                    {
                        if (num_particles + PARTICLES_INCREMENT <= MAX_PARTICLES)
                        {
                            initialize_particles(particles + num_particles, PARTICLES_INCREMENT);
                            num_particles += PARTICLES_INCREMENT;
                        }
                    }

                    if (mouse_x > 260 && mouse_x <= 360 && mouse_y >= 20 && mouse_y <= 60)
                    {
                        if (num_particles >= PARTICLES_INCREMENT)
                            num_particles -= PARTICLES_INCREMENT;
                        else
                            num_particles = 0;
                    }

                    if (mouse_x >= 380 && mouse_x <= 480 && mouse_y >= 20 && mouse_y <= 60)
                        gravity_enabled = !gravity_enabled;

                    // Set attraction or repulsion based on button
                    if (event.button.button == SDL_BUTTON_LEFT)
                        attraction_enabled = 1;   // attract
                    else if (event.button.button == SDL_BUTTON_RIGHT)
                        attraction_enabled = -1;  // repel

                    break;

                case SDL_MOUSEBUTTONUP:
                    mouse_down = 0;
                    attraction_enabled = 0;
                    break;

                case SDL_MOUSEMOTION:
                    mouse_x = event.motion.x;
                    mouse_y = event.motion.y;
                    break;
            }
        }
        // Physics update
        apply_forces(particles, num_particles);
        if (sim_state == STATE_RUNNING)
        {
            update_particles(particles, num_particles, dt);
        }

        // Rendering
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        render_particles(renderer, particles, num_particles);
        render_particle_counter(renderer, font, num_particles);
        render_buttons(renderer, sim_state);
        SDL_RenderPresent(renderer);

        SDL_Delay(16); // ~60 FPS
    }

    cleanup_renderer(window, renderer);
    return 0;
}
