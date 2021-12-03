/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/03 15:00:52 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int		fd;
	char	*line = NULL;
	int		ret = 1;
	char	**arr;
	char	**arr_oxy;
	char	**arr_c02;
	int		count_oxygen = 0;
	int		count_c02 = 0;
	int		x = 0;
	int		y = 0;
	int		z = 0;
	int		i = 0;
	int		u = 0;
	int		c1 = 0;
	int		c2 = 0;
	char	oxygen_bit[12] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
	char	c02_bit[12] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
	int		oxygen_generator_rating = 0;
	int		c02_scrubber_rating = 0;
	int		life_support_rating = 0;
	int		num[12] = {2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};

	arr = (char **)malloc(sizeof(char*) * 1000);
	arr_oxy = (char **)malloc(sizeof(char*) * 1000);
	arr_c02 = (char **)malloc(sizeof(char*) * 1000);
	fd = open("input", O_RDONLY);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		arr[x] = ft_strdup(line);
		x++;
		if (line[z] == '0')
		{
			count_oxygen -= 1;
			count_c02 -= 1;
		}
		else
		{
			count_oxygen += 1;
			count_c02 += 1;
		}
		if (line != NULL)
			free(line);
	}
	for (y = 0; y < 12; y++)
	{
		if (count_oxygen < 0)
			oxygen_bit[z] = '0';
		else if (count_oxygen == 0)
			oxygen_bit[z] = '1';
		else
			oxygen_bit[z] = '1';
		if (count_c02 < 0)
			c02_bit[z] = '1';
		else if (count_c02 == 0)
			c02_bit[z] = '0';
		else
			c02_bit[z] = '0';
		z++;
		count_oxygen = 0;
		count_c02 = 0;
		c1 = 0;
		c2 = 0;
		if( i > 1)
			for (int j = 0; j < i; j++)
				ft_strdel(&arr_oxy[j]);
		if (u > 1)
			for (int j = 0; j < u; j++)
				ft_strdel(&arr_c02[j]);

		for (x = 0; x < 1000; x++)
		{
			if (strncmp(oxygen_bit, arr[x], z) == 0)
			{
				arr_oxy[c1] = ft_strdup(arr[x]);
				c1++;
				if (arr[x][z] == '0')
					count_oxygen -= 1;
				else
					count_oxygen += 1;
			}
			if (strncmp(c02_bit, arr[x], z) == 0)
			{
				arr_c02[c2] = ft_strdup(arr[x]);
				c2++;
				if (arr[x][z] == '0')
					count_c02 -= 1;
				else
					count_c02 += 1;
			}
		}
		i = c1;
		u = c2;
	}
	for (x = 0; x < 12; x++)
	{
		if (arr_oxy[0][x] == '1')
			oxygen_generator_rating += num[x];
		if (arr_c02[0][x] == '1')
			c02_scrubber_rating += num[x];
	}
	ft_strdel(&arr_oxy[0]);
	ft_strdel(&arr_c02[0]);
	for (x = 0; x < 1000; x++)
		ft_strdel(&arr[x]);
	free(arr_c02);
	free(arr_oxy);
	free(arr);
	printf("Oxygen:[%d] ", oxygen_generator_rating);
	printf("C02:[%d] ", c02_scrubber_rating);
	life_support_rating = oxygen_generator_rating * c02_scrubber_rating;
	printf("Life Support rating:[%d]\n", life_support_rating);
	close (fd);
	return (0);
}
