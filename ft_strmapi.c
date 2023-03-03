#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    if(!s)
        return NULL;
    unsigned int i = 0;
    if (!s)
        return NULL;
    char *new_str = ft_calloc(1, ft_strlen(s) + 1);
    if (!new_str)
        return NULL;
    while(s[i])
    {
        new_str[i] = (*f)(i, s[i]);
        i++;
    }
    new_str[i] = 0;
    return new_str;
}
