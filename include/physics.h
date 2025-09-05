#ifndef PHYSICS_H
#define PHYSICS_H

#include "particle.h"

// function to apply force to all particles
void apply_forces(Particle *particles, int n);

// function to update particle accelerations
void update_accelerations(Particle *particles, int n);

// function to calculate forces based on particle properties
void calculate_forces(Particle *particles, int n);

// gravity status variable
extern int gravity_enabled;

extern int attraction_enabled;

extern int mouse_down; // checks for mouse button held down 

extern int mouse_x;

extern int mouse_y;

#endif // !PHYSICS_H
