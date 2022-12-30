/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:09:51 by mstiedl           #+#    #+#             */
/*   Updated: 2022/12/30 17:52:01 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_make_list(char **av, t_list **head)
{
	int i;
	t_list *node;
	
	i = 0;
	while (av[i])
	{
		node = (t_list *)malloc(sizeof(t_list));
		if (!node)
			return ;
		node->content = ft_atoi(av[i++]);
		node->next = NULL;
		ft_lstadd_front(head, node);
	}
}

/* int	ft_checker(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (!(str[i] < 48 || str[i] > 57 || str[i] != '-' && str[i] != '+'))
			i++;
		else
		{
			ft_printf("Error");
			return (0);
		}	
	}	
} */

int	ft_print_stack(t_list *list)
{
	if (!list)
		return (0);
	ft_printf("---------\nstacks:\n---------\n");
	while (list->next != NULL)
	{
		ft_printf("%i\n", list->content);
		list = list->next;
	}
	ft_printf("---------\na b\n");
	return (1);
}

void	free_list(t_list *lst, int error)
{
	t_list *temp;
	if (error == 1)
		ft_printf("Error");
	while (lst != NULL)
	{
		temp = lst;
		lst = lst->next;
		free (temp);
	}
}

int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
		//if (ft_checker(av) != 0)
			ft_make_list(av, &stack_a);
	/* while (ft_checksort(list) = 0)
	{
		ft_check_list();
		ft_apply_change();
	} */
	ft_print_stack(stack_a);
	free_list(stack_a, 0);
	return (0);
}