/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen _long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:02:30 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/06 18:18:35 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** ft_strlen() function calculates the length of the string pointed to by s,
** excluding the terminating null byte ('\0').
**
** RETURN VALUES
** ft_strlen() function returns the number of bytes in the string pointed to
** by s.
*/

long	ft_strlen_long(const char *s)
{
	long	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
