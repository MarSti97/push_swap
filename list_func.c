/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:10:48 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/12 13:47:40 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_listadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

void	ft_listadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;
	if (!*lst)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
	temp = *lst;
	new->next = *lst;
	*lst = new;
	temp->prev = new;
}

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

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
