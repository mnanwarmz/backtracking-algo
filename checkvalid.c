/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaid <azaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:34:12 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/04 14:44:41 by azaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	is_higher(int cur_val, int *max_val, int *total)
{
	if (cur_val > *max_val)
	{
		*total += 1;
		*max_val = cur_val;
	}
}

void	update_cross(int grid[][4], int rowcol[][4], int yx[2], int total)
{
	const int	coor[4][2] = {{0, yx[1]}, {3, yx[1]}, {yx[0], 0}, {yx[0], 3}};
	const int	mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int			i;
	int			j;
	int			max_val;

	i = 0;
	while (i < 3)
	{
		max_val = grid[coor[i][0]][coor[i][1]];
		total = (max_val == 0) ? 0 : 1;
		j = 0;
		while (j < 4)
		{
			is_higher(grid[coor[i][0] + mv[i][0] * j]
			[coor[i][1] + mv[i][1] * j], &max_val, &total);
			j++;
		}
		rowcol[i][yx[0]] = (i == 0 || i == 1) ? total : rowcol[i][yx[0]];
		rowcol[i][yx[1]] = (i == 2 || i == 3) ? total : rowcol[i][yx[1]];
		i++;
	}
}

void	update_grid(int grid[][4], int rowcol[][4])
{
	int i;
	int yx[2];

	i = 0;
	while (i < 4)
	{
		yx[0] = i;
		yx[1] = i;
		update_cross(grid, rowcol, yx, 0);
		i++;
	}
}

int		check_valid(int rowcol[][4], int u_rowcol[][4])
{
	int i;
	int y;
	int x;

	i = 0;
	while (i < 16)
	{
		y = i / 4;
		x = i % 4;
		if (rowcol[y][x] != u_rowcol[y][x])
			return (0);
		i++;
	}
	return (1);
}