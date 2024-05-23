/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_string_valid_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <benplante99@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:58:19 by bplante           #+#    #+#             */
/*   Updated: 2024/05/23 15:00:58 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_string_int(char *str, int sign);

bool	is_string_valid_int(char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (ft_strlen(str) == 0)
		return (false);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
		if (ft_strlen(str) == 1)
			return (false);
	}
	while (str[i] == '0')
		i++;
	if ((ft_strlen(&str[i]) == 10 && !is_string_int(&str[i], sign))
		|| ft_strlen(&str[i]) > 10)
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (false);
	}
	return (true);
}

bool	is_string_int(char *str, int sign)
{
	int		i;
	char	*max_int;

	max_int = "2147483647";
	i = 0;
	while (i < 9)
	{
		if (str[i] > max_int[i])
			return (false);
		if (str[i] < max_int[i])
			return (true);
		i++;
	}
	if (sign > 0 && str[i] > max_int[i])
		return (false);
	else if (str[i] > max_int[i] + 1)
		return (false);
	return (true);
}
