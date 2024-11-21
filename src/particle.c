#include "../include/particle.h"
#include <stdlib.h> // For rand() function

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

void update_particles(Particle *particles, int n, float dt) {
  for (int i = 0; i < n; i++) {
    // update velocity using acceleration
    particles[i].vx += particles[i].ax * dt;
    particles[i].vy += particles[i].ay * dt;

    // update position using velocity
    particles[i].x += particles[i].vx * dt;
    particles[i].y += particles[i].vy * dt;

    // Handle collisions with window borders
    if (particles[i].x <= 0 || particles[i].x >= 800) { // left and right edges
      particles[i].vx *= -1; // reverse horizontal velocity
      particles[i].x = particles[i].x < 0 ? 0 : 800; // clamp to edges
    }
    if (particles[i].y <= 0 || particles[i].y >= 600) { // top and bottom edges
      particles[i].vy *= -1; // reverse vertical velocity
      particles[i].y = particles[i].y < 0 ? 0 : 600; // clamp to edge
    }
  }
}
