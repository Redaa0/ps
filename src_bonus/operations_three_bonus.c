/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_three_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <rmoutaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 03:32:35 by rmoutaou          #+#    #+#             */
/*   Updated: 2024/05/07 09:10:23 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_node **a)
{
	t_node	*tmp;
	t_node	*prev;

	if (*a && (*a)->next)
	{
		prev = NULL;
		tmp = *a;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
		tmp->next = *a;
		*a = tmp;
	}
}

void	rra(t_node **a)
{
	reverse_rotate(a);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
