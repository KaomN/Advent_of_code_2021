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

int main(void)
{
	int		ret = 1;
	int		fd;
	char	*line = NULL;

	fd = open("input", O_RDONLY);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		
		if (line != NULL)
			free(line);
	}
	close(fd);
	return (0);
}