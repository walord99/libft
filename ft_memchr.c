/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:43:26 by bplante           #+#    #+#             */
/*   Updated: 2023/02/16 14:49:09 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	tlf;
	unsigned long	i;

	if (str == NULL)
		return ((void *)str);
	i = 0;
	tlf = c;
	ptr = (unsigned char *)str;
	while (i < n)
	{
		if (ptr[i] == tlf)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}
