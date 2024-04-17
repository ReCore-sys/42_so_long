/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_modify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 01:34:22 by kshore            #+#    #+#             */
/*   Updated: 2023/08/12 01:47:29 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	comment("If lst is NULL, set lst to new");
	if (!*lst)
		*lst = new;
	else
	{
		comment("Set new's next to lst");
		new->next = *lst;
		comment("Set lst to new");
		*lst = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	comment("If lst is NULL, set lst to new");
	if (!*lst)
		*lst = new;
	else
	{
		comment("Set last to lst");
		last = *lst;
		comment("While last's next is not NULL, set last to last's next");
		while (last->next)
			last = last->next;
		comment("Set last's next to new");
		last->next = new;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	comment("If lst is not NULL, call del with lst's content as a parameter");
	if (lst)
		del(lst->content);
	comment("Free lst");
	free(lst);
}
