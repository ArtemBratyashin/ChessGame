# Knight's Pathfinding with Bishop Avoidance

## Overview

This project is a C language implementation of a chess pathfinding algorithm for a **knight** on a standard 8x8 board. The program calculates the shortest possible route for the knight from a starting position to a target square while ensuring that the knight's path never passes through any squares threatened by **bishops** placed on the board. All squares under attack by any bishop—including diagonals—are marked as unsafe, and the algorithm finds a route that keeps the knight safe at each step.


## Usage

1. **Input:** The program expects user input for:
   - Starting square for the knight (e.g., `a1`)
   - Target square for the knight (e.g., `h8`)
   - Number of bishops on the board
   - Each bishop's position (e.g., `d4`)
2. **Output:** If a safe path exists, the program prints the sequence of knight moves. If not, an error message is shown.

## Example
1. **Input:**
'a1'  'h8'  '2'  'd4'  'f7'
3. **Output:** 
a1 b3 c5 d7 f6 h8
