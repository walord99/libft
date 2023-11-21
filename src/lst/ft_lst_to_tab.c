/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:58:28 by bplante           #+#    #+#             */
/*   Updated: 2023/11/21 08:03:37 by bplante          ###   ########.fr       */
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
