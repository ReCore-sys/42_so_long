/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:57:33 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 02:06:20 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long dstsize)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	res;

	if ((!dst && !src) || (!dstsize && !src))
		return (0);
	i = 0;
	j = 0;
	res = 0;
	while (dst[i] != '\0')
		i++;
	while (src[res] != '\0')
		res++;
	if (dstsize <= i)
		res += dstsize;
	else
		res += i;
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
