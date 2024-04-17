/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:05:28 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 02:11:15 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (*str != '\0')
	{
		f(i, str);
		str++;
		i++;
	}
}
