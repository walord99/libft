/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:49:07 by Ben               #+#    #+#             */
/*   Updated: 2023/11/10 02:15:03 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstclear(t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		temp = (lst)->next;
		ft_lstdelone(lst, del);
		lst = temp;
	}
	return (NULL);
}
