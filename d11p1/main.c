/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/07 09:05:34 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	octoarray[10][10] = {0};
int	octoflashed[10][10] = {0};
int flashcount = 0;

void add_adjacent(int x, int y)
{
	// first row
	if (x == 0)
	{
		if (y == 0)
		{
			octoarray[x + 1][y]++;
			octoarray[x + 1][y + 1]++;
			octoarray[x][y + 1]++;
		}
		else if (y == 9)
		{
			octoarray[x][y - 1]++;
			octoarray[x + 1][y - 1]++;
			octoarray[x + 1][y]++;
		}
		else
		{
			for (int i = x; i < x + 2; i++)
				for (int j = y - 1; j < y + 2; j++)
					octoarray[i][j]++;
		}
	}
	// last row
	else if (x == 9)
	{
		if (y == 0)
		{
			octoarray[x - 1][y]++;
			octoarray[x - 1][y + 1]++;
			octoarray[x][y + 1]++;
		}
		else if (y == 9)
		{
			octoarray[x][y - 1]++;
			octoarray[x - 1][y - 1]++;
			octoarray[x - 1][y]++;
		}
		else
		{
			for (int i = x - 1; i < x + 1; i++)
				for (int j = y - 1; j < y + 2; j++)
					octoarray[i][j]++;
		}
	}
	// first column
	else if (y == 0)
	{
		for (int i = x - 1; i < x + 2; i++)
				for (int j = y; j < y + 2; j++)
					octoarray[i][j]++;
	}
	// last column
	else if (y == 9)
	{
		for (int i = x - 1; i < x + 2; i++)
				for (int j = y - 1; j < y + 1; j++)
					octoarray[i][j]++;
	}
	else
	{
		for (int i = x - 1; i < x + 2; i++)
				for (int j = y - 1; j < y + 2; j++)
					octoarray[i][j]++;
	}
}

int	 re_check_octoarray()
{
	int flashes = 0;
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			if (octoarray[x][y] >= 10 && octoflashed[x][y] != 1)
			{
				octoflashed[x][y] = 1;
				add_adjacent(x, y);
				octoarray[x][y] = 0;
				flashes++;
				flashcount++;
			}
		}
	}
	return (flashes);
}

void increment_octoarray()
{
	int flashes = 1;
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			if (octoarray[x][y] >= 10 && octoflashed[x][y] != 1)
			{
				octoflashed[x][y] = 1;
				add_adjacent(x, y);
				octoarray[x][y] = 0;
				flashcount++;
			}
			else
				octoarray[x][y]++;
		}
	}
	while (flashes != 0)
		flashes = re_check_octoarray();
	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 10; y++)
			if (octoflashed[x][y] == 1)
				octoarray[x][y] = 0;
	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 10; y++)
			octoflashed[x][y] = 0;
}

int main(void)
{
	int		fd;
	char	*line;
	int		ret;
	int		c = 0;

	fd = open("input", O_RDONLY);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		for (int x = 0; x < (int)ft_strlen(line); x++)
			octoarray[c][x] = line[x] - '0';
		c++;
		if (line != NULL)
			free(line);
	}
	close(fd);
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
			printf("[%d]", octoarray[x][y]);
		printf("\n");
	}
	for (int x = 0; x < 100; x++)
		increment_octoarray();
	printf("\n");
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
			printf("[%d]", octoarray[x][y]);
		printf("\n");
	}
	printf("Flashed:[%d]", flashcount);
	return (0);
}