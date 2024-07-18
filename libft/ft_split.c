/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abzaiz <abzaiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:36:55 by abzaiz            #+#    #+#             */
/*   Updated: 2024/07/16 17:18:20 by abzaiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static int	count_words(char *s)
{
	int		counter;
	bool	inside_quotes;
	char	current_quote;

	1 && (counter = 0, inside_quotes = false, current_quote = '\0');
	while (*s)
	{
		while (*s && (*s == ' ' || (*s >= 9 && *s <= 13)) && !inside_quotes)
			s++;
		if (*s && (!(*s == ' ' || (*s >= 9 && *s <= 13)) || inside_quotes))
		{
			while (*s && (!(*s == ' ' || (*s >= 9 && *s <= 13)) || inside_quotes))
			{
				if ((*s == '\'' || *s == '\"') && (!inside_quotes || current_quote == *s))
				{
					inside_quotes = !inside_quotes;
					if (inside_quotes)
						current_quote = *s;
				}
				s++;
			}
			counter++;
		}
	}
	return (counter);
}

static int	word_length(char *s)
{
	int		index;
	bool	inside_quotes;
	char	current_quote;

	index = 0;
	inside_quotes = false;
	current_quote = '\0';
	while (s[index] && (!((s[index] == ' ' || (s[index] >= 9 && s[index] <= 13)) && !inside_quotes)))
	{
		if ((s[index] == '\'' || s[index] == '\"') && (!inside_quotes || current_quote == s[index]))
		{
			inside_quotes = !inside_quotes;
			if (inside_quotes)
				current_quote = s[index];
		}
		index++;
	}
	return (index);
}

static void	*free_memory(char **result, int length)
{
	int	index;

	index = 0;
	while (index < length)
		free(result[index++]);
	free(result);
	return (NULL);
}

char	**ft_split(char *s)
{
	char	**result;
	int		index;
	int		words_count;
	int		length_of_word;

	if (s == NULL)
		return (NULL);
	words_count = count_words(s);
	result = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (index < words_count)
	{
		while (*s && (*s == ' ' || (*s >= 9 && *s <= 13)))
			s++;
		length_of_word = word_length(s);
		result[index] = ft_substr(s, 0, length_of_word);
		if (!result[index])
			return (free_memory(result, index), NULL);
		index++;
		s += length_of_word;
	}
	result[index] = NULL;
	return (result);
}
