#include "sandpiles.h"
#include "stdbool.h"
/**
 * print_grid - prints grid
 * @grid: the matrix to print
 */
void print_grid(int grid[3][3])
{
    int i, j;

    printf("=\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
/**
 * stabilize - lowers sandpiles outwards
 * @grid1: first grid
 * @grid2: second grid
 * @check: bool that checks if grid should be printed
 * Returns: check
 */
bool stabilize(int grid1[3][3], int grid2[3][3], bool check)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid1[i][j] > 3)
            {
                if (check == false)
                    print_grid(grid1);
                check = true;
                grid1[i][j] -= 4;
                if (i > 0)
                    grid2[i - 1][j] += 1;
                if (j < 2)
                    grid2[i][j + 1] += 1;
                if (i < 2)
                    grid2[i + 1][j] += 1;
                if (j > 0)
                    grid2[i][j - 1] += 1;
            }
        }
    }
    return (check);
}
/**
 * sandpiles_sum - adds two sandpiles together and fixes sandpiles
 * @grid1: first grid
 * @grid2: second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    bool check = false;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
            grid2[i][j] = 0;
        }
    }
    if (stabilize(grid1, grid2, check))
        sandpiles_sum(grid1, grid2);
}