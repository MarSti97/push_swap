/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_back_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:35:45 by mstiedl           #+#    #+#             */
/*   Updated: 2023/02/02 14:43:14 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_fit(int smaller, int middle, int bigger)
{
	if (smaller < middle && middle < bigger)
		return (1);
	else
		return (0);
}

void	exec_rot(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*b_last;

	last = ft_lstlast(*stack_a);
	b_last = ft_lstlast(*stack_b);
	if ((*stack_b)->next && \
	check_fit(last->pos, b_last->pos, (*stack_a)->pos) == 1)
	{
		ft_rotate(stack_a, stack_b, 10);
		ft_push(stack_b, stack_a, 4);
		ft_rotate(stack_a, stack_b, 6);
	}
	else if ((*stack_b)->next && \
	check_fit(last->pos, (*stack_b)->next->pos, (*stack_a)->pos) == 1)
	{
		ft_swap(*stack_a, *stack_b, 2);
		ft_push(stack_b, stack_a, 4);
		ft_rotate(stack_a, stack_b, 6);
	}
	ft_rotate(stack_a, stack_b, 6);
}

void	exec_rev_rot(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*b_last;

	last = ft_lstlast(*stack_a);
	b_last = ft_lstlast(*stack_b);
	if (b_last->prev && check_fit(last->pos, b_last->pos, (*stack_a)->pos) == 1)
	{
		ft_rotate(stack_a, stack_b, 10);
		ft_push(stack_b, stack_a, 4);
	}
	else if ((*stack_b)->next && \
	check_fit(last->pos, (*stack_b)->next->pos, (*stack_a)->pos) == 1)
	{
		ft_swap(*stack_a, *stack_b, 2);
		ft_push(stack_b, stack_a, 4);
	}
	ft_rotate(stack_a, stack_b, 9);
}

int	find_pos(t_list *stack, int find)
{
	int	found;
	int	dif;
	int	i;

	dif = 0;
	i = 0;
	found = 0;
	while (stack)
	{
		if (stack->pos > find && dif == 0)
		{
			dif = stack->pos - find;
			found = i;
		}
		else if (stack->pos > find && (stack->pos - find) < dif)
		{
			dif = stack->pos - find;
			found = i;
		}
		i++;
		stack = stack->next;
	}
	return (found);
}
