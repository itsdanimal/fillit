# Fill-it!

The goal of this project is to arrange every Tetriminos with each others in order to make
the smallest possible square. But in some cases, this square should contains holes when
some given pieces won’t fit in perfectly with others.

# Usage

Compile using the 'make', run the program ('./fillit') with test files as arguments.
Valid test files are 4x4 blocks created with the '.' character. Each block is read as a '#'.

# Example test file contents
....
..##
.##.
....
\
...#
...#
...#
...#
\
.###
...#
....
....
\
....
..##
..##
....
\

Note that tetrimino blocks are only valid if they are all touching and of right size i.e. 4 '#' to one piece.
Blocks are separated by a '\n' character in the test file for the fillit program to parse the blocks correctly.
