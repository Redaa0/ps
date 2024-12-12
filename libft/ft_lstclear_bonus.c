/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:40:12 by rmoutaou          #+#    #+#             */
/*   Updated: 2023/11/13 17:19:32 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*store;

	if (!lst)
		return ;
	p = *lst;
	while (p)
	{
		store = p->next;
		del(p->content);
		free(p);
		p = store;
	}
	*lst = NULL;
}
