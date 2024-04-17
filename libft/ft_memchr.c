/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:12:37 by kshore            #+#    #+#             */
/*   Updated: 2023/08/07 16:32:39 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/// Returns a pointer to the first occurrence of the character
/// c in the first n bytes of the string s.
void	*ft_memchr(const void *s, int c, unsigned long n)
{
	char				*str;
	unsigned long		i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
