/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:26:33 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 02:49:18 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, unsigned long n)
{
	char	*str;

	str = (char *) s;
	while (n-- > 0)
		*str++ = '\0';
}

/**
 * The function comment takes a string as input and does nothing with it.
 * It is only used for the sake of getting around norminette.
 */
void	comment(char *comment)
{
	(void)comment;
}
