/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:59:40 by mstiedl           #+#    #+#             */
/*   Updated: 2023/02/02 11:05:39 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	push_bonus(t_list **from, t_list **to)
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
}
