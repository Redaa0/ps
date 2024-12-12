/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <rmoutaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 03:05:04 by rmoutaou          #+#    #+#             */
/*   Updated: 2024/05/07 09:10:14 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mylstclear(t_node **lst)
{
	t_node	*p;
	t_node	*store;

	if (!lst)
		return ;
	p = *lst;
	while (p)
	{
		store = p->next;
		free(p);
		p = store;
	}
	*lst = NULL;
}

int	lstsize(t_node *lst)
{
	t_node	*current;
	int		count;

	if (!lst)
		return (0);
	current = lst;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	find_min_index(t_node *a)
{
	t_node	*current;
	int		min_value;
	int		min_index;

	current = a;
	min_value = current->number;
	min_index = current->index;
	while (current)
	{
		if (current->number < min_value)
		{
			min_value = current->number;
			min_index = current->index;
		}
		current = current->next;
	}
	return (min_index);
}

int	find_max_index(t_node *a)
{
	t_node	*current;
	int		max_value;
	int		max_index;

	current = a;
	max_value = current->number;
	max_index = current->index;
	while (current)
	{
		if (current->number > max_value)
		{
			max_value = current->number;
			max_index = current->index;
		}
		current = current->next;
	}
	return (max_index);
}

int	atoi_error(int *flag)
{
	*flag = 1;
	return (0);
}
