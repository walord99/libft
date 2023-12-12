/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:57:04 by bplante/Wal       #+#    #+#             */
/*   Updated: 2023/12/12 01:59:18 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int len)
{
	char	*new_str;
	int		i;

	new_str = ft_calloc(len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}
