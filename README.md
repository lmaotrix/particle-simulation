# 🌀 Particle Simulator — Project Documentation

## Overview

This is a simple **Particle Simulator** developed in **C** using the **SDL2** library for graphics rendering.  
The program demonstrates basic rendering and physics simulation of particles on a 2D window using SDL2's APIs.

---

## 🚀 Features

- Real-time rendering of particles.
- Basic particle physics updates.
- Event-driven main loop using SDL2.
- Cross-platform compatible (tested on Windows with MinGW and on WSL2 with Arch).

---

## 🛠 Development Environment

- **Compiler:** `gcc` (MinGW 32-bit)
- **Build System:** `mingw32-make`
- **Graphics Library:** SDL2 (version 2.28.5)
- **Operating System:** Windows 10/11 (64-bit, targeting 32-bit build) / WSL2 with Arch Linux

---

## 📂 Project Structure

```
project-root/
├── include/              # Header files
├── src/                  # Source code files (.c)
│   ├── main.c
│   ├── render.c
│   ├── particle.c
│   └── physics.c
├── build/                # Build output (object files and executable)
├── Makefile              # Build instructions (for Unix-based systems)
├── Makefile.win          # Build instructions (for windows)
├── Assets/               # Fonts/Media
│   ├── fonts/
│   │   └── OpenSans-Regular.ttf
```


---

## ⚙️ Prerequisites

1. **SDL2 Development Libraries:**  
   Download SDL2 version **2.28.5** (or compatible) for MinGW 32-bit from [SDL2 Downloads](https://www.libsdl.org/download-2.0.php).

2. **MinGW-w64 GCC compiler:**  
   Install targeting 32-bit (i686).

3. **SDL2 DLL runtime:**  
   - Recommended: Add SDL2’s `bin` folder to your **PATH** environment variable  
   - Alternative: The Makefile copies `SDL2.dll` to the build directory automatically.

4. **SDL2_ttf font library:**
   It's important to have it installed for the everything to be rendered properly

---

## 🏗 Building the Project

Run:

```bash
mingw32-make
```
or 
``` bash
make
```


this will:
- Create build/ directory if missing.
- Compile all source files into object files.
- Link the object files to create particle_simulator.exe.
- Copy SDL2.dll into build/ (unless SDL2 bin is in PATH).

---

## ▶️ Running the Program
Navigate to build/ and run: 
```bash ./particle_simulator.exe ```
--- 
## ⚠️ Notes & Troubleshooting
The -Dmain=SDL_main flag is required on Windows with SDL2.
Linking order matters: SDL2 libs must come after object files.
-mwindows prevents a console window from appearing. 
If you see undefined references to SDL functions, verify include and linker paths. 
Missing SDL2.dll at runtime? Add its folder to PATH or ensure the copy_dll step succeeds. 

## 🔮 Future Improvements 

Here are some exciting features we can add to make the Particle Simulator more advanced and visually stunning:

### Visual Enhancements
- ⭐ Star-like particles with random colors and sizes
- ✨ Particle trails or motion blur effects
- 💫 Glow or halo effect around particles
- 🌈 Background gradient or dynamic cosmic backgrounds

### Physics Enhancements
- 🌍 Gravity sources / planets with realistic attraction
- 🔄 Global attraction/repulsion fields
- ⚛ Inter-particle gravity (particles attracting each other)
- 🪐 Collisions with massive bodies

### Interactivity
- 🖱 Mouse-controlled gravity wells
- 🎛 GUI controls (buttons, sliders) to adjust simulation parameters
- ⏸ Pause/resume and add/remove particles dynamically

### Particle Lifecycle
- ⏳ Particle fading, birth, and death over time
- 🎨 Dynamic color evolution of particles

### Advanced Cosmic Effects
- 💥 Supernova-like bursts
- 🌀 Galaxy patterns / spiral motion
- 🌠 3D particle simulation with depth perspective
--- 
## 🙋‍♂️ Contact & Support 
For questions, feel free to reach out to me at coco.gian07@gmail.com.
