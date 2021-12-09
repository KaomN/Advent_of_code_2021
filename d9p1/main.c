/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/09 14:29:20 by conguyen         ###   ########.fr       */
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
			if (x == 0 && y == 0)
				if (arr[x][y] < arr[x][y + 1] && arr[x][y] < arr[x + 1][y])
					count += arr[x][y] + 1;
			// top right corner
			else if (x == 0 && y == 9)
				if (arr[x][y] < arr[x][y - 1] && arr[x][y] < arr[x + 1][y])
					count += arr[x][y] + 1;
			// bottom left corner
			else if (y == 0 && x == 4)
				if (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x][y + 1])
					count += arr[x][y] + 1;
			// bottom right corner
			else if (x == 4 && y == 9)
				if (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x][y - 1])
					count += arr[x][y] + 1;
			// first row
			else if (x == 0)
				if (arr[x][y] < arr[x][y + 1] && arr[x][y] < arr[x + 1][y] && arr[x][y] < arr[x][y - 1])
					count += arr[x][y] + 1;
			// first column
			else if (y == 0)
				if (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x + 1][y] && arr[x][y] < arr[x][y + 1])
					count += arr[x][y] + 1;
			// last row
			else if (x == 4)
				if (arr[x][y] < arr[x][y - 1] && arr[x][y] < arr[x][y + 1] && arr[x][y] < arr[x - 1][y])
					count += arr[x][y] + 1;
			// last column
			else if (y == 9)
				if (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x + 1][y] && arr[x][y] < arr[x][y - 1])
					count += arr[x][y] + 1;
			else
				if (arr[x][y] < arr[x - 1][y] && arr[x][y] < arr[x + 1][y] && arr[x][y] < arr[x][y + 1] && arr[x][y] < arr[x][y - 1])
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