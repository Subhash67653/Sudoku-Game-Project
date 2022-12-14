#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define empty 0
#define N 9
bool isGridSafe(int grid[N][N], int row, int col, int num);
bool isEmptyLocation(int grid[N][N], int &row, int &col);
bool SolveSudoku(int grid[N][N]) // solves sudoku
{
    int row, col;
    if (!isEmptyLocation(grid, row, col))
        return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isGridSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (SolveSudoku(grid)) // checks if after adding a number is it solvable
                return true;
            grid[row][col] = empty;
        }
    }
    return false;
}
bool isEmptyLocation(int grid[N][N], int &row, int &col) // returns empty location
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == empty)
                return true;
    return false;
}
bool UsedInRow(int grid[N][N], int prow, int number) // checks if number if its in the row mentions
{
    for (int col = 0; col < N; col++)
        if (grid[prow][col] == number)
            return true;
    return false;
}
bool UsedInCol(int grid[N][N], int pcol, int number) // checks if number if its in the col mentions
{
    for (int row = 0; row < N; row++)
        if (grid[row][pcol] == number)
            return true;
    return false;
}
// Check if the entry used already in the grid box
bool UsedInBox(int grid[N][N], int boxBeginRow, int boxBeginCol, int number) // checks if number if its in the Box

{
    bool tf = false;
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxBeginRow][col + boxBeginCol] == number)
                tf = true;
    return tf;
}
bool isGridSafe(int grid[N][N], int prow, int pcol, int number) // checks if number is addable to the grid
{
    return !UsedInRow(grid, prow, number) && !UsedInCol(grid, pcol, number) &&
           !UsedInBox(grid, prow - prow % 3, pcol - pcol % 3, number);
}
/* print result  */
void printResult(int finalgrid[N][N]) // prints the grid
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout << finalgrid[row][col] << "  ";
        cout << endl;
    }
}
/* Main */
int main()
{
    int grid[N][N] = {{0, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 6, 0, 0, 0, 0, 3},
                      {0, 7, 4, 0, 8, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 3, 0, 0, 2},
                      {0, 8, 0, 0, 4, 0, 0, 1, 0},
                      {6, 0, 0, 5, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 1, 0, 7, 8, 0},
                      {5, 0, 0, 0, 0, 9, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 4, 0}};
    if (SolveSudoku(grid) == true)
        printResult(grid);
    else
        cout << "No solution found" << endl;
    return 0;
}
