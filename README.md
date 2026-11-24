# EDAG01 Efficient C

Lab exercises for EDAG01 Efficient C, including a work-in-progress simplex solver in C.

## Labs

- **Lab 1:** Reading linear-program input, allocating memory, and printing the objective and constraints.
- **Lab 2:** Implementing the simplex algorithm and practising debugging with GDB. Work in progress.

Each lab directory contains its C source and a sample input file named `i`.

## Run Lab 1

```sh
cd lab1
cc -g -Wall -Wextra intopt.c -lm -o intopt
./intopt < i
```

Lab 2 is an ongoing implementation, not a finished solver. Compiled programs and debug output are excluded from version control.
