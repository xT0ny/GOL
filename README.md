C implementation of a simple Conway's Game Of Life using standard libraries
The game consist in a table where every cell has two states: Alive or Dead.
An initial set of 600 cells are randomly generated on the table, then the cells respect the folowing rules:
1. Underpopulation: An alive cell with less than 2 neighbouring cells dies
2. Survival: An alive cell with 2 or 3 neighbouring cells survives the next generation
3. Overpopulation: An alive cell with more than 3 neighbouring cells dies
4. Reproduction: A dead cell with exactly 3 neighbouring cells turns alive
The game uses 3 different colors for alive cells, there is no current use outside aesthetic for now
