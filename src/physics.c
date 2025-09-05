#include "../include/physics.h"
#include <math.h> // used here for force calculations

// Apply forces to all particles
void apply_forces(Particle *particles, int n) {
    // Apply Gravity force (downward force)
    float gravity = gravity_enabled ? 9.81f : 0.0f;
    float k = 2000.0f; // strength of attraction/repulsion
    float max_force = 100.0f; // cap of acceleration
    float influence_radius = 200.0f; // effective range of attraction/repulsion
    float damping = 0.98f;

    for (int i = 0; i < n; i++) {
        //set gravity values
        particles[i].ax = 0.0f;
        particles[i].ay = gravity;

        //mouse attraction/repulsion
        if (mouse_down) {
            float dx = mouse_x - particles[i].x;
            float dy = mouse_y - particles[i].y;
            float distance = sqrtf(dx*dx + dy*dy);

            if (distance < influence_radius && distance > 0.0f) {
                float nx = dx / distance;
                float ny = dy / distance;

                // Linear falloff force
                float force = k * (1.0f - (distance / influence_radius));
                if (force > max_force) force = max_force;

                // Clamp the force
                //if (force > max_force) force = max_force;

                // Apply acceleration toward the cursor
                particles[i].ax += nx * force;
                particles[i].ay += ny * force;

                // add small perpendicular component for orbital effect 
                float orbit_strength = force * 0.3f; // orbit
                particles[i].ax += -ny * orbit_strength;
                particles[i].ay += nx * orbit_strength;
            }
        }
        // apply damping to velocity
        particles[i].vx *= damping;
        particles[i].vy *= damping;
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
