/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/06 20:50:28 by conguyen         ###   ########.fr       */
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
	char	*fish;
	char	*input = "3,4,1,1,5,1,3,1,1,3,5,1,1,5,3,2,4,2,2,2,1,1,1,1,5,1,1,1,1,1,3,1,1,5,4,1,1,1,4,1,1,1,1,2,3,2,5,1,5,1,2,1,1,1,4,1,1,1,1,3,1,1,3,1,1,1,1,1,1,2,3,4,2,1,3,1,1,2,1,1,2,1,5,2,1,1,1,1,1,1,4,1,1,1,1,5,1,4,1,1,1,3,3,1,3,1,3,1,4,1,1,1,1,1,4,5,1,1,3,2,2,5,5,4,3,1,2,1,1,1,4,1,3,4,1,1,1,1,2,1,1,3,2,1,1,1,1,1,4,1,1,1,4,4,5,2,1,1,1,1,1,2,4,2,1,1,1,2,1,1,2,1,5,1,5,2,5,5,1,1,3,1,4,1,1,1,1,1,1,1,4,1,1,4,1,1,1,1,1,2,1,2,1,1,1,5,1,1,3,5,1,1,5,5,3,5,3,4,1,1,1,3,1,1,3,1,1,1,1,1,1,5,1,3,1,5,1,1,4,1,3,1,1,1,2,1,1,1,2,1,5,1,1,1,1,4,1,3,2,3,4,1,3,5,3,4,1,4,4,4,1,3,2,4,1,4,1,1,2,1,3,1,5,5,1,5,1,1,1,5,2,1,2,3,1,4,3,3,4,3";
	int		count = 300;
	int		oldcount = 0;
	int		spawned = 0;
	int		c =0;
	char	*newfish;

	fish = (char *)malloc(sizeof(char) * count);
	for (int x = 0; input[x] != '\0'; x++)
	{
		if (input[x] <= '9' && input[x] >= '0')
		{
			fish[c] = input[x];
			c++;
		}
	}
	for (int x = 0; x < 80; x++)
	{
		for (int y = 0; y < count; y++)
		{
			if (fish[y] == '0')
			{
				fish[y] = '6';
				spawned++;
			}
			else
				fish[y]--;
		}
		if(spawned > 0)
		{
			oldcount = count;
			count += spawned;
			newfish = realloc(fish, count);
			fish = newfish;
			for (int z = oldcount; z < count; z++)
				fish[z] = '8';
		}
		spawned = 0;
	}
	//printf("%s", fish);
	printf("Total fish: %d\n", count);
	return (0);
}