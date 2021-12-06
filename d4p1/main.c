/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/06 10:55:48 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_check_h(int *arr)
{
	int	count = 0;
	for (int y = 0; y < 5; y++)
	{
		if (arr[y] == 1)
			count++;
	}
	if (count == 5)
		return (1);
	return 0;
}

int	ft_check_v(int arr[][5], int z, int y)
{
	int	count = 0;
	
	for (int x = 0; x < z; x++)
	{
		if (x % 5 == 0)
			count = 0;
		if (arr[x][y] == 1)
			count++;
		if (count == 5)
		{
			return (1);
			break ;
		}
	}
	return 0;
}

// int	ft_check_d(int arr[][5], int z)
// {
// 	int	count = 0;
// 	int	getnext = 0;
// 	int	getnext2 = 4;

// 	for (int x = 0; x < z; x++)
// 	{
// 		if (x % 5 == 0)
// 			count = 0;
// 		if (arr[x][getnext] == 1)
// 			count++;
// 		if (count == 5)
// 		{
// 			return (1);
// 			break ;
// 		}
// 		getnext++;
// 		if (getnext == 5)
// 			getnext = 0;
// 	}
// 	for (int x = 0; x < z; x++)
// 	{
// 		if (x % 5 == 0)
// 			count = 0;
// 		if (arr[x][getnext2] == 1)
// 			count++;
// 		if (count == 5)
// 		{
// 			return (1);
// 			break ;
// 		}
// 		getnext2--;
// 		if (getnext2 == -1)
// 			getnext2 = 4;
// 	}
// 	return 0;
// }

int main(void)
{
	int		fd;
	char	*line = NULL;
	int		ret = 1;
	int		num[100] = {17,2,33,86,38,41,4,34,91,61,11,81,3,59,29,71,26,44,54,89,46,9,85,62,23,76,45,24,78,14,58,48,57,40,21,49,7,99,8,56,50,19,53,55,10,94,75,68,6,83,84,88,52,80,73,74,79,36,70,28,37,0,42,98,96,92,27,90,47,20,5,77,69,93,31,30,95,25,63,65,51,72,60,16,12,64,18,13,1,35,15,66,67,43,22,87,97,32,39,82};
	int		**bingoarr;
	int		x = 0;
	int		y = 0;
	int		z = 0;
	int		count = 0;
	int		bingo = 0;
	int		res = 0;

	bingoarr = (int **)malloc(sizeof(int *) * 700);
	fd = open("input", O_RDONLY);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (line[0] != '\0')
		{
			bingoarr[z] = ft_strsplit_toint(line, ' ');
			z++;
		}
		if (line != NULL)
			free(line);
	}
	bingoarr[z] = NULL;
	int		checkbingo[z][5];
	// allocates 0 to checkbingo
	for (x = 0; x < z; x++)
		for (y = 0; y < 5; y++)
			checkbingo[x][y] = 0;
	for (count = 0; count <= 100; count++)
	{
		for (x = 0; x < z; x++)
		{
			for (y = 0; y < 5; y++)
			{
				if (num[count] == bingoarr[x][y])
				{
					checkbingo[x][y] = 1;
					bingo = ft_check_h(checkbingo[x]);
					if (bingo == 1)
						break ;
					bingo = ft_check_v(checkbingo, z, y);
					if (bingo == 1)
						break ;
					//bingo = ft_check_d(checkbingo, z);
					//if (bingo == 1)
					//	break ;
				}
				if (bingo == 1)
					break ;
			}
			if (bingo == 1)
				break ;
		}
		if (bingo == 1)
			break ;
	}
	// Get the winning board
	if (x % 5 != 0)
		x = (x % 5) - x;
	if (x < 0)
		x = -x;
	y = 0;
	for (y = x + 5; x < y; x++)
	{
		for (int c = 0; c < 5; c++)
		{
			printf("[%d]", bingoarr[x][c]);
			if (checkbingo[x][c] == 0)
			{
				res += bingoarr[x][c];
			}
		}
		printf("\n");
	}
	printf("[%d] * [%d] = [%d]\n",num[count], res, num[count] * res);
	printf("[%d]", x);
	for (x = 0; bingoarr[x] != NULL; x++)
		free(bingoarr[x]);
	free(bingoarr);
	close (fd);
	return (0);
}
