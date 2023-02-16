/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:27:15 by bplante           #+#    #+#             */
/*   Updated: 2023/02/14 15:16:14 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = ft_strlen(src);
	if (dest)
	{
		if (destsize > 0)
		{
			while (src[i] && i < destsize - 1)
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
	}
	return (j);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*src;
// 	char	*dest;

// 	dest = NULL;
// 	src = NULL;
// 	//ft_bzero(dest, 15);
// 	ft_strlcpy(dest, src, 15);
// }
