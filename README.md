# Staking Example

Based on: https://gist.github.com/tavakyan/4d9ac999dd0689806bf374732bea886d

## Explanation
It uses the current time as the base seed for rand() + whatever you add with the `-i` command

## To Run

`-t for running tests`


 `-h for running help`


 `-i (int) for adding randomness to picker`


Doxygen Path: staking/html/staking_8c.html


Valgrind command: valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind.txt ./a.out -t
Results: One memory warning