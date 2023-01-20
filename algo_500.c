/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:17:14 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/20 13:54:25 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_options_500(t_list **stack_a, t_list **stack_b, int front, int back)
{
	t_list *last;

	last = ft_lstlast(*stack_a);
	if ((*stack_a)->pos - (*stack_a)->next->pos == 1 || (*stack_a)->pos > (*stack_a)->next->pos)
		execute_a(stack_a, stack_b, 1);	
	if (!*stack_b)
	{
		// if ((*stack_a)->pos < last->pos)
			ft_push(stack_a, stack_b, 5);
		// else
		// {
		// 	ft_rotate(stack_a, stack_b, 9);
		// 	ft_push(stack_a, stack_b, 5);
		// }
	}
	else if ((*stack_a)->pos - (*stack_b)->pos == 1)
			ft_push(stack_a, stack_b, 5);
	else if (last - (*stack_b)->pos == 1)
	{
			ft_rotate(stack_a, stack_b, 9);
			ft_push(stack_a, stack_b, 5);
	}
	else if (last->pos > front && last->pos < back)
		ft_put_b(stack_a, stack_b, last->pos, divide);
	else if (((*stack_a)->pos <= front || (*stack_a)->pos >= back) && (last->pos <= front && last->pos >= back))
	{
		if ((*stack_a)->pos < last->pos)
			ft_put_b(stack_a, stack_b, last->pos, divide);
		else
		{
			execute_a(stack_a, stack_b, 9);
			ft_put_b(stack_a, stack_b, last->pos, divide);
		}
	}
	else // does this work?? maybe fix ft_put_b to put smallest in the middle 
	{
		execute_a(stack_a, stack_b, 9);
		ft_put_b(stack_a, stack_b, last->pos, divide);
	}
}

void	sort_500(t_list **stack_a, t_list **stack_b, int divide, int full_len)
{
	t_list	*last;
	t_list	*b_last;
	int		order;
	int		front;
	int		back;
	
	front = divide / 2;
	back = full_len - front;
	while (to_stop(*stack_a, front, back) != 0)
	{
		len = ft_lstsize(*stack_a);
		last = ft_lstlast(*stack_a);
		b_last = ft_lstlast(*stack_b);
		if (len <= 3)
			three_or_less(stack_a, stack_b, len);
		else if ((*stack_a)->pos - last->pos == 1)
			check_rotate(stack_a, stack_b);
		else if ((*stack_a)->pos <= front && (*stack_a)->pos >= back || last->pos <= front || last->pos >= back)
			check_options(stack_a, stack_b, front, back);
		else if ((*stack_a)->pos > front && (*stack_a)->pos < back)
			make_a(stack_a, stack_b, last->pos, divide);
		order = perfect_order(*stack_a);
		// ft_print_stack(*stack_a, *stack_b);
		if (order == 0 || len == 1)
			return (0);
	}
	return (order);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		order;
	int 	len;
	int		divide;
	int		full_len;
	
	full_len = ft_lstsize(*stack_a);
	divide = how_to_divide(len, 1);
	order = perfect_order(*stack_a);
	if (full_len == 500)
		sort_500(stack_a, stack_b, divide, full_len);
	while (order != 0 || *stack_b)
	{
		len = ft_lstsize(*stack_a);
		last = ft_lstlast(*stack_a);
		if (order != 0)
		{
			order = split_stack(stack_a, stack_b, divide, len);
			len = ft_lstsize(*stack_a);
			divide = how_to_divide(len, 0);	
		}
		if (order == 0 && *stack_b)
		{
			put_back(stack_a, stack_b);		
			// ft_print_stack(*stack_a, *stack_b);
			len = ft_lstsize(*stack_a);
		}
		order = perfect_order(*stack_a);
	}
	dub_search(-1);
}