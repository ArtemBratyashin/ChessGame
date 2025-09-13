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

## Demo
You can run and test this program online without installing anything:
**[Try it on OnlineGDB](https://onlinegdb.com/uu5Mfnm6c)**

1. **Input:**<br>
'a1'<br> 'h8'<br> '2'<br> 'a2'<br> 'c5'
2. **Output:** <br>
'a1 c2 e1 g2 f4 g6 h8'
