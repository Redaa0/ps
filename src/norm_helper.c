/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <rmoutaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 03:46:31 by rmoutaou          #+#    #+#             */
/*   Updated: 2024/05/07 09:09:45 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_flag(t_node **a, t_node *node, char *token, char **tokens)
{
	free_all(a, NULL);
	if (node)
		free(node);
	if (token)
		free(token);
	if (tokens)
		free(tokens);
	write(2, "Error\n", 6);
	exit(1);
}

int	check_empty(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!str[0])
		return (1);
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		return (1);
	return (0);
}

t_node	*create_new_node(char *token, int *flag, int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->number = ft_myatoi(token, flag);
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

int	check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
			i++;
		else if (!ft_isdigit(str[i]))
			return (1);
		else
			i++;
	}
	return (0);
}

void	parse_tokens(char **tokens, t_node **a, t_node **last_node, int *index)
{
	int		j;
	int		flag;
	t_node	*new_node;

	j = 0;
	flag = 0;
	while (tokens[j])
	{
		if (check_char(tokens[j]) == 1)
			exit_flag(a, NULL, tokens[j], tokens);
		new_node = create_new_node(tokens[j], &flag, (*index)++);
		if (flag == 1)
			exit_flag(a, new_node, tokens[j], tokens);
		if (*last_node == NULL)
			*a = new_node;
		else
			(*last_node)->next = new_node;
		*last_node = new_node;
		free(tokens[j]);
		j++;
	}
}
