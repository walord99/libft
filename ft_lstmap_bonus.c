#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_lst = NULL;
    t_list *new_node;
    while (lst)
    {
        new_node = ft_calloc(sizeof(t_list), 1);
        if (!new_node)
        {
            ft_lstclear(&new_lst, del);
            return (NULL);
        }
        new_node->content = (*f)(lst->content);
        ft_lstadd_back(&new_lst, new_node);
        lst = lst->next;
    }
    return new_lst;
}
