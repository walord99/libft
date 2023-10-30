/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:15:31 by bplante           #+#    #+#             */
/*   Updated: 2023/10/30 19:31:45 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdel_element(t_list *list, t_list *node, void (*del)(void *))
{
	t_list	*ret_val;
	t_list	*temp;

	ret_val = list;
	if (list && node)
	{
		if (list == node)
		{
			ret_val = list->next;
			ft_lstdelone(node, del);
		}
		else
		{
			while (list->next != node && list)
				list = list->next;
			if (list)
			{
				temp = list->next->next;
				ft_lstdelone(list->next, del);
				list->next = temp;
			}
		}
	}
	return (ret_val);
}
