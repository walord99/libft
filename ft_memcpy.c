/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:03:45 by bplante           #+#    #+#             */
/*   Updated: 2023/02/14 13:18:23 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst_ptr;
	unsigned const char	*src_ptr;

	dst_ptr = dest;
	src_ptr = src;
	if (dest == NULL || src == NULL)
		return (dest);
	while (n--)
		*(dst_ptr + n) = *(src_ptr + n);
	return (dest);
}
