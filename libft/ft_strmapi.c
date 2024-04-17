/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:01:36 by kshore            #+#    #+#             */
/*   Updated: 2023/07/25 23:03:18 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	if (!str || !f)
		return (NULL);
	res = (char *)malloc(ft_strlen((char *)str) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = f(i, str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
