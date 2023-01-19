/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:48:23 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/19 18:48:02 by mstiedl          ###   ########.fr       */
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
	{
		make_swap(stack_a);
		// write(1, "sa\n", 3);	
	}
	if (arg == 2 && ft_lstsize(stack_b) > 1)
	{
		make_swap(stack_b);
		// write(1, "sb\n", 3);
	}
	if (arg == 3 && ft_lstsize(stack_a) > 1 && ft_lstsize(stack_b) > 1)
	{
		make_swap(stack_a);
		make_swap(stack_b);
		// write(1, "ss\n", 3);
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
	// if (arg == 3)
	// 	write(1, "pa\n", 3);
	// if (arg == 4)
	// 	write(1, "pb\n", 3);
	dub_search(arg);
}
