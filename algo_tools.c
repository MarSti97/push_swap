/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:24:39 by mstiedl           #+#    #+#             */
/*   Updated: 2023/02/03 10:08:33 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_stop(t_list *stack_a, int divide)
{
	while (stack_a->next)
	{
		if (stack_a->pos <= divide)
			return (1);
		stack_a = stack_a->next;
	}
	if (stack_a->pos <= divide)
		return (1);
	return (0);
}

int	how_to_divide(int len, int full, int time)
{
	int	divide;

	if (time == 1)
	{
		if (len >= 100)
			divide = full / 5;
		else
			divide = full / 2;
	}
	else
	{
		if (len > 100)
			divide = (full / 10);
		else
			divide = (len / 2);
	}
	return (divide);
}

void	check_rotate(t_list **stack_a, t_list **stack_b)
{
	int	front;
	int	back;

	front = perfect_order(*stack_a);
	back = perfect_order_rev(*stack_a);
	if (front > back)
	{
		while (back--)
			ft_rotate(stack_a, stack_b, 9);
	}
	else
	{
		while (front--)
			ft_rotate(stack_a, stack_b, 6);
	}
}

void	no_b(t_list **stack_a, t_list **stack_b, int front)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if (last->pos <= front)
	{
		ft_rotate(stack_a, stack_b, 9);
		ft_push(stack_a, stack_b, 5);
	}
	else
		ft_push(stack_a, stack_b, 5);
}

void	three_or_less(t_list **stack_a, t_list **stack_b, int len)
{	
	if ((*stack_a)->next && (*stack_a)->pos - (*stack_a)->next->pos == 1)
		ft_swap(*stack_a, *stack_b, 1);
	else if (len == 2)
		ft_push(stack_a, stack_b, 5);
	else if ((*stack_a)->pos - (*stack_a)->next->next->pos == -1)
		ft_swap(*stack_a, *stack_b, 1);
	else if ((*stack_a)->next && (*stack_a)->pos - (*stack_a)->next->pos == -1)
		ft_rotate(stack_a, stack_b, 9);
	else if ((*stack_a)->next && \
	(*stack_a)->pos - (*stack_a)->next->next->pos == 1)
		ft_rotate(stack_a, stack_b, 6);
	else if ((*stack_a)->next && (*stack_a)->pos - (*stack_a)->next->pos != -1)
		ft_push(stack_a, stack_b, 5);
}
