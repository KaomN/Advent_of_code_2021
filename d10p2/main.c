/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/10 15:25:43 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*line_chunks;
int		count = 0;
long	saved[100];
int		z = 0;

void	swap(int x)
{
	long	temp = saved[x];
	saved[x] = saved[x + 1];
	saved[x + 1] = temp;
}

void bubble_sort()
{
	int i, j;
	for (i = 0; i < z-1; i++)
		for (j = 0; j < z-i-1; j++)
			if (saved[j] > saved[j+1])
				swap(j);
}

void	check_line(char	*line_chunks)
{
	int		corrupted = 0;
	long	res = 0;
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
			corrupted = 1;
			break ;
		}
	}
	if (corrupted == 0)
	{
		for (int x = count; x >= 0; x--)
		{
			if (line_chunks[x] == '(')
				res = res * 5 + 1;
			else if (line_chunks[x] == '[')
				res = res * 5 + 2;
			else if (line_chunks[x] == '{')
				res = res * 5 + 3;
			else if (line_chunks[x] == '<')
				res = res * 5 + 4;
		}
		saved[z++] = res;
	}
}

int main(void)
{
	int		fd;
	char	*line;
	int		ret;
	long	answer = 0;

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
	bubble_sort();
	answer = saved[z / 2];
	// for (int x = 0; x < z; x++)
	// 	printf("[%ld]\n", saved[x]);
	printf("Middle score: [%ld]\n", answer);
	return (0);
}