#include "libft.h"

char	*ft_strdup(const char *s1)
{
    if (s1 == NULL)
        return NULL;
    char *str = ft_calloc(1, ft_strlen(s1) + 1);
    int i = 0;
    while(s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
