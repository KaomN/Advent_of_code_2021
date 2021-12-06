/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_toint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:59:34 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/05 10:42:32 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** ft_strsplit() function allocates with malloc(3) and returns an array of
** "fresh" strings (all ending with '\0' including the array itself) obtained
** by splitting s using the character c as a delimiter.
*/

static int	ft_skipc(char const *s, char c, int count)
{
	while (s[count] != '\0' && s[count] == c)
		count++;
	return (count);
}

static int	ft_skipnotc(char const *s, char c, int count)
{
	while (s[count] != '\0' && s[count] != c)
		count++;
	return (count);
}

int	*ft_strsplit_toint(char const *s, char c)
{
	int		*intarr;
	int		count;
	size_t	x;
	size_t	wordcount;

	if (s == NULL)
		return (NULL);
	count = 0;
	x = 0;
	wordcount = ft_wordcount(s, c);
	intarr = (int *)malloc(sizeof(int) * wordcount);
	while (x < wordcount)
	{
		count = ft_skipc(s, c, count);
		intarr[x] = ft_atoi(&s[count]);
		count = ft_skipnotc(s, c, count);
		x++;
	}
	return (intarr);
}
