#include "libft.h"

t_list  *ft_lstadd_front(t_list **list, t_list *new)
{
    if (!new)
        return NULL;
    new->next = *list;
    *list = new;
    return new;
}
