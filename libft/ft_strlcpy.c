/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:55:16 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 02:07:40 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

unsigned long	ft_strlcpy(char *dst, const char *src, unsigned long dstsize)
{
	unsigned long	i;
	unsigned long	len;

	len = 0;
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (len);
}
