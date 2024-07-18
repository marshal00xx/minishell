#include "libft.h"

void ft_free_list_chars(char **list)
{
    size_t i;

    i = 0;
    while (list[i])
    {
        free(list[i]);
        i++;
    }
    free(list);
}