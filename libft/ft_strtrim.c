/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:59:25 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 02:46:45 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trimmed_str;
	int		start_index;
	int		end_index;
	int		trimmed_length;
	int		i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start_index = 0;
	while (s1[start_index] && ft_strchr(set, s1[start_index]))
		start_index++;
	end_index = ft_strlen((char *)s1) - 1;
	while (end_index >= 0 && ft_strchr(set, s1[end_index]))
		end_index--;
	if (end_index < start_index)
		return (ft_strdup(""));
	trimmed_length = end_index - start_index + 2;
	trimmed_str = (char *)malloc(sizeof(char) * trimmed_length);
	if (!trimmed_str)
		return (NULL);
	while (start_index <= end_index)
		trimmed_str[i++] = s1[start_index++];
	trimmed_str[i] = '\0';
	return (trimmed_str);
}
