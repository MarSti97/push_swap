/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:17:14 by mstiedl           #+#    #+#             */
/*   Updated: 2023/02/02 10:30:40 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	keep_a(t_list **stack_a, t_list **stack_b, int front)
{
	if ((*stack_a)->pos - (*stack_a)->next->pos == 1)
		ft_swap(*stack_a, *stack_b, 1);
	else if (*stack_b && (*stack_a)->pos - (*stack_b)->pos == 1)
		ft_push(stack_a, stack_b, 5);
	else if ((*stack_a)->pos > front)
	{
		while ((*stack_a)->pos - (*stack_a)->next->pos == -1)
			ft_rotate(stack_a, stack_b, 6);
		if ((*stack_a)->pos > front)
			ft_rotate(stack_a, stack_b, 6);
	}
}

void	last_to_b(t_list **stack_a, t_list **stack_b, int front, int half)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if (!*stack_b)
		return ;
	if ((*stack_a)->pos <= front)
	{
		if ((*stack_a)->pos <= half && last->pos <= half \
		&& (*stack_a)->pos < last->pos)
			return ;
		else if ((*stack_a)->pos > half && last->pos > half \
		&& (*stack_a)->pos < last->pos)
			return ;
	}
	else if (last->pos <= half || last->pos - (*stack_b)->pos == 1)
	{
		ft_rotate(stack_a, stack_b, 9);
		ft_push(stack_a, stack_b, 5);
	}
	else if (last->pos > half)
	{
		ft_rotate(stack_a, stack_b, 9);
		ft_push(stack_a, stack_b, 5);
		ft_rotate(stack_a, stack_b, 7);
	}
}

void	check_options(t_list **stack_a, t_list **stack_b, int front, int half)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if (last->pos <= front)
		last_to_b(stack_a, stack_b, front, half);
	if (!*stack_b)
		no_b(stack_a, stack_b, front);
	else if (last->pos - (*stack_b)->pos == 1)
	{
		ft_rotate(stack_a, stack_b, 9);
		ft_push(stack_a, stack_b, 5);
	}
	else if ((*stack_a)->pos <= front)
	{
		if ((*stack_a)->pos - (*stack_a)->next->pos == 1)
			ft_swap(*stack_a, *stack_b, 1);
		else if ((*stack_a)->pos <= half)
			ft_push(stack_a, stack_b, 5);
		else
		{
			ft_push(stack_a, stack_b, 5);
			ft_rotate(stack_a, stack_b, 7);
		}
	}
}

int	split_stack(t_list **stack_a, t_list **stack_b, int divide, int len)
{
	t_list		*last;
	int			order;
	int			half;
	static int	front;

	front += divide;
	half = front - (divide / 2);
	while (to_stop(*stack_a, front) != 0)
	{
		len = ft_lstsize(*stack_a);
		last = ft_lstlast(*stack_a);
		if (len <= 3)
			three_or_less(stack_a, stack_b, len);
		else if ((*stack_a)->pos - last->pos == 1)
			check_rotate(stack_a, stack_b);
		else if ((*stack_a)->pos <= front)
			check_options(stack_a, stack_b, front, half);
		else if ((*stack_a)->pos > front)
			keep_a(stack_a, stack_b, front);
		order = perfect_order(*stack_a);
		if (order == 0 || len == 1)
			return (0);
	}
	return (order);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int		order;
	int		len;
	int		divide;
	int		full_len;

	full_len = ft_lstsize(*stack_a);
	divide = how_to_divide(full_len, full_len, 1);
	order = perfect_order(*stack_a);
	while (order != 0 || *stack_b)
	{
		if (order != 0)
		{
			order = split_stack(stack_a, stack_b, divide, full_len);
			len = ft_lstsize(*stack_a);
			divide = how_to_divide(len, full_len, 0);
		}
		while (order == 0 && *stack_b)
			put_back(stack_a, stack_b);
		order = perfect_order(*stack_a);
	}
	dub_search(-1);
}

/* 
1 = sa - swap a
2 = sb - swap b
3 = ss - swap both
4 = pa - push b to a
5 = pb - push a to b
6 = ra - rotate a first to last
7 = rb - rotate b first to last
8 = rr - rotate both
9 = rra - rev_rot a last to first
10 = rrb - rev_rot b last to first
11 = rrr - rev_rot both 
*/