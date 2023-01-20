/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:17:14 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/20 17:09:20 by mstiedl          ###   ########.fr       */
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
			ft_push(stack_b, stack_a, 4); // can get rid of this if need
		ft_push(stack_b, stack_a, 4);
	}
	else if ((*stack_a)->pos - b_last->pos == 1)
	{
		ft_rotate(stack_a, stack_b, 10);
		ft_push(stack_b, stack_a, 4);
	}
	else if (a_last->pos - (*stack_b)->pos == -1)
	{
		ft_push(stack_b, stack_a, 4);
		ft_rotate(stack_a, stack_b, 6);
	}
	else if (a_last->pos - b_last->pos == 1)
	{
		ft_rotate(stack_a, stakc_b, 11);
		ft_push(stack_b, stack_a, 4);
	}
	else if (a_last->pos - b_last->pos == -1)
	{
		ft_rotate(stack_a, stack_b, 10);
		ft_push(stack_b, stack_a, 4);
		ft_rotate(stack_a, stack_b, 6);
	}
	else
		ft_search(stack_a, stack_b);
}

void	make_a_500(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->pos - (*stack_a)->next->pos == 1)
		execute_a(stack_a, stack_b, 1); 
	if (*stack_b && (*stack_b)->pos - last == 1) // is this needed or makes it worst 
	{
		ft_push(stack_b, stack_a, 4);
		execute_a(stack_a, stack_b, 6);
	} 
	else if (*stack_b && (*stack_a)->pos - (*stack_b)->pos == 1) 
		ft_push(stack_a, stack_b, 5); 
	else 
		execute_a(stack_a, stack_b, 6);	
}

void	ft_put_b(t_list **stack_a, t_list **stack_b, int front, int back)
{
	t_list	*b_last;
	t_list	*last;

	b_last = ft_lstlast(*stack_b);
	last = ft_lstlast(*stack_a);
	if ((*stack_a)->pos - (*stack_b)->pos == -1 || ((*stack_a)->pos <= front && (*stack_a)->pos < (*stack_b)->pos))
	{
		ft_push(stack_a, stack_b, 5);
		ft_swap(stack_a, stack_b, 2, divide);
	}
	else if ((*stack_a)->pos - b_last->pos == -1 || (*stack_a)->pos > back)
	{
		ft_push(stack_a, stack_b, 5);
		ft_rotate(stack_a, stack_b, 7);
	}
	else if ((*stack_a)->pos >= back || last->pos >= back)
	{
		ft_rotate(stack_a, stack_b, 9);
		ft_push(stack_a, stack_b, 5);
		ft_rotate(stack_a, stack_b, 7);
	}
	else // protection agains infinite loop, may not needed 
		ft_push(stack_a, stack_b, 5);
}

void	check_options_500(t_list **stack_a, t_list **stack_b, int front, int back)
{
	t_list *last;

	last = ft_lstlast(*stack_a);
	if ((*stack_a)->pos - (*stack_a)->next->pos == 1 || (*stack_a)->pos > (*stack_a)->next->pos)
		execute_a(stack_a, stack_b, 1);	
	if (!*stack_b)
		ft_push(stack_a, stack_b, 5);
	else if ((*stack_a)->pos - (*stack_b)->pos == 1)
		ft_push(stack_a, stack_b, 5);
	else if (last - (*stack_b)->pos == 1)
	{
		ft_rotate(stack_a, stack_b, 9);
		ft_push(stack_a, stack_b, 5);
	}
	else if (last->pos > front && last->pos < back)
		ft_put_b(stack_a, stack_b, front, back);
	else // if (((*stack_a)->pos <= front || (*stack_a)->pos >= back) && (last->pos <= front && last->pos >= back))
	{
		if ((*stack_a)->pos < last->pos)
			ft_put_b(stack_a, stack_b, front, back);
		else
		{
			execute_a(stack_a, stack_b, 9);
			ft_put_b(stack_a, stack_b, front, back);
		}
	}
	// else  
	// {
	// 	execute_a(stack_a, stack_b, 9);
	// 	ft_put_b(stack_a, stack_b, last->pos, divide);
	// }
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
			check_options_500(stack_a, stack_b, front, back);
		else if ((*stack_a)->pos > front && (*stack_a)->pos < back)
			make_a_500(stack_a, stack_b);
		order = simple_order(*stack_a);
		// ft_print_stack(*stack_a, *stack_b);
		if (order == 0 || len == 1)
			return (0);
	}
	return (order);
}

void	sort_500(t_list **stack_a, t_list **stack_b)
{
	int		order;
	int 	len;
	int		divide;
	int		full_len;
	
	full_len = ft_lstsize(*stack_a);
	divide = how_to_divide(full_len, 1);
	order = perfect_order(*stack_a);
	while (order != 0 || *stack_b)
	{
		if (order != 0)
		{
			order = split_500(stack_a, stack_b, divide, full_len);
			len = ft_lstsize(*stack_a);
			divide = how_to_divide(len, 0);	
		}
		while (order == 0 && *stack_b)
		{
			put_back(stack_a, stack_b);		
			// ft_print_stack(*stack_a, *stack_b);
			order = simple_order(*stack_a);
		}
		order = perfect_order(*stack_a);
	}
	dub_search(-1);
}