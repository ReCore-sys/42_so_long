/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:25:06 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 02:11:52 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *str, const char *substr, unsigned int len)
{
	unsigned int	stri;
	unsigned int	sub;
	char			*result;

	if (len == 0 && !str)
		return ((char *)0);
	result = (char *)str;
	stri = -1;
	if (!substr[0])
		return (result);
	while (result[++stri] && stri < len)
	{
		sub = 0;
		while (result[stri + sub] == substr[sub] && (stri + sub) < len)
		{
			if (!substr[sub + 1])
				return (&result[stri]);
			sub++;
		}
	}
	return ((char *)0);
}
