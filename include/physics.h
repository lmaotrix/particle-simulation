#ifndef PHYSICS_H
#define PHYSICS_H

#include "particle.h"

// function to apply force to all particles
void apply_forces(Particle *particles, int n);

// function to update particle accelerations
void update_accelerations(Particle *particles, int n);

// function to calculate forces based on particle properties
void calculate_forces(Particle *particles, int n);

#endif // !PHYSICS_H
