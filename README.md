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
```bash
./particle_simulator.exe
```

---

## ⚠️ Notes & Troubleshooting

- The -Dmain=SDL_main flag is required on Windows with SDL2.
- Linking order matters: SDL2 libs must come after object files.
- -mwindows prevents a console window from appearing.
- If you see undefined references to SDL functions, verify include and linker paths.
- Missing SDL2.dll at runtime? Add its folder to PATH or ensure the copy_dll step succeeds.

## 🔮 Future Improvements
- Add more complex particle interactions.
- Implement user controls (remove particles, slider to choose particle number, etc.).
- Automate cross-platform builds.
- Improve performance with optimizations.
- Convert to 3D simulation

---

## 🙋‍♂️ Contact & Support
For questions, feel free to reach out to me at coco.gian07@gmail.com.
