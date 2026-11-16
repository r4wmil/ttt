# Super TicTacToe

## Programs

| File | Game |
| --- | --- |
| `ttt.c` | Classic 3x3 Tic-Tac-Toe, two players sharing one terminal |
| `ttt2.c` | Super Tic-Tac-Toe: 9x9 board made of nine 3x3 sub-boards |

Both are single-file, dependency-free, and read moves from stdin.

## Build

Built and tested with GCC under MSYS2. There is no Makefile; compile each
target directly:

```sh
gcc -o ttt.c out/ttt && ./out/ttt
gcc -o ttt2.c out/ttt2 && ./out/ttt2
```
