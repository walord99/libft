/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <benplante99@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:58:28 by bplante           #+#    #+#             */
/*   Updated: 2024/05/20 13:44:43 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*lst_to_tab(t_list *list)
{
	char	**tab;
	int		i;

	tab = ft_calloc(ft_lstsize(list) + 1, sizeof(void *));
	if (!tab)
		return (NULL);
	i = 0;
	while (list)
	{
		tab[i] = (char *)list->content;
		list = list->next;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
