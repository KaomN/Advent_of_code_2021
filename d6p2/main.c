/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/06 20:44:11 by conguyen         ###   ########.fr       */
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
	char	*input = "3,4,1,1,5,1,3,1,1,3,5,1,1,5,3,2,4,2,2,2,1,1,1,1,5,1,1,1,1,1,3,1,1,5,4,1,1,1,4,1,1,1,1,2,3,2,5,1,5,1,2,1,1,1,4,1,1,1,1,3,1,1,3,1,1,1,1,1,1,2,3,4,2,1,3,1,1,2,1,1,2,1,5,2,1,1,1,1,1,1,4,1,1,1,1,5,1,4,1,1,1,3,3,1,3,1,3,1,4,1,1,1,1,1,4,5,1,1,3,2,2,5,5,4,3,1,2,1,1,1,4,1,3,4,1,1,1,1,2,1,1,3,2,1,1,1,1,1,4,1,1,1,4,4,5,2,1,1,1,1,1,2,4,2,1,1,1,2,1,1,2,1,5,1,5,2,5,5,1,1,3,1,4,1,1,1,1,1,1,1,4,1,1,4,1,1,1,1,1,2,1,2,1,1,1,5,1,1,3,5,1,1,5,5,3,5,3,4,1,1,1,3,1,1,3,1,1,1,1,1,1,5,1,3,1,5,1,1,4,1,3,1,1,1,2,1,1,1,2,1,5,1,1,1,1,4,1,3,2,3,4,1,3,5,3,4,1,4,4,4,1,3,2,4,1,4,1,1,2,1,3,1,5,5,1,5,1,1,1,5,2,1,2,3,1,4,3,3,4,3";
	int		inputlen = ft_strlen(input);
	long	fish[9] = {0,0,0,0,0,0,0,0,0};
	long	newfish[9]= {0,0,0,0,0,0,0,0,0};
	long	tmp;

	for (int x = 0; x < inputlen; x++)
	{
		if (input[x] <= '9' && input[x] >= '0')
		{
			if(input[x] == '1')
				fish[1] += 1;
			if(input[x] == '2')
				fish[2] += 1;
			if(input[x] == '3')
				fish[3] += 1;
			if(input[x] == '4')
				fish[4] += 1;
			if(input[x] == '5')
				fish[5] += 1;
		}
	}
	for (int z = 0; z < 9; z++)
		newfish[z] = fish[z];
	for (int x = 0; x < 256; x++)
	{
		tmp = newfish[0];
		fish[0] = newfish[1];
		fish[1] = newfish[2];
		fish[2] = newfish[3];
		fish[3] = newfish[4];
		fish[4] = newfish[5];
		fish[5] = newfish[6];
		fish[6] = newfish[7];
		fish[7] = newfish[8];
		if (tmp > 0)
		{
			fish[8] = tmp;
			fish[6] = tmp + fish[6];
			tmp = 0;
		}
		else
			fish[8] = tmp;
		for (int z = 0; z < 9; z++)
			newfish[z] = fish[z];
	}
	printf("Total fish: %ld\n", fish[0] + fish[1] + fish[2] + fish[3] + fish[4] + fish[5] + fish[6] + fish[7] + fish[8]);
	return (0);
}