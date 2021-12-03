/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/03 09:06:54 by conguyen         ###   ########.fr       */
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
	int		forward;
	int		depth;
	char	*tmp;
	int		aim;

	fd = open("input", O_RDONLY);
	ret = 1;
	forward = 0;
	depth = 0;
	aim = 0;
	line = NULL;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ft_strncmp(line, "for", 3) == 0)
		{
			tmp = ft_strrev(line);
			forward += ft_atoi(tmp);
			if (aim >= 1)
				depth += ft_atoi(tmp) * aim;
			free(tmp);
		}
		else if (ft_strncmp(line, "up ", 3) == 0)
		{
			tmp = ft_strrev(line);
			aim -= ft_atoi(tmp);
			free(tmp);
		}
		else if (ft_strncmp(line, "dow", 3) == 0)
		{
			tmp = ft_strrev(line);
			aim += ft_atoi(tmp);
			free(tmp);
		}
		if (line != NULL)
			free(line);
	}
	printf("forward: [%d] depth: [%d]\n", forward, depth);
	printf("Total: [%d]\n", forward * depth);
	close (fd);
	return (0);
}
