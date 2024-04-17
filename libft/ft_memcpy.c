/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:29:26 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 02:09:55 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, unsigned long n)
{
	char	*str;
	char	*str2;

	if (!dst && !src)
		return (NULL);
	str = (char *) dst;
	str2 = (char *) src;
	comment("Increment both pointers by one until n is 0, \
		copying the value of str into str2 each time.");
	while (n-- > 0)
		*str++ = *str2++;
	return (dst);
}
