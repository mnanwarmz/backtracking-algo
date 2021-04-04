#include <unistd.h>
#include "checkvalid.c"

void ft_putint(int nb)
{   
    char c;

    c = nb + '0';
    write(1, &c, 1);
}

void ft_putchar(int c)
{   
    write(1, &c, 1);
}

void print_grid(int grid[4][4])
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            ft_putint(grid[i][j]);
            if (j != 3)
                ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
    ft_putchar('\n');
}

int valid(int num, int y, int x, int grid[4][4])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < x)
    {
        if (grid[y][i] == num)
            return (0);
        i++;
    }
    while (j < y)
    {
		// 
        if (grid [j][x] == num)
            return (0);
        j++;
    }
    return (1);
}

int recursion(int piece, int grid[4][4], int rowcol[][4], int userinput[][4])
{
    int num;
    int row;
    int col;

    if (piece == 16)
    {   
        update_grid(grid, rowcol);
        if (check_valid(rowcol, userinput))
        {
            print_grid(grid);
            return (1);
        }
    }
    num = 1;
    row = piece / 4;
    col = piece % 4;
    while (num <= 4)
    {
        if (valid(num, row, col, grid))
        {   
            grid[row][col] = num;
            if (recursion(piece + 1, grid, rowcol, userinput))
                return (1);
        }
        num++;
    }
    return (0);
}