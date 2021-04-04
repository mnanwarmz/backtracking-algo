#include <unistd.h>
#include "solvesquare.c"

int main (int argc, char *argv[])
{

	int userinput[4][4];
	int atoi;
	int i;
	int j;
	int k;
	int l;
	int m;
	
	l = 0;
	while(argv[1][l])
	{
	l++;
	}

	/*check if array length is exactly 31 (16 single digit arguments with ws)"*/
	if (l != 31)
		{
		write(1, "Error\n", 6);
		return (1);
		}
	
	/*check if whitespaces are in the odd numbered elements*/
	m = 1;
	while (m < l)
	{
		if(argv[1][m] != ' ')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		m += 2;
	}

	/*copy values to user input array*/
	i = 0;
	while(i < l)
	{	
		k = 0;
		while(k <= 3)
		{
			atoi = ((argv[1][i]) - '0');
			if (!(atoi >= 1 && atoi <=4))
				   {
					write(1, "Error\n", 6);
				   return(1);
				   }	
			userinput [j][k] = atoi;
			i = i + 2;
			k++;
		}
		j++;
	}

	static int grid[4][4];
	static int rowcol[4][4];
    recursion(0, grid, rowcol, userinput);

}