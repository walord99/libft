#include "libft.h"
#include <stdlib.h>

char    *ft_strtrim(char const *s1, char const *set)
{
 // check if either input string is NULL
    if (s1 == NULL || set == NULL)
        return NULL;

    // determine the length of the input string and the set
    size_t len1 = 0;
    while (s1[len1] != '\0')
        len1++;
    size_t len_set = 0;
    while (set[len_set] != '\0')
        len_set++;

    // determine the index of the first non-set character
    size_t start = 0;
    while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
        start++;

    // determine the index of the last non-set character
    size_t end = len1 - 1;
    while (end > start && ft_strchr(set, s1[end]) != NULL)
        end--;

    // allocate memory for the trimmed string
    size_t trimmed_len = end - start + 1;
    char *result = ft_calloc(trimmed_len + 1, 1);
    if (result == NULL)
        return NULL;

    // copy the non-set characters into the trimmed string
    for (size_t i = 0; i < trimmed_len; i++)
        result[i] = s1[start + i];
    result[trimmed_len] = '\0';

    return result;
}
