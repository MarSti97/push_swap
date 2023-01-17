/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:11:18 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/17 17:18:27 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_to_put(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int 	counter;
	int		len;
	
	temp = *stack_b;
	len = ft_lstsize(*stack_b);
	counter = 0;
	while (temp->next && (*stack_a)->pos < temp->pos)
	{
		counter++;
		temp = temp->next;
	}
	if (counter <= len / 2)
	{
		while (counter--)
		{
			ft_rotate(stack_a, stack_b, 6);
			make_end(stack_a, stack_b);
		}
		ft_push(stack_a, stack_b, 4);	
	}
	else
	{
		counter = len - counter;
		while (counter--)
		{
			ft_rotate(stack_a, stack_b, 9);
			make_end(stack_a, stack_b);
		}
		ft_push(stack_a, stack_b, 4);	
	}	
}

void	ft_put(t_list **stack_a, t_list stack_b)
{
	if (!*stack_b || (*stack_b && (*stack_a)->pos - (*stack_b)->pos == 1))
		ft_push(stack_a, stack_b, 4);
	else if ((*stack_b)->next != NULL && (*stack_a)->pos - (*stack_b)->next->pos == 1)
	{
		ft_push(stack_a, stack_b, 4);
		ft_swap(*stack_a, *stack_b, 1);
	}
	else if ((*stack_a)->pos - (*stack_b)->pos == -1)
	{
		ft_push(stack_a, stack_b, 4);
		ft_swap(*stack_a, *stack_b, 1);
	}
	else 
		pos_to_put(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		order;
	int 	len;
	int		full_len;
	// can imploment dracsis flag idea to do both! save some moves for doing movement on both stacks
	full_len = ft_lstsize(*stack_a);
	order = perfect_order(*stack_a);
	while (order != 0 || *stack_b)
	{
		len = ft_lstsize(*stack_a);
		last = ft_lstlast(*stack_a);
		if ((*stack_a)->pos - last->pos == 1)
			check_rotate(stack_a, stack_b);
		if ((*stack_a)->pos < (full_len / 2))
			ft_put(stack_a, stack_b);
		else if ((*stack_a))
		
		order = perfect_order(*stack_a);
		// ft_print_stack(*stack_a, *stack_b);
	}
}