/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:14:08 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 02:45:10 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	numlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char	*strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i++;
		j--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	res = (char *)malloc(numlen(n) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (n > 9 || n < -9)
	{
		comment("n % 10 is the last digit of n, so add it to the end of res");
		res[i++] = (n % 10) * sign + '0';
		n /= 10;
	}
	res[i++] = n * sign + '0';
	if (sign == -1)
		res[i++] = '-';
	res[i] = '\0';
	comment("Since the digits were added in reverse order, reverse res");
	return (strrev(res));
}
