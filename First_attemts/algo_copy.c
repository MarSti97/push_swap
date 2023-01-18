/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:54:01 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/18 17:03:25 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_search(t_list **stack_a, t_list **stack_b);
void	pos_to_put(t_list **stack_a, t_list **stack_b);
void	put_back(t_list **stack_a, t_list **stack_b);
void	check_rotate(t_list **stack_a, t_list **stack_b);
void	all_good(t_list **stack_a, t_list **stack_b);
void	third_pos(t_list **stack_a, t_list **stack_b);
void	add_back_third(t_list **stack_a, t_list **stack_b);
void	change_one(t_list **stack_a, t_list **stack_b);
void	add_one(t_list **stack_a, t_list **stack_b);
int		check_three(t_list **stack_a);
void	three_combo(t_list **stack_a, t_list **stack_b);
int		front_or_back(t_list **stack_a, t_list **stack_b, int len, int last);
int		calculate_min(int front, int back);
void	make_end(t_list **stack_a, t_list **stack_b);

void	three_combo(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->pos - (*stack_a)->next->pos == 1 \
	|| (*stack_a)->pos - (*stack_a)->next->next->pos == -1) // change this or check this
		ft_swap(*stack_a, *stack_b, 0);
	else if ((*stack_a)->pos - (*stack_a)->next->pos == -1)
		ft_rotate(stack_a, stack_b, 8);
	else if ((*stack_a)->pos - (*stack_a)->next->pos != -1)
		change_one(stack_a, stack_b);
}

void	change_one(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b || (*stack_b && (*stack_a)->pos - (*stack_b)->pos == 1))
		ft_push(stack_a, stack_b, 4);
	else if ((*stack_b)->next != NULL && (*stack_a)->pos - (*stack_b)->next->pos == 1)
	{
		ft_push(stack_a, stack_b, 4);
		ft_swap(*stack_a, *stack_b, 1);
	}
	else if ((*stack_a)->pos - (*stack_b)->pos == -1)
	{
		ft_push(stack_a, stack_b, 4);
		ft_swap(*stack_a, *stack_b, 1);
	}
	else 
		pos_to_put(stack_a, stack_b);
		// add_one(stack_a, stack_b);
	// needs testing
}

// void	add_one(t_list **stack_a, t_list **stack_b)
// {
// 	// t_list *last;

// 	// last = ft_lstlast(*stack_b);
// 	// if ((*stack_a)->pos < last->pos)
// 	// {
// 	// 	ft_push(stack_a, stack_b, 4);
// 	// 	ft_rotate(stack_a, stack_b, 6);
// 	// }
// 	// else
// 		;
// }

void	third_pos(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b || (*stack_b && (*stack_a)->pos - (*stack_b)->pos == 1))
	{
		ft_push(stack_a, stack_b, 4);
		ft_push(stack_a, stack_b, 4);
	}
	if (((*stack_b)->next != NULL && (*stack_a)->pos - (*stack_a)->next->pos == 1) \
	|| (*stack_a)->next->pos - (*stack_a)->pos == -1)
	{
		ft_push(stack_a, stack_b, 4);
		ft_swap(*stack_a, *stack_b, 1);
		ft_push(stack_a, stack_b, 4);
		ft_swap(*stack_a, *stack_b, 1);
	}
	else 
		add_back_third(stack_a, stack_b);		
	// can also add to work with last but will use lots of moves
}
void	add_back_third(t_list **stack_a, t_list **stack_b)
{
	t_list *last;

	last = ft_lstlast(*stack_a);
	if ((*stack_a)->pos > last->pos)
	{
		if ((*stack_b)->next != NULL)
			ft_rotate(stack_a, stack_b, 9);
		ft_push(stack_a, stack_b, 4);
		ft_push(stack_a, stack_b, 4);
		ft_rotate(stack_a, stack_b, 6);
		ft_rotate(stack_a, stack_b, 6);
		ft_rotate(stack_a, stack_b, 6);
	}
	else if ((*stack_a)->pos < (*stack_b)->pos)
	{
		ft_push(stack_a, stack_b, 4);
		ft_push(stack_a, stack_b, 4);
		ft_rotate(stack_a, stack_b, 6);
		ft_rotate(stack_a, stack_b, 6);
	}
	else
	{
		ft_push(stack_a, stack_b, 4);
		ft_push(stack_a, stack_b, 4);
	}
}

void	all_good(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b || (*stack_b && (*stack_a)->pos - (*stack_b)->pos == 1))
	{
		while ((*stack_a)->pos - (*stack_a)->next->pos == -1)
			ft_push(stack_a, stack_b, 4);
		ft_push(stack_a, stack_b, 4);
	}
	else if ((*stack_b)->next != NULL && (*stack_a)->pos - (*stack_b)->next->pos == 1)
	{
		if ((*stack_b)->next != NULL)
			ft_rotate(stack_a, stack_b, 9);
		while ((*stack_a)->pos - (*stack_a)->next->pos == -1)
			ft_push(stack_a, stack_b, 4);
		ft_push(stack_a, stack_b, 4);
		ft_rotate(stack_a, stack_b, 7);	
	}
	else if ((*stack_a)->pos < (*stack_b)->pos)
	{
		while ((*stack_a)->pos - (*stack_a)->next->pos == -1)
			ft_push(stack_a, stack_b, 4);
		ft_push(stack_a, stack_b, 4);
		while ((*stack_b)->pos - (*stack_b)->next->pos == 1)
			ft_rotate(stack_a, stack_b, 6);
		ft_rotate(stack_a, stack_b, 6);
	}
	else
	{	
		while ((*stack_a)->pos - (*stack_a)->next->pos == -1)
			ft_push(stack_a, stack_b, 4);
		ft_push(stack_a, stack_b, 4);
	}
// again might have to see if last->prev->pos should be added to...
// or do a function that in the end sorts b by looking at back...
}

void	check_rotate(t_list **stack_a, t_list **stack_b)
{
	int	front;
	int	back;

	front = perfect_order(*stack_a);
	back = perfect_order_rev(*stack_a);
	if (front > back)
	{
		while (back--)
			ft_rotate(stack_a, stack_b, 8);
	}
	else // front <= back
	{
		while (front--)
			ft_rotate(stack_a, stack_b, 5);	
	}
	// check if the -- is in correct position 
}

void	put_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	last = ft_lstlast(*stack_b);
	if ((*stack_a)->pos - (*stack_b)->pos == 1)
	{	
		while ((*stack_b)->next && (*stack_b)->pos - (*stack_b)->next->pos == 1)
			ft_push(stack_b, stack_a, 3);
		ft_push(stack_b, stack_a, 3);
	}
	else if ((*stack_a)->pos - last->pos == 1)
	{
		ft_rotate(stack_a, stack_b, 9);
		ft_push(stack_b, stack_a, 3);
	}
	else if (b_perfect(*stack_b) == 0)
	{
		while ((*stack_b)->next && (*stack_b)->pos - (*stack_b)->next->pos == 1)
			ft_push(stack_b, stack_a, 3);
		ft_push(stack_b, stack_a, 3); // can combine with first if
	}
	else // find next
		ft_search(stack_a, stack_b);
}

int	front_or_back(t_list **stack_a, t_list **stack_b, int len, int last)
{ // maybe this shit is too much
	t_list	*temp;
	int 	front;
	int		back;
	int		found;
	
	temp = *stack_b;
	front = 0;
	back = 0;
	found = 0; // check if 1 or 0 is better because can be segfault going past list
	while (found != len)
	{
		if (last - temp->pos == -1)
			back = found;
		if ((*stack_a)->pos - temp->pos == 1)
			front = found;
		found++;
		temp = temp->next;	
	}
	if (front > (len / 2) && front != 0)
		front = front - len;
	if (back > (len / 2) && back != 0)
		back = back - len;
	if (front == 0)
		return (back);
	if (back == 0)
		return (front);
	return (calculate_min(front, back));
}

int	calculate_min(int front, int back)
{
	int front_op;
	int back_op;

	front_op = front * -1;
	back_op = back * -1;
	if (front < 0 && back < 0 && front < back)
		return (back);
	else if (front < 0 && back < 0 && front > back)
		return (front);
	else if (front < 0 && back > 0)
	{
		if (front_op <= back)
			return (front);
		return (back);	
	}
	else if (front > 0 && back < 0)
	{
		if (front <= back_op)
			return (front);
		return (back);
	}
	else if (front > 0 && back > 0 && front < back)
		return (front);
	else
		return (back);
} // return positive to rotate, negative to reverse rotate

void	ft_search(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		len;
	int		to_do;

	len = ft_lstsize(*stack_b);
	last = ft_lstlast(*stack_a);
	to_do = front_or_back(stack_a, stack_b, len, last->pos);
	if (to_do < 0)
	{
		to_do = to_do * -1;
		while (to_do--)
			ft_rotate(stack_a, stack_b, 9);
		while ((*stack_b)->next && (*stack_b)->pos - (*stack_b)->next->pos == 1)
			ft_push(stack_b, stack_a, 3);
		ft_push(stack_b, stack_a, 3);
	}	
	else
	{
		while (to_do--)
			ft_rotate(stack_a, stack_b, 6);		
	}	
	// else find beginning!!
}
void	pos_to_put(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int 	counter;
	int		len;
	
	temp = *stack_b;
	len = ft_lstsize(*stack_b);
	counter = 0;
	while (temp->next && (*stack_a)->pos < temp->pos)
	{
		counter++;
		temp = temp->next;
	}
	if (counter <= len / 2)
	{
		while (counter--)
		{
			ft_rotate(stack_a, stack_b, 6);
			make_end(stack_a, stack_b);
		}
		ft_push(stack_a, stack_b, 4);	
	}
	else
	{
		counter = len - counter;
		while (counter--)
		{
			ft_rotate(stack_a, stack_b, 9);
			make_end(stack_a, stack_b);
		}
		ft_push(stack_a, stack_b, 4);	
	}	
}

void	make_end(t_list **stack_a, t_list **stack_b) // this is to check if anything can be added to the end of a while rotating b
{
	t_list	*last;
	t_list	*b_last;

	last = ft_lstlast(*stack_a);
	b_last = ft_lstlast(*stack_b);
	while ((*stack_b)->next && (*stack_b)->pos - last->pos == 1)
	{
		ft_push(stack_b, stack_a, 3);
		ft_rotate(stack_a, stack_b, 5);
		last = ft_lstlast(*stack_a);
	}
	while ((*stack_b)->next && b_last->pos - last->pos == 1)
	{ // can try combine these two to make sorter
		ft_rotate(stack_a, stack_b, 9);
		ft_push(stack_b, stack_a, 3);
		ft_rotate(stack_a, stack_b, 5);
		last = ft_lstlast(*stack_a);
		// b_last = ft_lstlast(*stack_b);
	}
	while (*stack_b && (*stack_b)->pos - (*stack_a)->pos == -1 \
	&& (*stack_b)->pos - last->pos == 1)
		put_back(stack_a, stack_b);	
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		order;
	int 	len;
	// can imploment dracsis flag idea to do both! save some moves for doing movement on both stacks

	order = perfect_order(*stack_a);
	while (order != 0 || *stack_b)
	{
		len = ft_lstsize(*stack_a);
		last = ft_lstlast(*stack_a);
		if (*stack_b)
			make_end(stack_a, stack_b);
		if (order == 0)
		{
			while ((*stack_b)->next && (*stack_a)->pos - (*stack_b)->pos == 1)
				ft_push(stack_b, stack_a, 3);
			put_back(stack_a, stack_b);	
		}
		else if ((*stack_a)->pos - last->pos == 1)
			check_rotate(stack_a, stack_b); // apply every multpy rotate
		else if (len == 3)
			three_combo(stack_a, stack_b);
		// chdeck if last can fo first with rrv this is tricky which was to rotate
		// check perfect order reverse and normal, compare the return value, whichever is largest rotate in that direction
		else if (len > 2 && (*stack_a)->pos - (*stack_a)->next->pos != -1)
			change_one(stack_a, stack_b);
		else if (len > 2 && (*stack_a)->pos - (*stack_a)->next->pos == -1)
			third_pos(stack_a, stack_b);
		else if (len == 2)
		{
			ft_swap(*stack_a, *stack_b, 0);
			while ((*stack_b)->next && (*stack_b)->pos - (*stack_b)->next->pos == 1)
				ft_push(stack_b, stack_a, 3);
			ft_push(stack_b, stack_a, 3);
			ft_rotate(stack_a, stack_b, 8);
		}
		// else if (len > 2) // combine ??
		// 	all_good(stack_a, stack_b);
		order = perfect_order(*stack_a);
		// ft_print_stack(*stack_a, *stack_b);
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
33 50 90 61 49 75 2 23 78 92 97 88 63 21 40 58 25 20 17 100 95 39 76 99 42 18 37 14 9 31 65 55 32 5 11 51 53 86 12 41 82 24 60 26 89 7 48 27 72 68 80 85 38 10 81 19 94 8 77 34 13 74 73 6 64 69 56 96 30 93 98 29 3 47 46 52 36 70 71 66 22 87 43 35 28 15 83 57 91 79 1 62 4 44 84 67 45 54 59 16
*/