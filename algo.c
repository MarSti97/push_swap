/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:54:01 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/11 16:40:48 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_b(t_list **stack_a, t_list **stack_b, int arg);
void	three_combo(t_list **stack_a, t_list **stack_b, int order, int arg);
void	clear_back(t_list **stack_a, t_list **stack_b);
void	execute(t_list **stack_a, t_list **stack_b, int to_do);
void	sort_b(t_list **stack_a, t_list **stack_b);

void	check_stack_a(t_list **stack_a, t_list **stack_b, int order, int len)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if ((*stack_a)->pos - last->pos == 1)
		execute(stack_a, stack_b, 2);
	else if ((*stack_a)->next->pos - last->pos == 1)
	{
		execute(stack_a, stack_b, 1);
		execute(stack_a, stack_b, 2);
	}
	else if ((*stack_a)->pos == len)
		ft_push(stack_a, stack_b, 4);
	else if ((*stack_a)->pos - last->pos == -1)
		execute(stack_a, stack_b, 3);
	else if ((*stack_a)->pos - (*stack_a)->next->pos == 1)
		three_combo(stack_a, stack_b, order, 0);
	else if (*stack_b && (*stack_a)->next->pos - (*stack_b)->pos == -1)
		ft_swap(*stack_a, *stack_b, 0);
	else
		// sort_b(stack_a, stack_b);
		clear_back(stack_a, stack_b);
}

void	three_combo(t_list **stack_a, t_list **stack_b, int order, int arg)
{
	if ((*stack_a)->pos - (*stack_a)->next->pos == 1)
		execute(stack_a, stack_b, 1);
	else if (order <= 3 && arg == 1)
		execute(stack_a, stack_b, 3);
	if (arg == 0 && *stack_b && (*stack_a)->pos - (*stack_b)->pos == 1)
		ft_push(stack_b, stack_a, 3);
}

void	clear_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if ((*stack_a)->pos - last->pos == 1)
		execute(stack_a, stack_b, 3);
	else
	{			
		while (last->pos - last->prev->pos == 1)
		{
			ft_rotate(stack_a, stack_b, 8);
			ft_push(stack_a, stack_b, 4);
			last = ft_lstlast(*stack_a);
		}
		ft_rotate(stack_a, stack_b, 8);
		ft_push(stack_a, stack_b, 4);
	}
}

void	sort_b(t_list **stack_a, t_list **stack_b)
{
	int		check;
	t_list	*last;

	last = ft_lstlast(*stack_b);
	check = check_rev_order(*stack_b);
	if (*stack_b && (*stack_b)->next != NULL)
	{
		while (check != 0)
		{
			if ((*stack_b)->pos - (*stack_b)->next->pos == -1)
				ft_swap(*stack_a, *stack_b, 2);
			else if ((*stack_b)->pos - last->pos == -1) // rev_rot
				ft_rotate(stack_a, stack_b, 9);
			else if ((*stack_b)->pos - last->pos == 1)
				ft_rotate(stack_a, stack_b, 6);
			else
				break ;
			check = check_rev_order(*stack_b);
		}
	}
	while ((*stack_b)->next != NULL)
		if ((*stack_b)->pos - (*stack_b)->next->pos == 1)
			ft_push(stack_b, stack_a, 3);
	ft_push(stack_b, stack_a, 3);
}

int	check_b(t_list **stack_a, t_list **stack_b, int arg)
{
	t_list	*last;

	if (!*stack_b || (*stack_b)->next == NULL)
		return (0);
	last = ft_lstlast(*stack_b);
	if ((*stack_b)->pos - (*stack_b)->next->pos == -1)
	{
		if (arg == 1)
			return (1);
		ft_swap(*stack_a, *stack_b, 1);
	}
	else if ((*stack_b)->pos - last->pos == 1)
	{	
		if (arg == 2)
			return (2);
		ft_rotate(stack_a, stack_b, 6);
	}
	else if ((*stack_b)->pos - last->pos == -1) // rev_rot
	{
		if (arg == 3)
			return (3);
		ft_rotate(stack_a, stack_b, 9);
	}
	return (0);
}

void	execute(t_list **stack_a, t_list **stack_b, int to_do)
{
	if (to_do == 1)
	{
		if (check_b(stack_a, stack_b, 1) == 1)
			ft_swap(*stack_a, *stack_b, 2);
		else if (check_b(stack_a, stack_b, 1) == 0)
			ft_swap(*stack_a, *stack_b, 0);
	}
	if (to_do == 2)
	{
		if (check_b(stack_a, stack_b, 2) == 2)
			ft_rotate(stack_a, stack_b, 7);
		else if (check_b(stack_a, stack_b, 1) == 0)
			ft_rotate(stack_a, stack_b, 5);
	}
	if (to_do == 3)
	{
		if (check_b(stack_a, stack_b, 3) == 3)
			ft_rotate(stack_a, stack_b, 10);
		else if (check_b(stack_a, stack_b, 1) == 0)
			ft_rotate(stack_a, stack_b, 8);
	}
}

void	sort_part_two(t_list **stack_a, t_list **stack_b, int len, int order)
{
	int	check;
	
	check = check_big_half(*stack_a, len);
	if (check == 0 || check == 1)
		check_stack_a(stack_a, stack_b, order, len);
	else if (check == -1)
	{
		if ((*stack_b)->pos - (*stack_b)->pos == 1)
			ft_push(stack_b, stack_a, 3);
		else
			ft_push(stack_a, stack_b, 4);
	}
	else if (len <= 5)
		ft_push(stack_a, stack_b, 4);
	else if (order == (len / 2))
		while (order--)
			execute(stack_a, stack_b, 2);
	else
		while (--check)
			ft_push(stack_a, stack_b, 4);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	order;
	int	len;

	order = check_order(*stack_a, 0);
	while (order != 0 || *stack_b)
	{
		len = ft_lstsize(*stack_a);
		if (order == 0)
			sort_b(stack_a, stack_b);
		else if (len <= 3)
			three_combo(stack_a, stack_b, order, 1);
		else if (order <= (len / 2) || len <= 5) // odd half will be 1 less
			sort_part_two(stack_a, stack_b, len, order);
		else
			while (--order)
				ft_push(stack_a, stack_b, 4);
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

todo:
1 == swap
2 == rotate 
3 == rev_rot
*/