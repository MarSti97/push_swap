/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:18:14 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/11 16:53:55 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_list *stack, int arg)
{
	int	i;

	i = 0;
	while (stack->next)
	{
		if (stack->content > stack->next->content)
		{
			if (arg == 1)
				ft_printf("Wrong Order!\n");
			return (i + 1);
		}
		i++;
		stack = stack->next;
	}		
	if (arg == 1)
		ft_printf("OK\n");
	return (0);
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

int check_big_half(t_list *stack, int len)
{
	// this function is the problem
	int		i;
	int		half;
	
	half = (len / 2);
	i = 0;
	while (half--)
	{
		if (stack->pos > (len / 2))
			i++;
		if (stack->pos == len)
			return (i++);
		if (stack->pos < (len / 2))
			break;
		stack = stack->next;
	}
	return (i);
}

int	check_rev_order(t_list *stack)
{
	int	i;

	i = 0;
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			return (i + 1);
		i++;
		stack = stack->next;
	}		
	return (0);
}
