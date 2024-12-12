/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <rmoutaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 03:32:03 by rmoutaou          #+#    #+#             */
/*   Updated: 2024/05/07 09:10:26 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_node **a, t_node **b)
{
	push(a, b);
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
}

void	rotate(t_node **a)
{
	t_node	*tmp;
	t_node	*last;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		last = *a;
		while (last->next)
			last = last->next;
		last->next = tmp;
	}
}

void	ra(t_node **a)
{
	rotate(a);
}

void	rb(t_node **b)
{
	rotate(b);
}
