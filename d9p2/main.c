/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/10 10:16:01 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	checked[100][100];
static int	basin_size[1000];
static int c = 0;

int	ft_sort(const void *i1, const void *i2)
{
	return (*(int*)i2 - *(int*)i1);
}

void	calculate_basin(int arr[100][100], int x, int y, int c)
{
	if (arr[x][y] == 9 || checked[x][y] == 1)
		return ;
	checked[x][y] = 1;
	basin_size[c] += 1;
	if (x > 0)
		calculate_basin(arr, x - 1, y, c);
	if (y > 0)
		calculate_basin(arr, x, y - 1, c);
	if (x < 99)
		calculate_basin(arr, x + 1, y, c);
	if (y < 99)
		calculate_basin(arr, x, y + 1, c);
}

void	check_array(int	arr[100][100])
{
	for (int x = 0; x < 100; x++)
	{
		for (int y = 0; y < 100; y++)
		{
			// top left corner
			if ((x == 0 && y == 0) &&  (arr[x][y] < arr[x][y + 1] && arr[x][y] < arr[x + 1][y]))
			{
				calculate_basin(arr, x, y, c);
				c++;
			}
			// top right corner
			if ((x == 0 && y == 99) && (arr[x][y] < arr[x][y - 1] && arr[x][y] < arr[x + 1][y]))
			{
				calculate_basin(arr, x, y, c);
				c++;
			}
			// bottom left corner
			if ((y == 0 && x == 99) && (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x][y + 1]))
			{
				calculate_basin(arr, x, y, c);
				c++;
			}
			// bottom right corner
			if (((x == 99 && y == 99) && (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x][y - 1])))
			{
				calculate_basin(arr, x, y, c);
				c++;
			}
			// first row
			if ((x == 0 && y > 0 && y < 99) && (arr[x][y] < arr[x][y + 1] && arr[x][y] < arr[x + 1][y] && arr[x][y] < arr[x][y - 1]))
			{
				calculate_basin(arr, x, y, c);
				c++;
			}
			// first column
			if ((y == 0 && x > 0 && x < 99) && (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x + 1][y] && arr[x][y] < arr[x][y + 1]))
			{
				calculate_basin(arr, x, y, c);
				c++;
			}
			// last row
			if ((x == 99 && y > 0 && y < 99) && (arr[x][y] < arr[x][y - 1] && arr[x][y] < arr[x][y + 1] && arr[x][y] < arr[x - 1][y]))
			{
				calculate_basin(arr, x, y, c);
				c++;
			}
			// last column
			if ((y == 99 && x > 0 && x < 99) && (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x + 1][y] && arr[x][y] < arr[x][y - 1]))
			{
				calculate_basin(arr, x, y, c);
				c++;
			}
			if ((y > 0 && y < 99 && x > 0 && x < 99) && (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x + 1][y] && arr[x][y] < arr[x][y + 1] && arr[x][y] < arr[x][y - 1]))
			{
				calculate_basin(arr, x, y, c);
				c++;
			}
		}
	}
}

int	main(void)
{
	int		fd;
	char	*line;
	int		ret;
	int		arr[100][100];
	int		y = 0;

	fd = open("input", O_RDONLY);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		for (int x = 0; x < (int)ft_strlen(line); x++)
			arr[y][x] = line[x] - '0';
		y++;
		if (line != NULL)
			free(line);
	}
	close(fd);
	check_array(arr);
	qsort(basin_size, c, sizeof(basin_size[0]), ft_sort);
	printf("Answer: %d\n", basin_size[0] * basin_size[1] * basin_size[2]);
	return (0);
}