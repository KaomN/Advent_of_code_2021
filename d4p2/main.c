/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/06 10:55:33 by conguyen         ###   ########.fr       */
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

int	ft_check_v(int arr[][5], int y, int xcount)
{
	int	count = 0;
	int	x = xcount * 5;
	int	c;
	
	for (c = x + 5; x < c; x++)
	{
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
	int		num[100] = {74,79,46,2,19,27,31,90,21,83,94,77,0,29,38,72,42,23,6,62,45,95,41,55,93,69,39,17,12,1,20,53,49,71,61,13,88,25,87,26,50,58,28,51,89,64,3,80,36,65,57,92,52,86,98,78,9,33,44,63,16,34,97,60,40,66,75,4,7,84,22,43,11,85,91,32,48,14,18,76,8,47,24,81,35,30,82,67,37,70,15,5,73,59,54,68,56,96,99,10};
	int		**bingoarr;
	int		x = 0;
	int		xcount;
	int		y = 0;
	int		z = 0;
	int		count = 0;
	int		bingo = 0;
	int		res = 0;
	int		boardnum = 0;
	int		boardcheck = 0;
//	int		onemore = 0;

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
	boardnum = z / 5;
	int		board[boardnum];
	int		checkbingo[z][5];
	// allocates 0 to checkbingo
	for (x = 0; x < boardnum; x++)
		board[x] = 0;
	for (x = 0; x < z; x++)
		for (y = 0; y < 5; y++)
			checkbingo[x][y] = 0;
	for (count = 0; count <= 100; count++)
	{
		for (x = 0; x < z; x++)
		{
			xcount = x / 5;
			for (y = 0; y < 5; y++)
			{
				if (num[count] == bingoarr[x][y])
				{
					checkbingo[x][y] = 1;
					bingo = ft_check_h(checkbingo[x]);
					if (bingo == 1)
						board[xcount] = 1;
					bingo = ft_check_v(checkbingo, y, xcount);
					if (bingo == 1)
						board[xcount] = 1;
				}
			}
		}
		boardcheck = 0;
		for (int e = 0; e < z / 5; e++)
		{
			if (board[e] == 0)
			{
				boardcheck++;
				boardnum = e;
			}
		}
		if (boardcheck == 0)
			break ;
	}
	// Get the winning board
	x = boardnum * 5;
	y = 0;
	for (y = x + 5; x < y; x++)
	{
		for (int c = 0; c < 5; c++)
		{
			printf("[%d]", checkbingo[x][c]);
			if (checkbingo[x][c] == 0)
			{
				res += bingoarr[x][c];
			}
		}
		printf(" ");
		for (int t = 0; t < 5; t++)
			printf("[%d]", bingoarr[x][t]);
		printf("\n");
	}
	printf("[%d] * [%d] = [%d]\n",num[count], res, num[count] * res);
	for (x = 0; bingoarr[x] != NULL; x++)
		free(bingoarr[x]);
	free(bingoarr);
	close (fd);
	return (0);
}