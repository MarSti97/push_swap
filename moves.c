/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:48:23 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/23 16:28:22 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_swap(t_list *list)
{
	t_list	*temp;
	int		temp_cont;
	int		temp_pos;

	temp = list;
	temp_cont = list->content;
	temp_pos = list->pos;
	temp = temp->next;
	list->content = temp->content;
	list->pos = temp->pos;
	list = list->next;
	list->content = temp_cont;
	list->pos = temp_pos;
}

void	ft_swap(t_list *stack_a, t_list *stack_b, int arg)
{	
	if (arg == 1 && ft_lstsize(stack_a) > 1)
		make_swap(stack_a);
	if (arg == 2 && ft_lstsize(stack_b) > 1)
		make_swap(stack_b);
	if (arg == 3 && ft_lstsize(stack_a) > 1 && ft_lstsize(stack_b) > 1)
	{
		make_swap(stack_a);
		make_swap(stack_b);
	}
	dub_search(arg);
}

void	ft_push(t_list **from, t_list **to, int arg)
{
	t_list	*temp;

	temp = *from;
	if (temp->next != NULL)
	{
		*from = (*from)->next;
		(*from)->prev = NULL;
		ft_listadd_front(to, temp);
	}
	else
	{
		ft_listadd_front(to, temp);
		*from = NULL;
	}
	dub_search(arg);
}

void	make_rotate(t_list **stack, int arg)
{
	t_list	*temp;
	t_list	*last;

	if (arg == 1)
	{
		temp = *stack;
		ft_listadd_back(stack, temp);
		*stack = (*stack)->next;
		temp->next = NULL;
	}
	else if (arg == -1)
	{
		last = ft_lstlast(*stack);
		temp = last->prev;
		last->prev = NULL;
		ft_listadd_front(stack, last);
		temp->next = NULL;
	}
}

void	ft_rotate(t_list **stack_a, t_list **stack_b, int arg)
{
	if (arg == 6)
		make_rotate(stack_a, 1);
	if (arg == 7)
		make_rotate(stack_b, 1);
	if (arg == 8)
	{
		make_rotate(stack_a, 1);
		make_rotate(stack_b, 1);
	}
	if (arg == 9)
		make_rotate(stack_a, -1);
	if (arg == 10)
		make_rotate(stack_b, -1);
	if (arg == 11)
	{
		make_rotate(stack_a, -1);
		make_rotate(stack_b, -1);
	}
	dub_search(arg);
}
