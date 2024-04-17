/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:23:34 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 02:10:27 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, unsigned long len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *) b;
	while (i < len)
	{
		str[i] = (char) c;
		i++;
	}
	return (b);
}
