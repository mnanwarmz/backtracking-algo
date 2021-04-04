#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[])
{

	int userinput [4][4];
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
	printf("variable l's value is %d\n", l);
	if (l != 31)
		write(1, "Error\n", 6);
	
	/*check if whitespaces are in the odd numbered elements*/
	m = 1;
	while (m < l)
	{
		if(argv[1][m] != ' ')
			write(1, "Error\n", 6);
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
				   write(1, "Error\n", 6);	
			userinput [j][k] = atoi;
			i = i + 2;
			k++;
		}
		j++;
	}

	printf("Value of UserInput [0][0] = %d\n", userinput[0][0]);
	printf("Value of UserInput [0][1] = %d\n", userinput[0][1]);
	printf("Value of UserInput [0][2] = %d\n", userinput[0][2]);
	printf("Value of UserInput [0][3] = %d\n", userinput[0][3]);
	printf("Value of UserInput [1][0] = %d\n", userinput[1][0]);
	printf("Value of UserInput [1][1] = %d\n", userinput[1][1]);
	printf("Value of UserInput [1][2] = %d\n", userinput[1][2]);
	printf("Value of UserInput [1][3] = %d\n", userinput[1][3]);
	printf("Value of UserInput [2][0] = %d\n", userinput[2][0]);
	printf("Value of UserInput [2][1] = %d\n", userinput[2][1]);
	printf("Value of UserInput [2][2] = %d\n", userinput[2][2]);
	printf("Value of UserInput [2][3] = %d\n", userinput[2][3]);
	printf("Value of UserInput [3][0] = %d\n", userinput[3][0]);
	printf("Value of UserInput [3][1] = %d\n", userinput[3][1]);
	printf("Value of UserInput [3][2] = %d\n", userinput[3][2]);
	printf("Value of UserInput [3][3] = %d\n", userinput[3][3]);
}
