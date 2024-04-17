/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:12:11 by kshore            #+#    #+#             */
/*   Updated: 2023/08/12 01:09:54 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Returns a pointer to the last occurrence of the character c in the string s.
char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*start;

	i = ft_strlen(s);
	start = s;
	while (i >= 0)
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
