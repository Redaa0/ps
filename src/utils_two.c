/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <rmoutaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 03:12:35 by rmoutaou          #+#    #+#             */
/*   Updated: 2024/05/07 09:10:11 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	offset_calc(t_node **a, int index)
{
	t_node	*head;
	int		distance;

	distance = 0;
	head = *a;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	check_sorted(t_node *a)
{
	while (a)
	{
		if (a->next)
		{
			if (a->number > a->next->number)
				return (0);
		}
		a = a->next;
	}
	return (1);
}

static	void	bubble_sort(t_node **a, int *sorted_arr)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < lstsize(*a) - 1)
	{
		j = 0;
		while (j < lstsize(*a) - i - 1)
		{
			if (sorted_arr[j] > sorted_arr[j + 1])
			{
				temp = sorted_arr[j];
				sorted_arr[j] = sorted_arr[j + 1];
				sorted_arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*sorted_array(t_node **a)
{
	t_node	*current;
	int		i;
	int		*sorted_arr;

	current = *a;
	sorted_arr = malloc(sizeof(int) * lstsize(*a));
	i = 0;
	while (current)
	{
		sorted_arr[i] = current->number;
		current = current->next;
		i++;
	}
	bubble_sort(a, sorted_arr);
	return (sorted_arr);
}

int	ft_myatoi(const char *nptr, int *flag)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		if ((result * sign) > (INT_MAX - (nptr[i] - '0')) / 10
			|| (result * sign) < (INT_MIN + (nptr[i] - '0')) / 10)
			return (atoi_error(flag));
		result = (nptr[i++] - 48) + (result * 10);
	}
	if (nptr[i] != '\0')
		return (atoi_error(flag));
	return (result * sign);
}
