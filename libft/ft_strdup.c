/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abzaiz <abzaiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:10 by abzaiz            #+#    #+#             */
/*   Updated: 2023/12/16 12:02:36 by abzaiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	s1_len;

	s1_len = ft_strlen(s1) + 1;
	str = (char *)malloc(s1_len * sizeof(char));
	if (!str)
		return (NULL);
	return (ft_memmove(str, s1, s1_len));
}
