/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:44:25 by bplante           #+#    #+#             */
/*   Updated: 2023/02/16 17:01:59 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_isalnum.c"
// #include "ft_isalpha.c"
// #include "ft_isdigit.c"
#include "libft.h"

static int	is_space(char c);

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result + (str[i] - '0');
		if (ft_isdigit(str[i + 1]))
			result = result * 10;
		i++;
	}
	return (result * sign);
}

static int	is_space(char c)
{
	if (c >= 1 && c <= 32)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	i;

// 	i = ft_atoi("\t\n\r\v\f  469 \n");
// }
