/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:48:23 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/04 18:53:13 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_swap(t_list *list)
{
	t_list	*temp;
	int		temp_cont;
	
		temp = list;
		temp_cont = list->content;
		temp = temp->next;
		list->content = temp->content;
		list = list->next;
		list->content = temp_cont;
}

void	ft_swap(t_list *stack_a, t_list *stack_b, int arg)
{	
	if (arg == 0 && ft_lstsize(stack_a) > 1)
	{
		make_swap(stack_a);
		ft_printf("sa\n");	
	}
	if (arg == 1 && ft_lstsize(stack_b) > 1)
	{
		make_swap(stack_b);
		ft_printf("sb\n");
	}
	if (arg == 2 && ft_lstsize(stack_a) > 1 && ft_lstsize(stack_b) > 1)
	{
		make_swap(stack_a);
		make_swap(stack_b);
		ft_printf("ss\n");
	}
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
	if (arg == 3)
		ft_printf("pa\n");
	if (arg == 4)
		ft_printf("pb\n");
}
