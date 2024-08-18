#include <stdio.h>
#define N 9
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%2d", grid[row][col]);
        }
        printf("\n");
    }
}
int isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return 0;
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return 0;
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return 0;

    return 1;
}
int solveSudoku(int grid[N][N]) {
    int row, col;
    int isEmpty = 0;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = 1;
                break;
            }
        }
        if (isEmpty)
            break;
    }
    if (!isEmpty)
        return 1;
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return 1;
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int grid[N][N];
    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n**** give space after every element...\n5 3 0 0 7 0 0 0 0\n6 0 0 1 9 5 0 0 0\n0 9 8 0 0 0 0 6 0\n8 0 0 0 6 0 0 0 3\n4 0 0 8 0 3 0 0 1\n7 0 0 0 2 0 0 0 6\n0 6 0 0 0 0 2 8 0\n0 0 0 4 1 9 0 0 5\n0 0 0 0 8 0 0 7 9 ***\nNow enter your own unsolved sudoku : \n");
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            scanf("%d", &grid[row][col]);
        }
    }
	printf("\nInput Grid:\n");
    printGrid(grid);
	if (solveSudoku(grid) == 1) {
        printf("\nSolved Grid:\n");
        printGrid(grid);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}

