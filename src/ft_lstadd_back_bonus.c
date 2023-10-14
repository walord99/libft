/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walord <walord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:48:39 by Ben               #+#    #+#             */
/*   Updated: 2023/10/13 21:37:37 by walord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_back(t_list *lst, void *content)
{
	if (!lst)
		lst = ft_lstnew(content);
	else
		ft_lstlast(lst)->next = ft_lstnew(content);
	return lst;
}
