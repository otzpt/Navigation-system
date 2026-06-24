# Navigation System in C

A terminal-based program that simulates a robot automatically finding its path through a 10x10 maze using BFS (Breadth-First Search), with a step-by-step animation. Built in C as part of Hack Club Stardance.

## What it does

The program places a robot (`x`) at position `(0,0)` and finds the shortest path to the destination (`D`) at `(9,9)` through a maze of obstacles (`#`). The path is then animated tile by tile in the terminal, and replayed at a faster speed once the robot arrives.

## How it works

The pathfinding uses **BFS (Breadth-First Search)**:

1. Starting at `(0,0)`, the algorithm explores all reachable cells layer by layer
2. Each visited cell records its parent — where it came from
3. Once `(9,9)` is reached, the path is reconstructed backwards through the parent matrix
4. The path is reversed, then animated step by step using `clear()` and `usleep()`

The maze layout lives in `eh_obstaculo()`, completely separate from the pathfinding logic. Changing the maze only requires editing that one function.

## Build & Run

**Linux:**
```bash
gcc navegacaoauto.c -o robot-maze
./robot-maze
```

**Windows:**
```bash
gcc navegacaoauto.c -o robot-maze.exe
robot-maze.exe
```

Pre-built binaries available in [Releases](https://github.com/otzpt/Navigation-system/releases).

## What I learned

- How BFS works and why it guarantees the shortest path
- How to implement a queue manually in C using arrays
- How to use a parent matrix to reconstruct a path after traversal
- Why BFS gives you the path backwards and how to reverse it
- How `usleep()` and terminal clearing create smooth terminal animations

## Challenges

The biggest challenge was understanding BFS before writing a single line of code. I spent most of the time drawing it on paper, watching explanations, and trying to wrap my head around how the parent matrix actually works. The moment it clicked was thinking of it as water spreading through a maze — it fills every reachable cell layer by layer until it hits the destination.

The second challenge was path reconstruction. BFS naturally gives you the path backwards from destination to start, so reversing it correctly before animating took a few tries to get right.

## Tech stack

- C (C99)
- Standard library only: `stdio.h`, `stdlib.h`, `string.h`, `unistd.h`
- Compiled with GCC
