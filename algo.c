/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:54:01 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/05 18:59:37 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_position(t_list *list)
{
	t_list	*next_node;
	t_list	*prev_node;
	int		size;

	size = ft_lstsize(list);
	while (size--)
	{		
		next_node = list;
		prev_node = list;
		list->pos = 1;
		while (next_node->next)
		{
			next_node = next_node->next;
			if (next_node->content < list->content)
				list->pos += 1;
		}
		while (prev_node->prev)
		{
			prev_node = prev_node->prev;
			if (prev_node->content < list->content)
				list->pos += 1;
		}
		list = list->next;
	}
}

void	sort(t_list *stack_a, t_list *stack_b)
{
	int order;
	
	order = check_order(stack, 0);
	give_position(stack_a);
	while (order != 0 && stack_b)
	{
		if (order < 4)
			check_stack_a(stack_a);
		check_stack_b(stack_b);
		if (order == 0 && stack_b)
			ft_push(stack_b, stack_a, 4);
		order = check_order(stack, 0);	
	}
}

int check_stack_a(t_list *stack)
{
	t_list	*temp;
	
	temp = ft_lstlast(stack);
	stack = stack->next
	if ((stack->pos - stack->prev->pos) == -1)
		ft_swap(stack_a, stack_a, 0);
	if ((temp->pos - temp->prev->pos) > 0)
		//??if (temp->prev->pos - temp->prev->prev->pos)
		// check_stack_b()
		ft_rotate(stack_a, stack_b, 5);
	if (stack->pos - stack->prev->pos == 1)
		if (stack->pos - stack->next->pos == -1)
			ft_push(stack_a, stack_b, 3);
			
}