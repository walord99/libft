#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char *str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
    int i = 0;
    if (s1)
    {
        while (s1[i])
        {
            str[i] = s1[i];
            i++;
        }
    }
    if (s2)
    {
        int j = 0;
        while(s2[j])
        {
            str[i] = s2[j];
            i++;
            j++;
        }
    }
    str[i] = '\0';
    return str;
}
