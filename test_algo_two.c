/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_algo_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:24:39 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/22 22:13:10 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_pos(t_list **stack_a, t_list **stack_b, int len, int last)
{ // maybe this shit is too much
	t_list	*temp;
	int 	front;
	int		back;
	int		found;
	
	temp = *stack_b;
	front = 0;
	back = 0;
	found = 0; // check if 1 or 0 is better because can be segfault going past list
	while (found != len)
	{
		if (last - temp->pos == -1)
			back = found;
		if ((*stack_a)->pos - temp->pos == 1)
			front = found;
		found++;
		temp = temp->next;	
	}
	if (front > (len / 2) && front != 0)
		front = front - len;
	if (back > (len / 2) && back != 0)
		back = back - len;
	if (front == 0)
		return (back);
	if (back == 0)
		return (front);
	return (calculate_min(front, back));
}

void	ft_search_500(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		len;
	int		to_do;

	len = ft_lstsize(*stack_b);
	last = ft_lstlast(*stack_a);
	to_do = search_pos(stack_a, stack_b, len, last->pos);
	if (to_do < 0)
	{
		to_do = to_do * -1;
		while (to_do--)
			ft_rotate(stack_a, stack_b, 10);
		while ((*stack_b)->next && (*stack_b)->pos - (*stack_b)->next->pos == 1)
			ft_push(stack_b, stack_a, 4);
		ft_push(stack_b, stack_a, 4);
	}	
	else
	{
		while (to_do--)
			ft_rotate(stack_a, stack_b, 7);
		ft_push(stack_b, stack_a, 4);
	}	
	if ((*stack_a)->pos - last->pos == 1)
		check_rotate(stack_a, stack_b);
	// else find beginning!!
}

int	to_stop_500(t_list *stack_a, int front, int back)
{
	while (stack_a->next)
	{
		if (stack_a->pos <= front || stack_a->pos >= back)
			return (1);
		stack_a = stack_a->next;
	}
	if (stack_a->pos <= front || stack_a->pos >= back)
		return (1);
	return (0);
}

int	how_to_divide(int len, int full, int time)
{
	static int	divide;
	static int	res;

	res++;
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
			divide += (full / 5);
		else
			divide += (len / 2);
	}
	return (divide);
}

int	calculate_min(int front, int back)
{
	int front_op;
	int back_op;

	front_op = front * -1;
	back_op = back * -1;
	if (front < 0 && back < 0 && front < back)
		return (back);
	else if (front < 0 && back < 0 && front > back)
		return (front);
	else if (front < 0 && back > 0)
	{
		if (front_op <= back)
			return (front);
		return (back);	
	}
	else if (front > 0 && back < 0)
	{
		if (front <= back_op)
			return (front);
		return (back);
	}
	else if (front > 0 && back > 0 && front < back)
		return (front);
	else
		return (back);
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
	else // front <= back
	{
		while (front--)
			ft_rotate(stack_a, stack_b, 6);	
	}
	// maybe can take some moves off if use execute
}