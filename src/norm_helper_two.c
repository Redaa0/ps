/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_helper_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <rmoutaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:35:49 by rmoutaou          #+#    #+#             */
/*   Updated: 2024/05/07 09:09:41 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_node **a, t_node **b)
{
	if (a)
		ft_mylstclear(a);
	if (b)
		ft_mylstclear(b);
}

void	sort_5(t_node **a, t_node **b)
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
	{
		rra(a);
		rra(a);
	}
	else if (offset == 4)
		rra(a);
	if (check_sorted(*a) == 1)
		return ;
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}

void	small_sort(t_node **a, t_node **b)
{
	if (lstsize(*a) == 2)
		sa(a);
	else if (lstsize(*a) == 3)
		sort_3(a);
	else if (lstsize(*a) == 4)
		sort_4(a, b);
	else if (lstsize(*a) == 5)
		sort_5(a, b);
}
