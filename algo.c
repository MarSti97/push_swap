/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:54:01 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/09 19:35:36 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_b(t_list **stack_a, t_list **stack_b, int arg);
void	three_combo(t_list **stack_a, t_list **stack_b, int order, int arg);

void	check_stack_a(t_list **stack_a, t_list **stack_b, int len)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if ((*stack_a)->pos - last->pos == 1)
	{
		if (*stack_b && check_b(stack_a, stack_b, 3) == 3)
			ft_rotate(stack_a, stack_b, 7);
		else
			ft_rotate(stack_a, stack_b, 5);
	}
	// else if ((*stack_a)->pos - (*stack_a)->next->pos == 1)
	// 	three_combo(stack_a, stack_b, order, 0);
	else if ((*stack_a)->pos == len)
		ft_push(stack_a, stack_b, 4);
		// ft_swap(*stack_a, *stack_b, 0);
	if ((*stack_a)->pos - last->pos == -1)
	{
		if (*stack_b && check_b(stack_a, stack_b, 2) == 2)
			ft_rotate(stack_a, stack_b, 10);
		else
			ft_rotate(stack_a, stack_b, 8);
	}
	// else
	// 	ft_push(stack_a, stack_b, 4);
}

void	three_combo(t_list **stack_a, t_list **stack_b, int order, int arg)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if ((*stack_a)->pos - (*stack_a)->next->pos == 1)
	{
		if (*stack_b && check_b(stack_a, stack_b, 1) == 1)
			ft_swap(*stack_a, *stack_b, 2);
		else
			ft_swap(*stack_a, *stack_b, 0);
	}
	if (order <= 3 && arg == 1)
		if (last->pos - (*stack_a)->pos == -1 || last->pos - (*stack_a)->pos == 1)
		{
			if (*stack_b && check_b(stack_a, stack_b, 2) == 2)
				ft_rotate(stack_a, stack_b, 10);
			else
				ft_rotate(stack_a, stack_b, 8);
		}
	if (arg == 0 && *stack_b && (*stack_a)->pos - (*stack_b)->pos == -1)
		ft_push(stack_b, stack_a, 3);
}

void	clear_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if ((*stack_a)->pos - last->pos == 1)
	{
		if (*stack_b && check_b(stack_a, stack_b, 3) == 3)
			ft_rotate(stack_a, stack_b, 7);
		else
			ft_rotate(stack_a, stack_b, 5);
	}
	else
	{			
		while (last->pos - last->prev->pos == 1)
		{
			ft_rotate(stack_a, stack_b, 8);
			ft_push(stack_a, stack_b, 4);
			last = ft_lstlast(*stack_a);
		}
		ft_rotate(stack_a, stack_b, 8);
	}
}

int	check_b(t_list **stack_a, t_list **stack_b, int arg)
{
	t_list	*temp;
	t_list	*last;

	temp = *stack_b;
	last = ft_lstlast(*stack_b);
	while (temp->next)
	{
		if (temp->pos - temp->next->pos == 1)
			temp = temp->next;
		else if (temp->pos - temp->next->pos == -1)
		{
			if (arg == 1)
				return (1);
			ft_swap(*stack_a, *stack_b, 1);
		}
		else if (temp->pos - last->pos == -1) // rev_rot
		{
			if (arg == 2)
				return (2);
			ft_rotate(stack_a, stack_b, 9);
		}
		else if (temp->pos - last->pos == 1)
		{
			if (arg == 3)
				return (3);
			ft_rotate(stack_a, stack_b, 6);
		}
		else
			temp = temp->next;
	}
	if (arg == 0)
		ft_push(stack_b, stack_a, 3);
	return (0);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	order;
	int	len;
	int check;

	order = check_order(*stack_a, 0);
	while (order != 0 || *stack_b)
	{
		len = ft_lstsize(*stack_a);
		if (order == 0)
			check_b(stack_a, stack_b, 0);
		else if (len <= 3)
			three_combo(stack_a, stack_b, order, 1);
		else if (order <= (len / 2)) // odd half will be 1 less
		{
			check = check_big_half(*stack_a, len);
			if (check == 0 || check == 1)
				check_stack_a(stack_a, stack_b, len);
			// else if (order < len / 2)
			// 	while (order--)
			// 		ft_push(stack_a, stack_b, 4);
			else 
				while (check--) 
					ft_push(stack_a, stack_b, 4);
		}
		else
			clear_back(stack_a, stack_b);
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