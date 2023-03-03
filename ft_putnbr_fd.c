#include "libft.h"
#include <unistd.h>

static unsigned int exponent(int base, int exponent);

void    ft_putnbr_fd(int n, int fd)
{
    int n_cpy = n;
    int i = 0;
    while (n_cpy && ++i)
        n_cpy /= 10;
    int power = exponent(10, i - 1);
    if (n == 0)
        write(fd, "0", 1);
    if (n < 0)
        write(fd, "-", 1);
    while (i--)
    {
        ft_putchar_fd(ft_num_to_char(n / power), fd);
        n %= power;
        power /= 10;
    }
}

static unsigned int exponent(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
