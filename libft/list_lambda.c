/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_lambda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 01:40:48 by kshore            #+#    #+#             */
/*   Updated: 2023/08/12 02:34:32 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	comment("While lst is not NULL, call f with lst's \
	content as a parameter and set lst to lst's next");
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped;
	t_list	*tmp;
	void	*tmp_data;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	mapped = NULL;
	while (lst)
	{
		tmp_data = (*f)(lst->content);
		tmp = ft_lstnew(tmp_data);
		if (!tmp)
		{
			free(tmp_data);
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped, tmp);
		lst = lst->next;
	}
	return (mapped);
}
