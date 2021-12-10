/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/10 15:25:53 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*line_chunks;
int		count = 0;
char	saved[100];
int		z = 0;

void	check_line(char	*line_chunks)
{
	for (int x = 0; x < count; x++)
	{
		if ((line_chunks[x] == '(' && line_chunks[x + 1] == ')')
		|| (line_chunks[x] == '[' && line_chunks[x + 1] == ']')
		|| (line_chunks[x] == '<' && line_chunks[x + 1] == '>')
		|| (line_chunks[x] == '{' && line_chunks[x + 1] == '}'))
		{
			ft_strncpy(&line_chunks[x], &line_chunks[x + 2], count - x - 1);
			count = count - 2;
			x = x - 2;
		}
		else if ((line_chunks[x] == '(' && line_chunks[x + 1] == ']') || (line_chunks[x] == '(' && line_chunks[x + 1] == '>') || (line_chunks[x] == '(' && line_chunks[x + 1] == '}')
			|| (line_chunks[x] == '[' && line_chunks[x + 1] == ')') || (line_chunks[x] == '[' && line_chunks[x + 1] == '>') || (line_chunks[x] == '[' && line_chunks[x + 1] == '}')
			|| (line_chunks[x] == '<' && line_chunks[x + 1] == ')') || (line_chunks[x] == '<' && line_chunks[x + 1] == ']') || (line_chunks[x] == '<' && line_chunks[x + 1] == '}')
			|| (line_chunks[x] == '{' && line_chunks[x + 1] == ')') || (line_chunks[x] == '{' && line_chunks[x + 1] == '>') || (line_chunks[x] == '{' && line_chunks[x + 1] == ']'))
		{
			saved[z++] = line_chunks[x + 1];
		}
	}
}

void	calc_points()
{
	int	res = 0;

	for (int x = 0; x < z; x++)
	{
		if (saved[x] == ')')
			res += 3;
		else if (saved[x] == ']')
			res += 57;
		else if (saved[x] == '}')
			res += 1197;
		else if (saved[x] == '>')
			res += 25137;
	}
	printf("Answer: [%d]\n", res);
}

int main(void)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("input", O_RDONLY);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		line_chunks = ft_strdup(line);
		count = (int)ft_strlen(line_chunks);
		check_line(line_chunks);
		free(line_chunks);
		if (line != NULL)
			free(line);
	}
	close(fd);
	fd = ret;
	printf("Found corrupted: ");
	for (int x = 0; x < z; x++)
		printf("%c ", saved[x]);
	printf("\n");
	calc_points();
	return (0);
}