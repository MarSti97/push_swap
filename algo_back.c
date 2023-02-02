/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:42:43 by mstiedl           #+#    #+#             */
/*   Updated: 2023/02/02 10:55:04 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if ((*stack_b)->next)
	{
		if (check_first(stack_a, stack_b, (*stack_b)->next->pos) == 0)
			ft_search(stack_a, stack_b);
	}
	else
		if (check_first(stack_a, stack_b, -1) == 0)
			ft_search(stack_a, stack_b);
	if ((*stack_a)->pos - last->pos == 1)
		check_rotate(stack_a, stack_b);
}

int	check_first(t_list **stack_a, t_list **stack_b, int second)
{
	t_list	*last;

	last = ft_lstlast(*stack_b);
	if ((*stack_a)->pos - (*stack_b)->pos == 1)
	{
		ft_push(stack_b, stack_a, 4);
		return (1);
	}
	else if ((*stack_a)->pos - second == 1)
	{
		ft_rotate(stack_a, stack_b, 7);
		ft_push(stack_b, stack_a, 4);
		return (1);
	}
	else if ((*stack_a)->pos - last->pos == 1)
	{
		ft_rotate(stack_a, stack_b, 10);
		ft_push(stack_b, stack_a, 4);
		return (1);
	}
	else
		return (0);
}

void	ft_search(t_list **stack_a, t_list **stack_b)
{
	int		to_do;
	t_list	*last;

	last = ft_lstlast(*stack_b);
	if ((*stack_b)->pos >= last->pos)
		to_do = find_pos(*stack_a, (*stack_b)->pos);
	else
	{
		to_do = find_pos(*stack_a, last->pos);
		ft_rotate(stack_a, stack_b, 10);
	}
	if (to_do == 0)
	{
		while ((*stack_b)->next && (*stack_b)->pos - (*stack_b)->next->pos == 1)
			ft_push(stack_b, stack_a, 4);
		ft_push(stack_b, stack_a, 4);
	}
	else
		ft_search_two(stack_a, stack_b, to_do);
}

void	ft_search_two(t_list **stack_a, t_list **stack_b, int to_do)
{
	int		len;

	len = ft_lstsize(*stack_a);
	if (to_do <= (len / 2))
	{
		while (to_do--)
			exec_rot(stack_a, stack_b);
		while ((*stack_b)->next && (*stack_b)->pos - (*stack_b)->next->pos == 1)
			ft_push(stack_b, stack_a, 4);
		ft_push(stack_b, stack_a, 4);
	}	
	else
	{
		to_do = len - to_do;
		while (to_do--)
			exec_rev_rot(stack_a, stack_b);
		ft_push(stack_b, stack_a, 4);
	}
}	
