/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:11:18 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/18 19:25:09 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_b(t_list **stack_a, t_list **stack_b, int last, int b_last);
void	pos_to_put(t_list **stack_a, t_list **stack_b);
void	make_a(t_list **stack_a, t_list **stack_b, int half, int len);
void	check_rotate(t_list **stack_a, t_list **stack_b);
void	put_back(t_list **stack_a, t_list **stack_b);

void	three_combo(t_list **stack_a, t_list **stack_b, int len)
{	
	if ((*stack_a)->next && ((*stack_a)->pos - (*stack_a)->next->pos == 1 \
	|| (*stack_a)->pos - (*stack_a)->next->next->pos == -1))
		ft_swap(*stack_a, *stack_b, 0);
	else if (len == 2)
	{
		ft_push(stack_a, stack_b, 4);
		ft_search(stack_a, stack_b);
	}
	else if ((*stack_a)->next && (*stack_a)->pos - (*stack_a)->next->pos == -1)
		ft_rotate(stack_a, stack_b, 8);
	else if ((*stack_a)->next && (*stack_a)->pos - (*stack_a)->next->pos != -1)
		ft_push(stack_a, stack_b, 4);
}

void	put_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	last = ft_lstlast(*stack_b);
	if ((*stack_a)->pos - (*stack_b)->pos == 1 || b_perfect(*stack_b) == 0)
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
	else
		ft_search(stack_a, stack_b);
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

void	ft_put_b(t_list **stack_a, t_list **stack_b, int last, int b_last)
{
	if ((*stack_b)->next != NULL && ((*stack_a)->pos - \
	(*stack_b)->next->pos == 1 || (*stack_a)->pos - (*stack_b)->pos == -1))
	{
		ft_push(stack_a, stack_b, 4);
		ft_swap(*stack_a, *stack_b, 1);
	}
	else if ((*stack_a)->pos - b_last == -1 || (*stack_a)->pos < b_last)
	{
		ft_push(stack_a, stack_b, 4);
		ft_rotate(stack_a, stack_b, 6);
	}
	else if (last - b_last == -1)
	{
		ft_rotate(stack_a, stack_b, 8);
		ft_push(stack_a, stack_b, 4);
		ft_rotate(stack_a, stack_b, 6);
	}
	else 
		pos_to_put(stack_a, stack_b);
}

void	make_a(t_list **stack_a, t_list **stack_b, int last, int half)
{
	if ((*stack_a)->pos - (*stack_a)->next->pos == 1)
		ft_swap(*stack_a, *stack_b, 0); // check stack b .. maybe bring back execute function
	if (*stack_b && (*stack_b)->pos - last == 1)
	{
		ft_push(stack_b, stack_a, 3);
		ft_rotate(stack_a, stack_b, 5);
	} 
	else if (*stack_b && (*stack_a)->pos - (*stack_b)->pos == 1) 
		ft_push(stack_a, stack_b, 4); 
	else if ((*stack_a)->pos > half)
	{
		while ((*stack_a)->pos - (*stack_a)->next->pos == -1)
			ft_rotate(stack_a, stack_b, 5);
		if ((*stack_a)->pos > half)
			ft_rotate(stack_a, stack_b, 5);	
	}
}
void	check_options_checker(t_list **stack_a, t_list **stack_b, int last, int half)
{
	if ((*stack_a)->pos <= half && last <= half)
		if ((*stack_a)->pos < last)
			
}

void	check_options(t_list **stack_a, t_list **stack_b, int last, int half)
{
	if ((*stack_a)->pos - (*stack_a)->next->pos == 1 || (*stack_a)->pos > (*stack_a)->next->pos)
		ft_swap(*stack_a, *stack_b, 0);	
	if (!*stack_b || (*stack_b && (*stack_a)->pos - (*stack_b)->pos == 1))
		ft_push(stack_a, stack_b, 4);
	if (last > half)
		ft_put_b(stack_a, stack_b, last->pos, b_last->pos);
	else if ((*stack_a)->pos <= half && last <= half)
	{
		if ((*stack_a)->pos < last)
			ft_put_b(stack_a, stack_b, last->pos, b_last->pos);
		else
		{
			ft_rotate(stack_a, stack_b, 8);
			ft_put_b(stack_a, stack_b, last->pos, b_last->pos);
		}
			// new func to do last	
	}
	else // does this work?? maybe fix ft_put_b to put smallest in the middle 
	{
		ft_rotate(stack_a, stack_b, 8);
		ft_put_b(stack_a, stack_b, last->pos, b_last->pos);
	}
		// do last
}

int	split_half(t_list **stack_a, t_list **stack_b, int half, int len)
{
	t_list	*last;
	t_list	*b_last;
	int		order;

	while (to_stop(*stack_a, half) != 0)
	{
		len = ft_lstsize(*stack_a);
		last = ft_lstlast(*stack_a);
		b_last = ft_lstlast(*stack_b);
		if (len <= 3)
			three_combo(stack_a, stack_b, len);
		else if ((*stack_a)->pos - last->pos == 1 || (*stack_a)->pos - last->pos == -1)
			check_rotate(stack_a, stack_b);
		// for more efficency can check if last is bigger then half then rotate and push this will only get a few extra moves
		else if ((*stack_a)->pos <= half || last->pos <= half)
			check_options(stack_a, stack_b, last->pos, half);
		else if ((*stack_a)->pos > half)
			make_a(stack_a, stack_b, last->pos, half);
		order = perfect_order(*stack_a);
		// ft_print_stack(*stack_a, *stack_b);
		if (order == 0)
			break;
	}
	return (order);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		order;
	int 	len;
	int		half;
	// can imploment dracsis flag idea to do both! save some moves for doing movement on both stacks
	len = ft_lstsize(*stack_a);
	half = len / 2;
	order = perfect_order(*stack_a);
	while (order != 0 || *stack_b)
	{
		last = ft_lstlast(*stack_a);
		if (order != 0)
		{
			order = split_half(stack_a, stack_b, half, len);
			len = ft_lstsize(*stack_a);
			half += (len / 2);
		}
		if (order == 0 && *stack_b)
		{
			put_back(stack_a, stack_b);		
			// ft_print_stack(*stack_a, *stack_b);
			len = ft_lstsize(*stack_a);
		}
		order = perfect_order(*stack_a);
	}
}