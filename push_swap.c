/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:09:51 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/16 22:44:17 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *lst, int error);

void	ft_make_list(char **av, t_list **head)
{
	int		i;
	t_list	*node;

	i = 0;
	while (av[++i])
	{
		node = (t_list *)malloc(sizeof(t_list));
		if (!node)
			return ;
		node->content = ft_atoi(av[i]);
		node->next = NULL;
		node->prev = NULL;
		ft_listadd_back(head, node);
	}
}

void	free_list(t_list *lst, int error)
{
	t_list	*temp;

	if (lst)
	{
		if (error == 1)
			write(2, "Error\n", 6);
		while (lst != NULL)
		{
			temp = lst;
			lst = lst->next;
			free (temp);
		}
	}
}

int	ft_compare(t_list *list)
{
	int		compare;
	t_list	*temp;

	while (list->next)
	{
		compare = list->content;
		list = list->next;
		temp = list;
		while (temp->next)
		{
			if (compare == temp->content)
				return (0);
			temp = temp->next;
		}
		if (compare == temp->content)
				return (0);
	}
	return (1);
}

int	ft_print_stack(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a)
		return (0);
	ft_printf("---------\nstack a:\n---------\n");
	while (stack_a->next)
	{
		ft_printf("%i\t%i\n", stack_a->content, stack_a->pos);
		stack_a = stack_a->next;
	}
	ft_printf("%i\t%i\n", stack_a->content, stack_a->pos);
	ft_printf("---------\n");
	ft_printf("stack\tposition\n\n");
	if (!stack_b)
		return (0);
	ft_printf("---------\nstack b:\n---------\n");
	while (stack_b->next)
	{
		ft_printf("%i\n", stack_b->content);
		stack_b = stack_b->next;
	}
	ft_printf("%i\n", stack_b->content);
	ft_printf("---------\n\n");
	return (1);
}

int	main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{	
		if (check_args(av) != 0)
		{
			ft_make_list(av, &stack_a);
			if (ft_compare(stack_a) == 0)
			{
				free_list(stack_a, 1);
				return (0);
			}
		}
		else 
			return (0);
		give_position(stack_a);
		sort(&stack_a, &stack_b);
		// ft_print_stack(stack_a, stack_b);
		// check_order(stack_a, 1);
		free_list(stack_a, 0);
		free_list(stack_b, 0);
	} 	
	return (0);
}
