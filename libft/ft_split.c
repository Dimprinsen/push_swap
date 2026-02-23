/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2026/02/23 18:03:38 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strallocate(char *start, char *end)
{
	int		len;
	int		i;
	char	*word;

	len = end - start;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	ft_free(char **arr, int i)
{
	while (i--)
		free(arr[i]);
	free(arr);
}

static int	count_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	char	*start;
	int		i;

	result = malloc(sizeof(char *) * (count_words((char *)str, c) + 1));
	if (!result || !str)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			start = (char *)str;
			while (*str && *str != c)
				str++;
			result[i] = strallocate(start, (char *)str);
			if (!result[i])
				return (ft_free(result, i), NULL);
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}
