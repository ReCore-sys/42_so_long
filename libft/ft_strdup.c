/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:35:26 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 02:11:03 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
