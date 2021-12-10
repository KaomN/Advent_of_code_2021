/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/10 10:12:07 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	check_array(int	arr[100][100])
{
	int	count = 0;
	for (int x = 0; x < 100; x++)
	{
		for (int y = 0; y < 100; y++)
		{
			// top left corner
			if ((x == 0 && y == 0) && (arr[x][y] < arr[x][y + 1] && arr[x][y] < arr[x + 1][y]))
				count += arr[x][y] + 1;
			// top right corner
			if ((x == 0 && y == 99) && (arr[x][y] < arr[x][y - 1] && arr[x][y] < arr[x + 1][y]))
				count += arr[x][y] + 1;
			// bottom left corner
			if ((y == 0 && x == 99) && (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x][y + 1]))
				count += arr[x][y] + 1;
			// bottom right corner
			if ((x == 99 && y == 99) && (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x][y - 1]))
				count += arr[x][y] + 1;
			// first row
			if ((x == 0 && y > 0 && y < 99) && (arr[x][y] < arr[x][y + 1] && arr[x][y] < arr[x + 1][y] && arr[x][y] < arr[x][y - 1]))
				count += arr[x][y] + 1;
			// first column
			if ((y == 0 && x > 0 && x < 99) && (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x + 1][y] && arr[x][y] < arr[x][y + 1]))
				count += arr[x][y] + 1;
			// last row
			if ((x == 99 && y > 0 && y < 99) && (arr[x][y] < arr[x][y - 1] && arr[x][y] < arr[x][y + 1] && arr[x][y] < arr[x - 1][y]))
				count += arr[x][y] + 1;
			// last column
			if ((y == 99 && x > 0 && x < 99) && (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x + 1][y] && arr[x][y] < arr[x][y - 1]))
				count += arr[x][y] + 1;
			// inside
			if ((y > 0 && y < 99 && x > 0 && x < 99) && (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x + 1][y] && arr[x][y] < arr[x][y + 1] && arr[x][y] < arr[x][y - 1]))
				count += arr[x][y] + 1;
		}
	}
	return (count);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		ret;
	int		arr[100][100];
	int		count = 0;


	fd = open("input", O_RDONLY);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		for (unsigned int x = 0; x < ft_strlen(line); x++)
			arr[count][x] = line[x] - '0';
		count++;
		if (line != NULL)
			free(line);
	}
	count = check_array(arr);
	printf("%d", count);
	close(fd);
	return (0);
}