/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/15 17:54:40 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*input = NULL;
char	*tmpinput1;
char	*tmpinput2;
int		size = 32;

int		ft_strstri(const char *haystack, const char *needle)
{
	size_t	needle_len;
	int	count = 0;

	needle_len = ft_strlen(needle);
	if (*needle == '\0')
		return (-1);
	while (*haystack != '\0')
	{
		if (haystack[count] == needle[0]
			&& ft_strncmp(haystack, needle, needle_len) == 0)
			return (count);
		count++;
	}
	return (-1);
}

void	insert_elem(char *pair, char *insert)
{
	int		get_end = 0;
	int		get_start = 0;
	char	*tmp;
	char	*tmp_start;
	char	*joined;

	get_start = ft_strstri(tmpinput1, pair);
	get_start = get_start + 2;
	get_end = ft_strlen(tmpinput1);
	//printf("start: %d end: %d\n", get_start, get_end);
	if (get_start == 2)
	{
		get_end = get_end + 2;
		printf("start: %d end: %d\n", get_start, get_end);
		tmp = ft_strsub(tmpinput1, get_start, get_end);
		if (input != NULL)
			free(input);
		input = ft_strjoin(insert, tmp);
		free(tmp);
		free(insert);
		free(pair);
		printf("%s\n", input);
	}
	if (get_start > 2)
	{
		tmp_start = ft_strsub(tmpinput1, 0, get_start);
		tmp = ft_strsub(tmpinput1, get_start, get_end);
		joined = ft_strjoin(insert, tmp);
		if (input != NULL)
			free(input);
		input = ft_strjoin(tmp_start, joined);
		free(tmp);
		free(tmp_start);
		free(joined);
		free(insert);
		free(pair);
	}
}

void	get_pair_insertion(char *line)
{
	char	*pair;
	char	*insert;

	pair = ft_strnew(sizeof(char) * 3);
	insert = ft_strnew(sizeof(char) * 4);
	for (int x = 0; x < 2; x++)
		pair[x] = line[x];
	pair[2] = '\0';
	insert[0] = pair[0];
	insert[1] = line[6];
	insert[2] = pair[1];
	insert_elem(pair, insert);
}

int main(void)
{
	int		fd;
	char	*line;
	int		ret;
	//int		steps = 1;

	tmpinput1 = (char *)malloc(sizeof(char) * size + 1);
	ft_strcpy(tmpinput1, "NNCB");
	tmpinput2 = ft_strdup(tmpinput1);
	fd = open("input", O_RDONLY);
	ret = 1;
	// for (int x = 0; x < steps; x++)
	// {
		while (ret)
		{
			ret = get_next_line(fd, &line);
			get_pair_insertion(line);
			if (line != NULL)
				free(line);
		}
		close(fd);
	// }
	//printf("%s\n", input);
	return (0);
}