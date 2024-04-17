/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:32:01 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 01:48:51 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(unsigned long count, unsigned long size)
{
	void	*res;

	comment("Allocate us some juicy memory.");
	res = malloc(count * size);
	comment("If for whatever reason we can't allocate memory, return NULL.");
	if (!res)
		return (NULL);
	comment("Fill the allocated memory with zeroes.");
	ft_bzero(res, count * size);
	return (res);
}
