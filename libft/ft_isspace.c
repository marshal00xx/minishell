#include "libft.h"

bool    ft_isspace(int c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}
