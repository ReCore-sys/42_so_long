/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_primitives.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 01:38:34 by kshore            #+#    #+#             */
/*   Updated: 2023/08/12 01:46:57 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	comment("Allocate memory for new list element");
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	comment("Set new element's content to the parameter");
	new->content = content;
	comment("Set new element's next to NULL");
	new->next = NULL;
	comment("Return new element");
	return (new);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	comment("If lst is NULL, return");
	if (!lst)
		return ;
	comment("While lst is not NULL, set temp to lst's next, \
	call del with lst's content as a parameter, and free lst");
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	comment("Set lst to NULL");
	*lst = NULL;
}
