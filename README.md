# Staking Example

Based on: https://gist.github.com/tavakyan/4d9ac999dd0689806bf374732bea886d 

## Explanation
It uses the current time as the base seed for rand() + whatever you add with the `-i` command. Compiled with gcc

## To Run

`-t for running tests`


 `-h for running help`


 `-i (int) for adding randomness to picker`

## Code

Code can be found in staking.c and staking.h 

Doxygen Path: staking/html/staking_8c.html

Note: coin index 0 is the first coin (coin index 94 is really coin 95)


Valgrind command: `valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind.txt ./a.out -t`
Results: One memory warning