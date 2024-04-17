/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:17:50 by kshore            #+#    #+#             */
/*   Updated: 2023/08/02 02:10:40 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *str, int fd)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}
