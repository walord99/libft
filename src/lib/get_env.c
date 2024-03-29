/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <benplante99@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:22:13 by bplante           #+#    #+#             */
/*   Updated: 2024/03/02 15:49:40 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*get_env(char **env, char *key)
{
	int		i;
	int		j;
	char	*sub_str;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub_str = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub_str, key) == 0)
		{
			free(sub_str);
			return (&env[i][j] + 1);
		}
		free(sub_str);
		i++;
	}
	return (NULL);
}
