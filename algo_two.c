/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:52:04 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/23 17:33:17 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*b_last;
	t_list	*a_last;

	b_last = ft_lstlast(*stack_b);
	a_last = ft_lstlast(*stack_a);
	if ((*stack_a)->pos - (*stack_b)->pos == 1 || b_perfect(*stack_b) == 0)
	{	
		while ((*stack_b)->next && (*stack_b)->pos - (*stack_b)->next->pos == 1)
			ft_push(stack_b, stack_a, 4);
		ft_push(stack_b, stack_a, 4);
	}
	else if ((*stack_a)->pos - (*stack_b)->pos == -1)
	{
		ft_push(stack_b, stack_a, 4);
		ft_swap(*stack_a, *stack_b, 1);
	}
	else if ((*stack_a)->pos - b_last->pos == -1)
	{
		ft_rotate(stack_a, stack_b, 10);
		ft_push(stack_b, stack_a, 4);
		ft_swap(*stack_a, *stack_b, 1);
	}
	else
		put_back_2(stack_a, stack_b, b_last->pos, a_last->pos);
}

void	put_back_2(t_list **stack_a, t_list **stack_b, int b_last, int a_last)
{
	if ((*stack_a)->pos - b_last == 1)
	{
		ft_rotate(stack_a, stack_b, 10);
		ft_push(stack_b, stack_a, 4);
	}
	else if (a_last - (*stack_b)->pos == -1)
	{
		ft_push(stack_b, stack_a, 4);
		ft_rotate(stack_a, stack_b, 6);
	}
	else if (a_last - b_last == 1)
	{
		ft_rotate(stack_a, stack_b, 11);
		ft_push(stack_b, stack_a, 4);
		ft_rotate(stack_a, stack_b, 6);
		ft_rotate(stack_a, stack_b, 6);
	}
	else if (a_last - b_last == -1)
	{
		ft_rotate(stack_a, stack_b, 10);
		ft_push(stack_b, stack_a, 4);
		ft_rotate(stack_a, stack_b, 6);
	}
	else
		ft_search(stack_a, stack_b);
}

void	ft_search(t_list **stack_a, t_list **stack_b)
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
}

int	search_pos(t_list **stack_a, t_list **stack_b, int len, int last)
{
	t_list	*temp;
	int		front;
	int		back;
	int		found;

	temp = *stack_b;
	found = 0;
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

int	calculate_min(int front, int back)
{
	int	front_op;
	int	back_op;

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
