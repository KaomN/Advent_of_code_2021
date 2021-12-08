/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/08 11:04:20 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	count_output_values(char *line)
{
	int	count = 0;
	int count_char = 0;
	int	x = 0;

	while (line[x] != '|')
		x++;
	for (int y = x + 1; line[y] != '\0'; y++)
	{
		if (line[y] == ' ')
		{
			if (count_char == 2 || count_char == 3 || count_char == 4 || count_char == 7)
			{
				count++;
				count_char = 0;
			}
			count_char = 0;
		}
		else
			count_char++;
		printf("[%d]\n", count_char);
		
	}
	if (count_char == 2 || count_char == 3 || count_char == 4 || count_char == 7)
		count++;
	return (count);
}

int main(void)
{
	int		fd;
	char	*line;
	int		ret;
	int		count = 0;

	fd = open("input", O_RDONLY);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		count += count_output_values(line);
		if (line != NULL)
			free(line);
	}
	close(fd);
	printf("count:[%d]", count);
	return (0);
}