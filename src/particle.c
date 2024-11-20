#include "../include/particle.h"
#include <stdlib.h>

void initialize_particles(Particle *particles, int n) {
  for (int i = 0; i < n; i++) {
    particles[i].x = rand() % 800; // Random x position
    particles[i].y = rand() % 600; // Random y position
    particles[i].vx = 0.0f;        // Initial velocity
    particles[i].vy = 0.0f;        // Initial velocity
    particles[i].ax = 0.0f;        // No acceleration
    particles[i].ay = 0.0f;
    particles[i].mass = 1.0f; // Default mass
  }
}
