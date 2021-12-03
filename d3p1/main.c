/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/03 09:06:58 by conguyen         ###   ########.fr       */
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
	char	*line;
	int		ret;
	int		bit[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int		gamma_rate = 0;
	int		epsilon_rate = 0;
	int		power_consumption = 0;
	int		num[12] = {2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};

	fd = open("input", O_RDONLY);
	ret = 1;
	line = NULL;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		for (int x = 0; x < 12; x++)
		{
			if (line[x] == '0')
				bit[x] -= 1;
			else
				bit[x] += 1;
		}
		if (line != NULL)
			free(line);
	}
	for (int x = 0; x < 12; x++)
	{
		if (bit[x] > 0)
			gamma_rate += num[x];
		else
			epsilon_rate += num[x];
	}
	power_consumption = epsilon_rate * gamma_rate;
	printf("Gamma: [%d]", gamma_rate);
	printf(" Epsilon:[%d]", epsilon_rate);
	printf(" Power consumption:[%d]\n", power_consumption);
	close (fd);
	return (0);
}
