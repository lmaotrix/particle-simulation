#ifndef PARTICLE_H
#define PARTICLE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>

// Simulation state for pause and play
typedef enum {
    STATE_RUNNING,
    STATE_PAUSED
} SimulationState;

// Particle data structure definition
typedef struct Particle {
  float x, y;   // Position
  float vx, vy; // Velocity
  float ax, ay; // Acceleration
  float mass;   // Mass
  SDL_Color color; // particle color
} Particle;

// Function Prototypes

// Function to initialize an array of particles
void initialize_particles(Particle *particles, int n);

// Function to update the position and velocity of a particle array
void update_particles(Particle *particles, int n, float dt);

#endif // PARTICLE_H
