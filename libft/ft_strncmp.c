/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:11:38 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 02:11:39 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	int				res;
	unsigned char	unsinged1;
	unsigned char	unsinged2;

	if (n == 0)
		return (0);
	i = 0;
	res = 0;
	while ((i < n && res == 0) && (s1[i] != '\0' || s2[i] != '\0'))
	{
		unsinged1 = (unsigned char)s1[i];
		unsinged2 = (unsigned char)s2[i];
		res = unsinged1 - unsinged2;
		i++;
	}
	return (res);
}
