#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    if(s == NULL)
        return NULL;
    if(ft_strlen(s) <= start)
        return ft_calloc(1, 1);
    if(ft_strlen(&s[start]) < len)
        len = ft_strlen(&s[start]);
    char *str = ft_calloc(1, len + 1);
    if (str == NULL)
        return NULL;
    unsigned long i = 0;
    while (i < len)
    {
        str[i] = s[i + start];
        i++;
    }
    str[i] = '\0';
    return str;
}
