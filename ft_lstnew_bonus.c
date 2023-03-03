#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *node = ft_calloc(sizeof(t_list), 1);
    if (!node)
		return (NULL);
    node->content = content;
    return node;
}
