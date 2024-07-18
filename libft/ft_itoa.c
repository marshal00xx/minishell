/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abzaiz <abzaiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:31:38 by abzaiz            #+#    #+#             */
/*   Updated: 2023/12/16 12:50:25 by abzaiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		counter = 1;
	while (n)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		length;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = nbr_len(n);
	result = (char *)malloc(length + 1);
	if (!result)
		return (NULL);
	result[length] = '\0';
	if (n == 0)
		result[0] = '0';
	else if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	while (n)
	{
		result[--length] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
