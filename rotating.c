/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:40:17 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/16 12:58:38 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_rotate(t_list **stack, int arg)
{
	t_list	*temp;
	
	temp = *stack;
	ft_listadd_back(stack, temp);
	*stack = (*stack)->next;
	temp->next = NULL;
	if (arg == 5)
		write(1, "ra\n", 3);
	if (arg == 6)
		write(1, "rb\n", 3);
}

void	make_rev_rot(t_list **stack, int arg)
{
	t_list *temp;
	t_list *last;

	last = ft_lstlast(*stack);
	temp = last->prev;
	last->prev = NULL;
	ft_listadd_front(stack, last);
	temp->next = NULL;
	if (arg == 8)
		write(1, "rra\n", 4);
	if (arg == 9)
		write(1, "rrb\n", 4);
}

void	ft_rotate(t_list **stack_a, t_list **stack_b, int arg)
{
	if (arg == 5)
		make_rotate(stack_a, arg);
	if (arg == 6)
		make_rotate(stack_b, arg);
	if 	(arg == 7)
	{
		make_rotate(stack_a, arg);
		make_rotate(stack_b, arg);
		write(1, "rr\n", 3);
	}
	if (arg == 8)
		make_rev_rot(stack_a, arg);
	if (arg == 9)
		make_rev_rot(stack_b, arg);
	if (arg == 10)
	{
		make_rev_rot(stack_a, arg);
		make_rev_rot(stack_b, arg);
		write(1, "rrr\n", 4);
	}	
}
