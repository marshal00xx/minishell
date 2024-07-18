#include "libft.h"

char *ft_skip_spaces(char *str)
{
    while (*str == ' ' || (*str >= 8 && *str <= 13))
        str++;
    return (str);
}
