# GaussEliminationMethod
A simple program for calculating a system of equations using gauss elimination.
Contains testing program (test.sh).
To use the program create A and b.
File A should be cointaining:
number of columns number of rows (these should be the same),
system of equations (no new lines, just spaces).
File b should be cointaing:
number of columns number of rows(1),
answers to the equations (no new lines, just spaces).
For example, for system of equation:
2x + y + 4z = 7;
3x + 4y + 1z = 4;
5x + 2y + 2z = 5;
A file:
3 3
2 1 4 3 4 1 5 2 2
b file:
3 1
7 4 5

To execute the program use ./bin/gauss A file localization b file localization
For example: ./bin/gauss data/A data/b
