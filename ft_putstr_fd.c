#include "libft.h"

void    ft_putstr_fd(char *s, int fd)
{
    if(!s)
        return;
    unsigned int i = 0;
    while (s[i])
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
}
