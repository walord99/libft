/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walord <walord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:49:13 by Ben               #+#    #+#             */
/*   Updated: 2023/10/13 21:32:13 by walord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*new_lst;

	new_lst = NULL;
	while (lst)
	{
		ft_lstadd_back(&new_lst, (*f)(lst->content));
		lst = lst->next;
	}
	return (new_lst);
}
