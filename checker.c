/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:18:14 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/16 21:29:06 by mstiedl          ###   ########.fr       */
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
		if (ft_atol(av[j]) < INT_MIN || ft_atol(av[j]) > INT_MAX)
		{
			write(2, "Error\n", 6);
			return (0);
		}
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

int	b_perfect(t_list *stack)
{
	int	i;

	i = 0;
	while (stack->next)
	{
		if (stack->pos - stack->next->pos != 1)
			return (++i);
		i++;
		stack = stack->next;
	}		
	return (0);
}

int perfect_order(t_list *stack)
{
	int	i;

	i = 0;
	while (stack->next)
	{
		if (stack->pos - stack->next->pos != -1)
			return (++i);
		i++;
		stack = stack->next;
	}		
	return (0);	
}

int perfect_order_rev(t_list *stack)
{
	int	i;

	i = 0;
	stack = ft_lstlast(stack);
	while (stack->prev)
	{
		if (stack->pos - stack->prev->pos != 1)
			return (++i);
		i++;
		stack = stack->prev;
	}		
	return (0);	
}