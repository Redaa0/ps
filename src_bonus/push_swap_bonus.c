/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <rmoutaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:24:53 by rmoutaou          #+#    #+#             */
/*   Updated: 2024/05/07 09:10:28 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	check_dups(t_node *head)
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

int	execute_instruction(char *line, t_node **a, t_node **b)
{
	if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		rra(a);
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		rrb(b);
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		rrr(a, b);
	else if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		sa(a);
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		sb(b);
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		ss(a, b);
	else if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		pa(a, b);
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		pb(a, b);
	else if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		ra(a);
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		rb(b);
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		rr(a, b);
	else
		return (-1);
	return (0);
}

int	process_lines(t_node **a, t_node **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (execute_instruction(line, a, b) == -1)
		{
			write(2, "Error\n", 6);
			free_all(a, b);
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	return (1);
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
		if (!process_lines(&a, &b))
			return (0);
		if (check_sorted(a) && !b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_all(&a, &b);
		return (0);
	}
	else
		return (0);
}
