/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:11:18 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/19 18:51:45 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_b(t_list **stack_a, t_list **stack_b, int last, int divide);
void	pos_to_put(t_list **stack_a, t_list **stack_b);
void	make_a(t_list **stack_a, t_list **stack_b, int divide, int len);
void	check_rotate(t_list **stack_a, t_list **stack_b);
void	put_back(t_list **stack_a, t_list **stack_b);
int		how_to_divide(int len, int time);


void	three_or_less(t_list **stack_a, t_list **stack_b, int len)
{	
	if ((*stack_a)->next && (*stack_a)->pos - (*stack_a)->next->pos == 1)
		ft_swap(*stack_a, *stack_b, 1);
	else if (len == 2)
	{
		ft_push(stack_a, stack_b, 5);
		ft_search(stack_a, stack_b);
	}
	else if ((*stack_a)->pos - (*stack_a)->next->next->pos == -1)
		ft_swap(*stack_a, *stack_b, 1);
	else if ((*stack_a)->next && (*stack_a)->pos - (*stack_a)->next->pos == -1)
		ft_rotate(stack_a, stack_b, 9);
	else if ((*stack_a)->next && (*stack_a)->pos - (*stack_a)->next->next->pos == 1)
		ft_rotate(stack_a, stack_b, 6);
	else if ((*stack_a)->next && (*stack_a)->pos - (*stack_a)->next->pos != -1)
		ft_push(stack_a, stack_b, 5);
}

void	put_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	last = ft_lstlast(*stack_b);
	if ((*stack_a)->pos - (*stack_b)->pos == 1 || b_perfect(*stack_b) == 0)
	{	
		while ((*stack_b)->next && (*stack_b)->pos - (*stack_b)->next->pos == 1)
			ft_push(stack_b, stack_a, 4);
		ft_push(stack_b, stack_a, 4);
	}
	else if ((*stack_a)->pos - last->pos == 1)
	{
		ft_rotate(stack_a, stack_b, 10);
		ft_push(stack_b, stack_a, 4);
	}
	else
		ft_search(stack_a, stack_b);
}

// void	pos_to_put(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*temp;
// 	int 	counter;
// 	int		len;
	
// 	temp = *stack_b;
// 	len = ft_lstsize(*stack_b);
// 	counter = 0;
// 	while (temp->next && (*stack_a)->pos < temp->pos)
// 	{
// 		counter++;
// 		temp = temp->next;
// 	}
// 	if (counter <= len / 2)
// 	{
// 		while (counter--)
// 		{
// 			ft_rotate(stack_a, stack_b, 6);
// 			make_end(stack_a, stack_b);
// 		}
// 		ft_push(stack_a, stack_b, 4);	
// 	}
// 	else
// 	{
// 		counter = len - counter;
// 		while (counter--)
// 		{
// 			ft_rotate(stack_a, stack_b, 9);
// 			make_end(stack_a, stack_b);
// 		}
// 		ft_push(stack_a, stack_b, 4);	
// 	}	
// }

void	ft_put_b(t_list **stack_a, t_list **stack_b, int last, int divide)
{
	t_list *b_last;

	b_last = ft_lstlast(*stack_b);
	if ((*stack_b)->next != NULL && ((*stack_a)->pos - \
	(*stack_b)->next->pos == 1 || (*stack_a)->pos - (*stack_b)->pos == -1))
	{
		ft_push(stack_a, stack_b, 5);
		execute_b(stack_a, stack_b, 2, divide);
	}
	else if ((*stack_a)->pos - b_last->pos == -1 || (*stack_a)->pos < (*stack_b)->pos)
	{
		ft_push(stack_a, stack_b, 5);
		execute_b(stack_a, stack_b, 7, divide);
	}
	else if (last - b_last->pos == -1)
	{
		ft_rotate(stack_a, stack_b, 9);
		ft_push(stack_a, stack_b, 5);
		ft_rotate(stack_a, stack_b, 7);
	}
	else 
		ft_push(stack_a, stack_b, 5);
		// pos_to_put(stack_a, stack_b);
}

void	make_a(t_list **stack_a, t_list **stack_b, int last, int divide)
{
	if ((*stack_a)->pos - (*stack_a)->next->pos == 1)
		execute_a(stack_a, stack_b, 1); // check stack b .. maybe bring back execute function
	if (*stack_b && (*stack_b)->pos - last == 1)
	{
		ft_push(stack_b, stack_a, 4);
		execute_a(stack_a, stack_b, 6);
	} 
	else if (*stack_b && (*stack_a)->pos - (*stack_b)->pos == 1) 
		ft_push(stack_a, stack_b, 5); 
	else if ((*stack_a)->pos > divide)
	{
		while ((*stack_a)->pos - (*stack_a)->next->pos == -1)
			execute_a(stack_a, stack_b, 6);
		if ((*stack_a)->pos > divide)
			execute_a(stack_a, stack_b, 6);	
	}
}

void	check_options(t_list **stack_a, t_list **stack_b, int last, int divide)
{
	if ((*stack_a)->pos - (*stack_a)->next->pos == 1 || (*stack_a)->pos > (*stack_a)->next->pos)
		execute_a(stack_a, stack_b, 1);	
	if (!*stack_b)
	{
		if ((*stack_a)->pos < last)
			ft_push(stack_a, stack_b, 5);
		else
		{
			ft_rotate(stack_a, stack_b, 9);
			ft_push(stack_a, stack_b, 5);
		}
	}
	else if ((*stack_a)->pos - (*stack_b)->pos == 1)
			ft_push(stack_a, stack_b, 5);
	else if (last - (*stack_b)->pos == 1)
	{
			ft_rotate(stack_a, stack_b, 9);
			ft_push(stack_a, stack_b, 5);
	}
	else if (last > divide)
		ft_put_b(stack_a, stack_b, last, divide);
	else if ((*stack_a)->pos <= divide && last <= divide)
	{
		if ((*stack_a)->pos < last)
			ft_put_b(stack_a, stack_b, last, divide);
		else
		{
			execute_a(stack_a, stack_b, 9);
			ft_put_b(stack_a, stack_b, last, divide);
		}
	}
	else // does this work?? maybe fix ft_put_b to put smallest in the middle 
	{
		execute_a(stack_a, stack_b, 9);
		ft_put_b(stack_a, stack_b, last, divide);
	}
}

int	split_stack(t_list **stack_a, t_list **stack_b, int divide, int len)
{
	t_list	*last;
	t_list	*b_last;
	int		order;

	while (to_stop(*stack_a, divide) != 0)
	{
		len = ft_lstsize(*stack_a);
		last = ft_lstlast(*stack_a);
		b_last = ft_lstlast(*stack_b);
		if (len <= 3)
			three_or_less(stack_a, stack_b, len);
		else if ((*stack_a)->pos - last->pos == 1)
			check_rotate(stack_a, stack_b);
		else if ((*stack_a)->pos <= divide || last->pos <= divide)
			check_options(stack_a, stack_b, last->pos, divide);
		else if ((*stack_a)->pos > divide)
			make_a(stack_a, stack_b, last->pos, divide);
		order = perfect_order(*stack_a);
		// ft_print_stack(*stack_a, *stack_b);
		if (order == 0 || len == 1)
			return (0);
	}
	return (order);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		order;
	int 	len;
	int		divide;
	
	len = ft_lstsize(*stack_a);
	divide = how_to_divide(len, 1);
	order = perfect_order(*stack_a);
	while (order != 0 || *stack_b)
	{
		last = ft_lstlast(*stack_a);
		if (order != 0)
		{
			order = split_stack(stack_a, stack_b, divide, len);
			len = ft_lstsize(*stack_a);
			divide = how_to_divide(len, 0);	
		}
		if (order == 0 && *stack_b)
		{
			put_back(stack_a, stack_b);		
			// ft_print_stack(*stack_a, *stack_b);
			len = ft_lstsize(*stack_a);
		}
		order = perfect_order(*stack_a);
	}
	dub_search(-1);
}

int	how_to_divide(int len, int time)
{
	static int	divide;
	
	if (time == 1)
	{
		if (len >= 100)
			divide = len / 5;
		else
			divide = len / 2;	
	}
	else
	{
		if (len > 100)
			divide += divide;
		else
			divide += (len / 2);
	}
	return (divide);
}

/* 
1 = sa - swap a
2 = sb - swap b
3 = ss - swap both
4 = pa - push b to a
5 = pb - push a to b
6 = ra - rotate a first to last
7 = rb - rotate b first to last
8 = rr - rotate both
9 = rra - rev_rot a last to first
10 = rrb - rev_rot b last to first
11 = rrr - rev_rot both

todo:
1 == swap
2 == rotate 
3 == rev_rot
*/
