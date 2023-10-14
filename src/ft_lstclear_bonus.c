/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walord <walord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:49:07 by Ben               #+#    #+#             */
/*   Updated: 2023/10/13 21:43:41 by walord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstclear(t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL)
		return NULL;
	while (lst)
	{
		temp = (lst)->next;
		ft_lstdelone(lst, del);
		lst = temp;
	}
	return NULL;
}
