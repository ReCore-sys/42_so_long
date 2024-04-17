/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:13:53 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 01:55:18 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *str1, const void *str2, unsigned long n)
{
	unsigned long	i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && (i < n - 1))
		i++;
	return (s1[i] - s2[i]);
}
// Line 26: iterate through both strings until they are not equal
// or until the end of the string is reached.
// If they aren't equal, return the difference
// between the two strings at the current index.
// If the end of the string is reached, return the
// difference between the two strings at the current index.
// If the end of the string is reached, return 0.
