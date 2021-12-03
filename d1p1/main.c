/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/03 09:06:14 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_compare(char* s1, char* s2)
{
	if (ft_atoi(s1) < ft_atoi(s2))
		return (1);
	return (0);
}

int main(void)
{
	int		fd;
	char	*line;
	int		ret;
	char	*temp;
	int		count;

	fd = open("input", O_RDONLY);
	ret = 1;
	count = 0;
	temp = NULL;
	line = NULL;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (temp != NULL)
		{
			count += ft_compare(temp, line);
			free(temp);
		}
		temp = ft_strdup(line);
		printf("[%s]\n", temp);
		if (line != NULL)
			free(line);
	}
	free(temp);
	close (fd);
	printf("%d\n", count);
	return (0);
}