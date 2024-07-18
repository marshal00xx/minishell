/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abzaiz <abzaiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:12:05 by abzaiz            #+#    #+#             */
/*   Updated: 2023/12/16 13:59:49 by abzaiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (s1 && !set)
		return ((char *)s1);
	result = NULL;
	if (s1 && set)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (end > start && s1[end - 1] && ft_strchr(set, s1[end - 1]))
			end--;
		result = (char *)malloc(sizeof(char) * (end - start + 1));
		if (result)
			ft_strlcpy(result, s1 + start, end - start + 1);
	}
	return (result);
}
