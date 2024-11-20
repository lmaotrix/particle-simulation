#include "../include/particle.h"

void update_particles(Particle *particles, int n, float dt) {
  for (int i = 0; i < n; i++) {
    particles[i].vx += particles[i].ax * dt;
    particles[i].vy += particles[i].ay * dt;
    particles[i].x += particles[i].vx * dt;
    particles[i].y += particles[i].vy * dt;
  }
}
