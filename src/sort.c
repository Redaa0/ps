/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <rmoutaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 03:05:02 by rmoutaou          #+#    #+#             */
/*   Updated: 2024/05/07 09:10:09 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_node **a)
{
	if ((*a)->number < (*a)->next->number
		&& (*a)->next->number > (*a)->next->next->number
		&& (*a)->number < (*a)->next->next->number)
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->number > (*a)->next->number
		&& (*a)->next->number < (*a)->next->next->number
		&& (*a)->number < (*a)->next->next->number)
		sa(a);
	else if (sort_norm(a) == 0)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->number < (*a)->next->number
		&& (*a)->next->number > (*a)->next->next->number
		&& (*a)->number > (*a)->next->next->number)
		rra(a);
	else if ((*a)->number > (*a)->next->number
		&& (*a)->next->number < (*a)->next->next->number
		&& (*a)->number > (*a)->next->next->number)
		ra(a);
}

void	sort_4(t_node **a, t_node **b)
{
	int	offset;

	offset = offset_calc(a, find_min_index(*a));
	if (offset == 1)
		ra(a);
	else if (offset == 2)
	{
		ra(a);
		ra(a);
	}
	else if (offset == 3)
		rra(a);
	if (check_sorted(*a) == 1)
		return ;
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	end_big_sort(t_node **a, t_node **b)
{
	int	max_index;

	while (*b)
	{
		if ((*b)->index == find_max_index(*b))
			pa(a, b);
		else if ((*b)->next && (*b)->next->index == find_max_index(*b))
			sb(b);
		else
		{
			max_index = find_max_index(*b);
			if (offset_calc(b, max_index) <= lstsize(*b) / 2)
			{
				while ((*b)->index != max_index)
					rb(b);
			}
			else if (offset_calc(b, max_index) > lstsize(*b) / 2)
			{
				while ((*b)->index != max_index)
					rrb(b);
			}
			pa(a, b);
		}
	}
}

void	stack_sort(t_node **a, t_node **b)
{
	int	end;

	end = 0;
	if (lstsize(*a) <= 5)
		small_sort(a, b);
	else
	{
		if (lstsize(*a) >= 6 && lstsize(*a) <= 18)
			end = 3;
		else if (lstsize(*a) <= 100)
			end = 15;
		else if (lstsize(*a) <= 500)
			end = 45;
		else
			end = 50;
		big_sort(a, b, &end);
		end_big_sort(a, b);
	}
}
