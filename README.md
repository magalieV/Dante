# Dante Star

>90% passed

The goal of this project is to generate mazes, solve them, and print the solution

This is a school project and it may only work under a Unix environment- - -
- - -
## How to read it

* The 'X' represent the wall
* The '*' represent the free space

You can moove to a free space(up, down, right, left).

The start position is the upper left-hand corne(0, 0)

The finish position is the bottom right-hand corner.
- - -
## The solution

The solution is mark with the 'o' pattern.
- - -
## How to use it

Executing the solver or the generator will print the maze.

You need to compile the source files using make before trying to execute the binaries.

*The solver:*

```./solver/solver mazefile.txt```

*The generator:*

```./generator/generator x_size y_size [perfect]```

If the perfect flag is present, a perfect maze will be generated.

A perfect maze is a maze that has a single solution.
