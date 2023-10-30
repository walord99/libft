/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:04:41 by bplante           #+#    #+#             */
/*   Updated: 2023/10/30 19:11:21 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind_one(t_list *list, bool (*equal)(void *, void *), void *data)
{
	while (list)
	{
		if ((*equal)(list->content, data))
			return (list);
		list = list->next;
	}
	return (NULL);
}