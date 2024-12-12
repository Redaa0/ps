/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <rmoutaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 03:04:54 by rmoutaou          #+#    #+#             */
/*   Updated: 2024/05/07 09:10:06 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				index;
	int				number;
	struct s_node	*next;
	int				*array;
}	t_node;

int		ft_myatoi(const char *nptr, int *flag);
int		atoi_error(int *flag);
void	exit_flag(t_node **a, t_node *node, char *token, char **tokens);
int		check_empty(char *str);
t_node	*create_new_node(char *token, int *flag, int index);
void	parse_tokens(char **tokens, t_node **a, t_node **last_node, int *index);
void	ft_mylstclear(t_node **lst);
int		lstsize(t_node *lst);
void	free_all(t_node **a, t_node **b);
int		sort_norm(t_node **a);
int		find_min_index(t_node *a);
int		find_max_index(t_node *a);
int		offset_calc(t_node **a, int index);
int		check_sorted(t_node *a);
int		*sorted_array(t_node **a);
void	stack_sort(t_node **a, t_node **b);
void	small_sort(t_node **a, t_node **b);
void	sort_3(t_node **a);
void	sort_4(t_node **a, t_node **b);
void	big_sort(t_node **a, t_node **b, int *end);

void	swap(t_node **a);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	push(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	rotate(t_node **a);
void	ra(t_node **a);
void	rb(t_node	**b);
void	rr(t_node **a, t_node **b);
void	reverse_rotate(t_node **a);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

void	free_all(t_node **a, t_node **b);

#endif