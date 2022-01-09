/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/14 08:45:35 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	paper[1500][1000];
int		max_col = 0;
int		max_row = 894;

// char	paper[15][11];
// int		max_col = 14;
// int		max_row = 10;

int	get_x_coords(char *s)
{
	int	x;
	for (x = 0; s[x] != '\0'; x++)
		if (s[x] == ',')
			break ;
	return (x + 1);
}

void	x_fold(int fold)
{
	int	starty;

	for (int x = 0; x < max_row + 1; x++)
	{
		starty = fold - 1;
		for (int y = fold + 1; y < max_col + 1; y++)
		{
			if (paper[x][y] == '#')
				paper[x][starty] = '#';
			starty--;
		}
	}
	max_col = fold - 1;
}

void	y_fold(int fold)
{
	int	startx = fold - 1;
	
	for (int x = fold + 1; x < max_row + 1; x++)
	{
		for (int y = 0; y < max_col + 1; y++)
		{
			if (paper[x][y] == '#')
				paper[startx][y] = '#';
		}
		startx--;
	}
	max_row = fold - 1;
}

int	get_fold(char *line)
{
	int	x;

	for (x = 0; line[x] != '\0'; x++)
		if (line[x] == '=')
			break ;
	x = ft_atoi(line + x + 1);
	return (x);
}

void print()
{
	for (int x = 0; x < max_row + 1; x++)
	{
		for (int y = 0; y < max_col + 1; y++)
			printf("%c", paper[x][y]);
		printf("\n");
	}
}

int	get_count()
{
	int	count = 0;

	for (int x = 0; x < max_row + 1; x++)
		for (int y = 0; y < max_col + 1; y++)
			if (paper[x][y] == '#')
				count++;
	return (count);
}

int main(void)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("input", O_RDONLY);
	ret = 1;
	for (int x = 0; x < 1500 + 1; x++)
		for (int y = 0; y < 1000 + 1; y++)
				paper[x][y] = '.';
	while (ret)
	{
		ret = get_next_line(fd, &line);
		paper[ft_atoi(line + get_x_coords(line))][ft_atoi(line)] = '#';
		if(max_col < ft_atoi(line))
			max_col = ft_atoi(line);
		// printf("coords:[%d],[%d]\n", ft_atoi(line + get_x_coords(line)), ft_atoi(line));
		if (line != NULL)
			free(line);
	}
	close(fd);
	printf("maxcol:%d\n", max_col);
	printf("maxrow:%d\n", max_row);
	// for (int x = 0; x < max_col + 1; x++)
	// {
	// 	for (int y = 0; y < max_row + 1; y++)
	// 	{
	// 		if (paper[x][y] != '#')
	// 			paper[x][y] = '.';
	// 	}
	// }
	// fd = open("fold", O_RDONLY);
	// ret = 1;
	// while (ret)
	// {
	// 	ret = get_next_line(fd, &line);
		
	// 	if (line[11] == 'x')
	// 		x_fold(get_fold(line));
	// 	else
	// 		y_fold(get_fold(line));
	// 	print();
	// 	if (line != NULL)
	// 		free(line);
	// }
	// close(fd);
	/* count number of dots */
	//print();
	printf("\n");
	x_fold(655);
	printf("maxcol:%d\n", max_col);
	printf("maxrow:%d\n", max_row);

	//print();
	printf("count: [%d]\n", get_count());
	// x_fold(5);
	// print();
	// printf("count: [%d]\n", get_count());
	return (0);
}