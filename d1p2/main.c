/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/02 16:27:17 by conguyen         ###   ########.fr       */
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
	int		countn1;
	int		countn2;
	int		n1;
	int		n2;
	int		n1cmp;
	int		n2cmp;
	int		count;

	fd = open("input", O_RDONLY);
	ret = 1;
	countn1 = 0;
	countn2 = 0;
	n1 = 0;
	n2 = 0;
	n1cmp = 0;
	n2cmp = 0;
	count = 0;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (n1 != 0)
		{
			n2 += ft_atoi(line);
			countn2++;
			if (countn2 == 3)
			{
				if (n2cmp != 0 && n1cmp != 0)
				{
					if (n2cmp < n1cmp)
						count++;
				}
				n2cmp = n2;
				if (n1cmp < n2cmp)
					count++;
				n2 = ft_atoi(line);
				countn2 = 1;
			}
		}
		n1 += ft_atoi(line);
		countn1++;
		if (countn1 == 3)
		{
			n1cmp = n1;
			n1 = ft_atoi(line);
			countn1 = 1;
		}
	}
	printf("[%d]\n", count);
	free(line);
	return (0);
}