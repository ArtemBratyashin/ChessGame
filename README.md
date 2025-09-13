Knight's Pathfinding with Bishop Avoidance
Overview
This project is a C language implementation of a chess pathfinding algorithm for a knight on a standard 8x8 board. The program calculates the shortest possible route for the knight from a starting position to a target square while ensuring that the knight's path never passes through any squares threatened by bishops placed on the board. All squares under attack by any bishop—including diagonals—are marked as unsafe, and the algorithm finds a route that keeps the knight safe at each step.

Features
Finds the minimum-length path for a knight between any two fields.

Automatically marks all squares attacked by provided bishop positions as forbidden for the knight.

Returns the move sequence from start to finish in algebraic notation (e.g., a1, b3...). Path is printed in order, or a warning is shown if the route is impossible.

Efficient traversing of the board using a wave-like algorithm (Breadth-First Search variant).

Usage
Input: The program expects user input for:

Starting square for the knight (e.g., a1)

Target square for the knight (e.g., h8)

Number of bishops on the board

Each bishop's position (e.g., d4)

Output: If a safe path exists, the program prints the sequence of knight moves. If not, an error message is shown.

Example
text
Input:
a1
h8
2
c3
f6

Output:
a1 b3 c5 d7 f6 h8
