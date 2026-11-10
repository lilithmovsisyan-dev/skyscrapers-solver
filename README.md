# Rush01 — Skyscrapers Solver

A command-line solver for the 4×4 Skyscrapers puzzle, written in C and based on the 42 Piscine Rush01 exercise.

The project demonstrates recursive backtracking, constraint checking, early pruning, input validation, and dynamic memory management.

## Puzzle rules

Fill a 4×4 board with building heights from 1 to 4:

- Each height appears exactly once in each row and column.
- Each clue states how many buildings are visible when looking along a row or column from that edge.
- A taller building hides any shorter buildings behind it.

For example, `1 2 3 4` shows four buildings from the left and one from the right.

## Build and run

Requirements: a C compiler and Make. Python 3 is needed only for the tests.

```sh
make
./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

Output:

```text
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
```

Supply exactly 16 clues in one quoted argument. Each clue must be a digit from `1` to `4`, separated by exactly one space. Leading or trailing spaces are rejected.

The four groups of clues are ordered as follows:

| Group | Positions | Reading order |
| --- | --- | --- |
| Top | 1–4 | Columns from left to right, viewed downward |
| Bottom | 5–8 | Columns from left to right, viewed upward |
| Left | 9–12 | Rows from top to bottom, viewed rightward |
| Right | 13–16 | Rows from top to bottom, viewed leftward |

Invalid arguments, unsolvable puzzles, and allocation failures print `Error` followed by a newline and return exit status `1`. A solution returns exit status `0`. Output, including errors, is written to standard output to preserve the original exercise behavior.

## How it works

1. Validate the input format, clue range, and opposing-clue sums.
2. Allocate a board initialized to zero.
3. Visit cells in row order and try heights from 1 to 4.
4. Reject heights already present in the row or column.
5. Reject partial rows and columns that cannot meet their left or top clues.
6. Check both views when a row or column is complete.
7. Backtrack when a choice fails, then free the board after solving.

For partial-line pruning, the visible count cannot exceed the clue. The count plus the number of heights above the current maximum must also be large enough to reach the clue. This is a safe upper bound; it does not guarantee that a partial line can be completed.

Backtracking has exponential worst-case cost. This implementation favors readability and is intended for 4×4 puzzles. It prints the first solution found and does not check uniqueness. Although internal functions use a size parameter, the supported interface and temporary arrays are configured for 4×4; changing the size is outside this version's supported scope.

## Files

| File | Purpose |
| --- | --- |
| `include/rush01.h` | Shared declarations and board size |
| `src/main.c` | Program entry, errors, and cleanup |
| `src/board.c` | Allocation, initialization, printing, and freeing |
| `src/input.c` | Input validation and clue extraction |
| `src/solve.c` | Recursive backtracking and uniqueness checks |
| `src/check_sides.c` | Row and column clue checks |
| `src/visibility.c` | Visibility counting and partial-line pruning |
| `tests/test_solver.py` | Independent black-box correctness checks |

## Tests

```sh
make test
```

The test script independently enumerates all 576 valid 4×4 Latin squares and derives their clue sets. It runs the solver for each distinct solvable clue set, then verifies row uniqueness, column uniqueness, all four views, output formatting, and exit status. It also checks malformed arguments and unsolvable puzzles, including contradictions that pass the preliminary sum filter.

Verification of this prepared version passed for all 438 solvable clue sets, 18 malformed argument cases, and 102 unsolvable puzzles. The same suite passed with AddressSanitizer and UndefinedBehaviorSanitizer; leak detection was disabled because LeakSanitizer cannot run under this environment's tracing.

These tests cover behavior and do not simulate allocation failures. Official 42 grading and Norminette compliance have not been verified.

## Cleanup

```sh
make clean   # Remove object files
make fclean  # Remove object files and the executable
make re      # Rebuild
```

## Project history and attribution

This repository packages a student-provided Rush01 implementation with assisted refactoring, build instructions, documentation, and independent tests. The original algorithm uses recursive backtracking with visibility pruning.

The original implementation was written individually by the repository owner. This published version includes AI-assisted refactoring, documentation, and test preparation.
