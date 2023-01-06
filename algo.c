/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:54:01 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/06 20:05:08 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_stack_a(t_list **stack_a, t_list **stack_b, int len, int order)
{
	t_list	*last;
	
	last = ft_lstlast(*stack_a);
	if (((*stack_a)->next->pos - (*stack_a)->pos) == -1)
		ft_swap(*stack_a, *stack_b, 0);
	if (len <= 3 && order < 3)
		if (last->pos - (*stack_a)->pos == -1 || last->pos - (*stack_a)->pos == 1 || order == 0)
			ft_rotate(stack_a, stack_b, 8);
	if (len > 3 && order < 3)
	{
		if ((*stack_a)->pos - last->pos == 1)
			ft_rotate(stack_a, stack_b, 5);
		else 
		// if ((*stack_a)->pos - (*stack_a)->next->pos != -1 || last->pos - (*stack_a)->pos != 1)
			ft_push(stack_a, stack_b, 4);
	}
	/* 	if (stack_a->next->pos - stack_a->pos > 0)
			if (stack_a->next->pos - stack_a->next->next->pos == -1)
			{
				ft_push(stack_a, stack_b, 4);
				check_stack_a(stack_a, stack_b, len);
				ft_push(stack_b, stack_a, 3);
			} */			
}

void	clear_back(t_list **stack_a, t_list **stack_b, int order)
{
	t_list	*last;
	
	last = ft_lstlast(*stack_a);
	if (order == 0)
	{
		ft_rotate(stack_a, stack_b, 8);
		return ;
	}	
	while (last->pos - last->prev->pos == -1)
	{
		ft_rotate(stack_a, stack_b, 8);
		last = ft_lstlast(*stack_a);
	}
	ft_rotate(stack_a, stack_b, 8);
}

void	check_b(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b)
	{
		if ((*stack_a)->pos - (*stack_b)->pos == 1 || (*stack_a)->pos - (*stack_b)->pos == -1)
			ft_push(stack_b, stack_a, 3);
		// if (can swap)
		// if (can rotate)
		// if (can rev_rot)	
	/* 	else if(last->pos - (*stack_a)->pos == 1)
			ft_rotate(stack_a, stack_b, 8);
		else
		{
			ft_rotate(stack_a, stack_b, 8);
			ft_push(stack_a, stack_b, 4);
		} */
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int order;
	int	len;
	
	order = check_order(*stack_a, 0);
	while (order != 0 || *stack_b) // dont loop with order 0!
	{
		len = ft_lstsize(*stack_a);
		if (order <= 3 && order != 0)
			check_stack_a(stack_a, stack_b, len, order);
		else if (order < (len / 2) && order != 0) // odd half will be 1 less
		{
			while(--order)
				ft_push(stack_a, stack_b, 4);
			sort(stack_a, stack_b);
			ft_push(stack_b, stack_a, 3);
		}
		else
		{
			clear_back(stack_a, stack_b, order);
			check_b(stack_a, stack_b);
		}
		// if (order == 0 && stack_b)
		// 	ft_push(stack_b, stack_a, 3);
		order = check_order(*stack_a, 0);	
	} 
}

/* 
0 = sa - swap a
1 = sb - swap b
2 = ss - swap both
3 = pa - push b to a
4 = pb - push a to b
5 = ra - rotate a first to last
6 = rb - rotate b first to last
7 = rr - rotate both
8 = rra - rev_rot a last to first
9 = rrb - rev_rot b last to first
10 = rrr - rev_rot both
*/