/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walord <walord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:49:06 by Ben               #+#    #+#             */
/*   Updated: 2023/10/13 21:37:03 by walord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_front(t_list *list, void *content)
{
	t_list *new_front;
	new_front = ft_lstnew(content);
	if (!new_front)
		return (NULL);
	new_front->next = list;
	return (new_front);
}
