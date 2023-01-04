/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:18:14 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/04 13:31:42 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(t_list *stack)
{
	int toComp;
	t_list *temp;
	
	while (stack->next != NULL)
	{
		toComp = stack->content;
		stack = stack->next;
		temp = stack;
		while (temp->next != NULL)
		{
			if (toComp == temp->content)
				return (0);
			if (toComp > temp->content)
			{
				ft_printf("Wrong Order!\n");
				return (0);
			}	
			temp = temp->next;
		}		
	}
	ft_printf("OK\n");
	return (1);
}

int	check_args(char **av)
{
	int	i;
	int	j;

	j = 0;
	while (av[++j])
	{
		i = 0;
		while (av[j][i])
		{
			if ((av[j][i] >= 48 && av[j][i] <= 57) \
			|| av[j][i] == '-' || av[j][i] == '+')
				i++;
			else
			{
				write(2, "Error\n", 6);
				return (0);
			}	
		}	
	}
	return (i);
}