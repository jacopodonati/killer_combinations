 kc - Killer Sudoku Combinations Generator

`kc` is a C program that generates all possible combinations of numbers for killer sudoku, given a target sum and a number of cells. The program also allows you to specify numbers that must or must not be included in the combinations.

## Features

- Calculates combinations of numbers that meet a specified sum.
- Allows exclusion of specific numbers from the combinations.
- Enables inclusion of mandatory numbers in the combinations.

## Requirements

- A C compiler (e.g., `clang` or `gcc`).
- An operating system compatible with C (Linux, macOS, Windows with WSL).

## Compilation

To compile the program, use the included Makefile. Run the following command in the project directory:

```bash
make
```

This will generate an executable named `kc`.

## Usage

The program can be executed from the command line with the following syntax:

```bash
./kc <target_sum> <num_cells> [-<exclude_numbers>] [+<include_numbers>]
```

### Examples

1. To find combinations that sum to 14 with 4 cells, excluding the number 2 and including the number 6:
```bash
./kc 14 4 -2 +6
```

2. To find combinations that sum to 12 with 3 cells, including the number 9 and excluding the number 6:
```bash
./kc 12 3 +9 -6
```

## Cleanup

To remove generated files (object files and the executable), run:

```bash
make clean
```