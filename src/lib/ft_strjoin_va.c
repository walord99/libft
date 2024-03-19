/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_va.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <benplante99@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:09:21 by bplante           #+#    #+#             */
/*   Updated: 2024/03/18 21:33:16 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	total_len(int arg_count, va_list args)
{
	int	len;

	len = 0;
	while (arg_count != 0)
	{
		len += ft_strlen(va_arg(args, char *));
		arg_count--;
	}
	return (len);
}

char	*ft_strjoin_va(int arg_count, ...)
{
	va_list	args;
	va_list	arg2;
	int		len;
	char	*str;

	va_start(args, arg_count);
	va_copy(arg2, args);
	len = total_len(arg_count, args);
	str = ft_calloc(len + 1, sizeof(char));
	va_end(args);
	if (!str)
		return (NULL);
	while (arg_count != 0)
	{
		ft_strlcat(str, va_arg(arg2, char *), len + 1);
		arg_count--;
	}
	va_end(arg2);
	return (str);
}
