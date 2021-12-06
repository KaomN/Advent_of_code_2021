/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/06 21:01:59 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	get_x2(char *s)
{
	int	x;

	for (x = 0; s[x] != '\0'; x++)
	{
		if (s[x] == ',')
			break;
	}
	return (x + 1);
}

int	get_y1(char *s)
{
	int	x;

	for (x = 0; s[x] != '\0'; x++)
	{
		if (s[x] == '>')
			break;
	}
	return (x + 1);
}

int	get_y2(char *s)
{
	int	x;
	int	check = 0;

	for (x = 0; s[x] != '\0'; x++)
	{
		if (check == 1 && s[x] == ',')
			break ;
		if (s[x] == ',')
			check = 1;
		
	}
	return (x + 1);
}

int main(void)
{
	int		fd;
	char	*line = NULL;
	int		ret = 1;
	int		coords[500][4];
	int		map[990][990];
	int		count = 0;
	int		x2 = 0;
	int		diffx;
	int		diffy;
	fd = open("input", O_RDONLY);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		coords[count][0] = ft_atoi(line);
		coords[count][1] = ft_atoi(line + get_x2(line));
		coords[count][2] = ft_atoi(line + get_y1(line));
		coords[count][3] = ft_atoi(line + get_y2(line));
		count++;
		if (line != NULL)
			free(line);
	}
	//Fills map[][] with 0
	for (int x = 0; x < 990; x++)
		for (int y = 0; y < 990; y++)
			map[x][y] = 0;
	for (int x = 0; x < 500; x++)
	{
		if (coords[x][0] < coords[x][2] && coords[x][0] != coords[x][3])
			diffx = coords[x][2] - coords[x][0];
		else
			diffx = coords[x][0] - coords[x][2];
		if (coords[x][1] < coords[x][3] && coords[x][1] != coords[x][2])
			diffy = coords[x][3] - coords[x][1];
		else
			diffy = coords[x][1] - coords[x][3];
		// check if x1 == x2
		if (coords[x][0] == coords[x][2])
		{
			if (coords[x][1] < coords[x][3])
				for (int x1 = coords[x][1]; x1 <= coords[x][3]; x1++)
					map[x1][coords[x][0]] += 1;
			else
				for (int x1 = coords[x][3]; x1 <= coords[x][1]; x1++)
					map[x1][coords[x][0]] += 1;
		}
		//check if y1 == y2
		if (coords[x][1] == coords[x][3])
		{
			if (coords[x][0] < coords[x][2])
				for (int x1 = coords[x][0]; x1 <= coords[x][2]; x1++)
					map[coords[x][1]][x1] += 1;
			else
				for (int x1 = coords[x][2]; x1 <= coords[x][0]; x1++)
					map[coords[x][1]][x1] += 1;
		}
		//Check diagonals
		if (coords[x][0] == coords[x][1] && coords[x][2] == coords[x][3])
		{
			if (coords[x][0] < coords[x][2])
				for (int x1 = coords[x][0]; x1 <= coords[x][2]; x1++)
					map[x1][x1] += 1;
			else
				for (int x1 = coords[x][2]; x1 <= coords[x][0]; x1++)
					map[x1][x1] += 1;
		}
		else if (coords[x][0] == coords[x][3] && coords[x][1] == coords[x][2])
		{
			if (coords[x][0] < coords[x][1])
			{
				x2 = coords[x][1];
				for (int x1 = coords[x][0]; x1 <= coords[x][1]; x1++)
					map[x1][x2--] += 1;
			}
			else
			{
				x2 = coords[x][0];
				for (int x1 = coords[x][1]; x1 <= coords[x][0]; x1++)
					map[x1][x2--] += 1;
			}
		}
		else if (diffx == diffy && coords[x][0] != coords[x][1] && coords[x][2] != coords[x][3])
		{
			
			if (coords[x][0] > coords[x][2] && coords[x][1] > coords[x][3])
			{
				x2 = coords[x][3];
				for (int x1 = coords[x][2]; x1 <= coords[x][0]; x1++)
					map[x2++][x1] += 1;
			}
			else if (coords[x][0] < coords[x][2] && coords[x][1] < coords[x][3])
			{
				x2 = coords[x][1];
				for (int x1 = coords[x][0]; x1 <= coords[x][2]; x1++)
					map[x2++][x1] += 1;
			}
			else if (coords[x][0] < coords[x][2] && coords[x][1] > coords[x][3])
			{
				x2 = coords[x][1];
				for (int x1 = coords[x][0]; x1 <= coords[x][2]; x1++)
					map[x2--][x1] += 1;
			}
			else if (coords[x][0] > coords[x][2] && coords[x][1] < coords[x][3])
			{
				x2 = coords[x][3];
				for (int x1 = coords[x][2]; x1 <= coords[x][0]; x1++)
					map[x2--][x1] += 1;
			}
		}
		else if (diffx == diffy && coords[x][0] == coords[x][1])
		{
			if (coords[x][0] == coords[x][1] && coords[x][2] < coords[x][3])
			{
				x2 = coords[x][3];
				for (int x1 = coords[x][2]; x1 <= coords[x][0]; x1++)
					map[x2--][x1] += 1;
			}
			else if (coords[x][0] == coords[x][1] && coords[x][2] > coords[x][3])
			{
				x2 = coords[x][2];
				for (int x1 = coords[x][3]; x1 <= coords[x][0]; x1++)
					map[x1][x2--] += 1;
			}
		}
		else if (diffx == diffy && coords[x][2] == coords[x][3])
		{
			if(coords[x][2] == coords[x][3] && coords[x][0] < coords[x][1])
			{
				x2 = coords[x][1];
				for (int x1 = coords[x][0]; x1 <= coords[x][2]; x1++)
					map[x2--][x1] += 1;
			}
			else if(coords[x][2] == coords[x][3] && coords[x][0] > coords[x][1])
			{
				x2 = coords[x][0];
				for (int x1 = coords[x][1]; x1 <= coords[x][2]; x1++)
					map[x1][x2--] += 1;
			}
		}
		diffx = 1000;
		diffy = 1001;
	}
	count = 0;
	for (int x = 0; x < 990; x++)
		for (int y = 0; y < 990; y++)
		{
			if (map[x][y] > 1)
				count++;
		}
	printf("Answer: [%d]\n", count);
	close (fd);
	return (0);
}