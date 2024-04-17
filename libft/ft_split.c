/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 01:00:17 by kshore            #+#    #+#             */
/*   Updated: 2023/08/12 02:50:26 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	count_words(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !(str[i] == c))
			i++;
	}
	return (count);
}

static int	get_word_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	return (i);
}

static char	*allocate_word(char *str, char c)
{
	int		word_len;
	int		i;
	char	*word;

	i = -1;
	word_len = get_word_len(str, c);
	word = (char *)malloc(word_len + 1);
	while (++i < word_len)
		word[i] = str[i];
	word[i] = '\0';
	return (word);
}

// Return a null pointer afterwards so we can save a couple lines in ft_split
void	*freestring(char **string, int i)
{
	int	a;

	a = 0;
	while (a <= i)
		free(string[i++]);
	free(string);
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	char	**sub_strings;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (str == NULL)
		return (NULL);
	sub_strings = (char **) malloc(sizeof(char *) * \
	(count_words((char *)str, c) + 1));
	if (sub_strings == NULL)
		return (NULL);
	while (str[j] != '\0')
	{
		while (str[j] != '\0' && (str[j] == c))
			j++;
		if (str[j] != '\0')
			sub_strings[i++] = allocate_word((char *)&str[j], c);
		if (i > 0 && sub_strings[i - 1] == NULL)
			return (freestring(sub_strings, i - 1));
		while (str[j] && !(str[j] == c))
			j++;
	}
	sub_strings[i] = 0;
	return (sub_strings);
}
