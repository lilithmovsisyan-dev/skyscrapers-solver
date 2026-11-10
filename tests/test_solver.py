"""Independent black-box checks using all 576 Latin squares of order four."""
import itertools
from pathlib import Path
import random
import subprocess
import sys


def visible(line):
    tallest = count = 0
    for value in line:
        if value > tallest:
            tallest = value
            count += 1
    return count


def clues(board):
    columns = list(zip(*board))
    return tuple(
        [visible(col) for col in columns]
        + [visible(col[::-1]) for col in columns]
        + [visible(row) for row in board]
        + [visible(row[::-1]) for row in board]
    )


def all_boards():
    permutations = list(itertools.permutations(range(1, 5)))

    def extend(rows):
        if len(rows) == 4:
            yield tuple(rows)
            return
        for row in permutations:
            if all(row[col] not in [r[col] for r in rows] for col in range(4)):
                yield from extend(rows + [row])

    return list(extend([]))


def main():
    executable = str(Path(sys.argv[1]).resolve())

    def run(arguments):
        return subprocess.run(
            [executable, *arguments], capture_output=True, text=True, timeout=10
        )

    def reject(arguments):
        result = run(arguments)
        assert result.returncode == 1, (arguments, result.returncode, result.stderr)
        assert result.stdout == 'Error\n', (arguments, result.stdout)
        assert result.stderr == '', result.stderr

    boards = all_boards()
    assert len(boards) == 576
    valid_clues = {clues(board) for board in boards}
    for expected in sorted(valid_clues):
        result = run([' '.join(map(str, expected))])
        assert result.returncode == 0, (expected, result.stdout, result.stderr)
        lines = result.stdout.splitlines()
        assert len(lines) == 4, result.stdout
        board = [list(map(int, line.split())) for line in lines]
        assert all(sorted(row) == [1, 2, 3, 4] for row in board), board
        assert all(sorted(col) == [1, 2, 3, 4] for col in zip(*board)), board
        assert clues(board) == expected, (expected, board)
        formatted = ''.join(' '.join(map(str, row)) + '\n' for row in board)
        assert result.stdout == formatted, result.stdout
        assert result.stderr == '', result.stderr

    sample = '4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2'
    malformed = [
        [], [sample, sample], [''], [' '], ['1'], [sample[:-2]],
        [sample + ' 1'], [sample + ' '], [' ' + sample],
        [sample.replace(' ', '  ', 1)], [sample.replace(' ', '\t', 1)],
        [sample + '\n'], ['0' + sample[1:]], ['5' + sample[1:]],
        ['x' + sample[1:]], ['-1' + sample[1:]], ['1' * 31], ['1' * 10000],
    ]
    for arguments in malformed:
        reject(arguments)

    rng = random.Random(42)
    impossible = {(1,) * 16, (4,) * 16}
    # Also exercise contradictions which pass the opposing-clue sum filter.
    while len(impossible) < 102:
        candidate = tuple(rng.randint(1, 4) for _ in range(16))
        if candidate not in valid_clues and all(
            candidate[i] + candidate[i + 4] <= 5
            and candidate[i + 8] + candidate[i + 12] <= 5
            for i in range(4)
        ):
            impossible.add(candidate)
    for candidate in sorted(impossible):
        reject([' '.join(map(str, candidate))])
    print(
        f'PASS: {len(valid_clues)} solvable clue sets from {len(boards)} boards, '
        f'{len(malformed)} invalid inputs, {len(impossible)} unsolvable puzzles.'
    )


if __name__ == '__main__':
    main()
