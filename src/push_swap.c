/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <rmoutaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 03:04:46 by rmoutaou          #+#    #+#             */
/*   Updated: 2024/05/07 09:10:03 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dups(t_node *head)
{
	t_node	*current;
	t_node	*check;

	current = head;
	while (current != NULL)
	{
		check = current->next;
		while (check != NULL)
		{
			if (current->number == check->number)
			{
				free_all(&head, NULL);
				write(2, "Error\n", 6);
				exit(1);
			}
			check = check->next;
		}
		current = current->next;
	}
}

static	void	parse_all(int ac, char **av, t_node **a)
{
	int		i;
	int		index;
	t_node	*last_node;
	char	**tokens;

	i = 1;
	last_node = NULL;
	index = 0;
	while (i < ac)
	{
		if (check_empty(av[i]) == 1)
		{
			free_all(a, NULL);
			write(2, "Error\n", 6);
			exit(1);
		}
		tokens = ft_split(av[i], ' ');
		parse_tokens(tokens, a, &last_node, &index);
		free(tokens);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		parse_all(ac, av, &a);
		check_dups(a);
		if (check_sorted(a))
		{
			free_all(&a, &b);
			exit(0);
		}
		stack_sort(&a, &b);
		free_all(&a, &b);
		return (0);
	}
	else
		return (0);
}
