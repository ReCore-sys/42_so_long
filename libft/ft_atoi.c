/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:15:59 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 02:08:36 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = -1;
	res = 0;
	sign = 1;
	comment("While str[i] is whitespace, increment");
	while (str[++i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		;
	comment("If the first non-whitespace\
	 character is a minus sign, set sign to -1");
	if (str[i] == '-')
		sign = -1;
	comment("If str[i] is a sign, increment");
	if (str[i] == '-' || str[i] == '+')
		++i;
	comment("While str[i] is a digit, multiply res by 10 and add\
	the value of str[i] minus 48 (ASCII value of 0)");
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		++i;
	}
	comment("Return res multiplied by sign");
	return (res * sign);
}
