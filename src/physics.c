#include "../include/physics.h"
#include <math.h> // used here for force calculations

// Apply forces to all particles
void apply_forces(Particle *particles, int n) {
  // Apply Gravity force (downward force)
  float gravity = 9.81f;
  for (int i = 0; i < n; i++) {
    particles[i].ay = gravity;
  }
}

void update_accelerations(Particle *particles, int n) {
  // TODO: add more force calculations if needed
  (void)particles; // remove when using these params
  (void)n;         // remove when using these params
}

void calculate_forces(Particle *particles, int n) {
  float G = 6.67430e-11f; // Gravitational constant
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      // calculate distance between two particles
      float dx = particles[j].x - particles[i].x;
      float dy = particles[j].y - particles[i].y;
      float distance = sqrt(dx * dx + dy * dy);

      // Calculate gravitational force between two particles
      float force =
          (G * particles[i].mass * particles[j].mass) / (distance * distance);

      // Calculate acceleration due to this force
      float ax = force * dx / distance / particles[i].mass;
      float ay = force * dy / distance / particles[i].mass;

      // update accelerations of particles
      particles[i].ax += ax;
      particles[i].ay += ay;
      particles[j].ax -= ax;
      particles[j].ay -= ay;
    }
  }
}
