/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:18:37 by bplante           #+#    #+#             */
/*   Updated: 2023/11/10 05:11:38 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void free_f(char *s1, char *s2, int f)
{
	if ((f & FREE_S1) == FREE_S1)
		free(s1);
	if ((f & FREE_S2) == FREE_S2)
		free(s2);
}

char	*ft_strjoin_free(char *s1, char *s2, int f)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i++])
			str[i-1] = s1[i-1];
		i -= 1;
	}
	if (s2)
	{
		j = 0;
		while (s2[j])
			str[i++] = s2[j++];
	}
	str[i] = '\0';
	free_f(s1, s2, f);
	return (str);
}
