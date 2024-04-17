/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:31:13 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 02:10:19 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned long len)
{
	char			*dst1;
	char			*src1;
	unsigned long	i;

	if (!dst && !src)
		return (NULL);
	dst1 = (char *) dst;
	src1 = (char *) src;
	i = 0;
	comment("If src is less than dst, copy backwards to \
	avoid overwriting the source.");
	if (dst1 > src1)
	{
		while (len--)
			dst1[len] = src1[len];
	}
	else
	{
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	return (dst);
}
