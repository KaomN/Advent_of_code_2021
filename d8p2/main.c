/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/08 14:59:03 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"


// 7 i know 3, 0 and 6;
// 4 i know 5, 2 and 9;
// 1 is always 2 char long
// 7 is always 3 char long
// 4 is always 4 char long
// 8 is always 7 char long

int analyse_input(char *s)
{
	char	*line = s;
	char	arr_s7[4] = "...";
	char	arr_s4[5] = "....";
	char	output[5] = "....";
	int		num = 0;
	int		char_count = 0;
	int		x = 0;
	int		count = 0;

	while (line[x] != '|')
		x++;
	x++;
	for (int y = 0; line[y] != '\0'; y++)
	{
		if (line[y] == ' ')
		{
			if (char_count == 3)
			{
				arr_s7[2] = line[y - 1];
				arr_s7[1] = line [y - 2];
				arr_s7[0] = line [y - 3];
				break ;
			}
			char_count = 0;
		}
		else
			char_count++;
	}
	char_count = 0;
	for (int y = 0; line[y] != '\0'; y++)
	{
		if (line[y] == ' ')
		{
			if (char_count == 4)
			{
				arr_s4[3] = line[y - 1];
				arr_s4[2] = line [y - 2];
				arr_s4[1] = line [y - 3];
				arr_s4[0] = line [y - 4];
				break ;
			}
			char_count = 0;
		}
		else
			char_count++;
	}
	char_count = 0;
	for (int y = x + 1; y > 0; y++)
	{
		if (line[y] == ' ' || line[y] == '\0')
		{
			if (char_count == 2)
			{
				output[num] = '1';
				num++;
			}
			else if (char_count == 3)
			{
				output[num] = '7';
				num++;
			}
			else if (char_count == 4)
			{
				output[num] = '4';
				num++;
			}
			else if (char_count == 7)
			{
				output[num] = '8';
				num++;
			}
			else if (char_count == 5)
			{
				count = 0;
				for (int z = 1; z < 6; z++)
				{
					for (int i = 0; i < 4; i++)
					{
						if (arr_s4[i] == line[y - z])
						{
							count++;
							break ;
						}
					}
				}
				if (count == 3)
				{
					count = 0;
					for (int z = 1; z < 6; z++)
					{
						for (int i = 0; i < 3; i++)
						{
							if (arr_s7[i] == line[y - z])
							{
								count++;
								break ;
							}
						}
					}
					if (count == 3)
						output[num] = '3';
					else
						output[num] = '5';
				}
				else
					output[num] = '2';
				num++;
			}
			else if (char_count == 6)
			{
				count = 0;
				for (int z = 1; z < 7; z++)
				{
					for (int i = 0; i < 4; i++)
					{
						if (arr_s4[i] == line[y - z])
						{
							count++;
							break ;
						}
					}
				}
				if (count == 4)
					output[num] = '9';
				else
				{
					count = 0;
					for (int z = 1; z < 7; z++)
					{
						for (int i = 0; i < 3; i++)
						{
							if (arr_s7[i] == line[y - z])
							{
								count++;
								break ;
							}
						}
					}
					if (count == 3)
						output[num] = '0';
					else
						output[num] = '6';
				}
				num++;
			}
			char_count = 0;
		}
		else
			char_count++;
		if (output[0] != '.' && output[1] != '.' && output[2] != '.' && output[3] != '.')
			break ;
	}
	return (ft_atoi(output));
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
		count += analyse_input(line);
		if (line != NULL)
			free(line);
	}
	close(fd);
	printf("output value:[%d]\n", count);
	return (0);
}