/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <rmoutaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 03:04:41 by rmoutaou          #+#    #+#             */
/*   Updated: 2024/05/07 09:09:39 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	increment_range(int *start, int *end, int size)
{
	if (*start < *end)
		(*start)++;
	if (size - 1 > *end)
		(*end)++;
}

static void	push_and_rotate(t_node **a, t_node **b)
{
	pb(a, b);
	if (lstsize(*b) > 1)
		rb(b);
}

static void	push_and_swap(t_node **a, t_node **b)
{
	pb(a, b);
	if (lstsize(*b) > 1 && (*b)->next->number > (*b)->number)
		sb(b);
}

void	big_sort(t_node **a, t_node **b, int *end)
{
	int	start;
	int	*sorted_arr;
	int	size;

	start = 0;
	sorted_arr = sorted_array(a);
	size = lstsize(*a);
	while (*a)
	{
		if ((*a)->number <= sorted_arr[start])
		{
			push_and_rotate(a, b);
			increment_range(&start, end, size);
		}
		else if ((*a)->number <= sorted_arr[*end])
		{
			push_and_swap(a, b);
			increment_range(&start, end, size);
		}
		else
			ra(a);
	}
	free(sorted_arr);
}

int	sort_norm(t_node **a)
{
	if ((*a)->number > (*a)->next->number
		&& (*a)->next->number > (*a)->next->next->number
		&& (*a)->number > (*a)->next->next->number)
	{
		return (0);
	}
	return (1);
}
