/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:11:18 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/17 22:47:09 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_b(t_list **stack_a, t_list stack_b);
void	pos_to_put(t_list **stack_a, t_list **stack_b);
void	make_a(t_list **stack_a, t_list **stack_b);
void	check_rotate(t_list **stack_a, t_list **stack_b);
void	put_back(t_list **stack_a, t_list **stack_b);

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

void	ft_put_b(t_list **stack_a, t_list stack_b)
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
}

void	make_a(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->pos - (*stack_a)->next->pos == 1 || (*stack_a)->pos > (*stack_a)->next->pos)
		ft_swap(stack_a, stack_b, 0); // check stack b .. maybe bring back execute function
	while ((*stack_a)->next && (*stack_a)->pos - (*stack_a)->next->pos == -1)
		ft_rotate(stack_a, stack_b, 5);
	ft_rotate(stack_a, stack_b, 5);	
}

int	sort_two(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*b_last;
	int		order;
	int		b;
	
	b = 0;
	order = perfect_order(*stack_a);
	last = ft_lstlast(*stack_a);
	b_last = ft_lstlast(*stack_b);
	while (order != 0)
	{
		if ((*stack_a)->pos - last->pos == 1 || (*stack_a)->pos - last->pos == -1)
			check_rotate(stack_a, stack_b);
		if ((*stack_a)->pos - (*stack_a)->next->pos == 1 || (*stack_a)->pos > (*stack_a)->next->pos)
			ft_swap(stack_a, stack_b, 0);
		else if ((*stack_a)->pos - (*stack_b)->pos == 1 || (*stack_b)->pos - last->pos == 1)
			ft_push(stack_b, stack_a, 3);
		else if ((*stack_a)->pos - b_last->pos == 1)
		{
			ft_rotate(stack_a, stack_b, 9);
			ft_push(stack_a, stack_b, 4);
		}
		else if (last->pos - b_last->pos == -1)
		{
			ft_rotate(stack_a, stack_b, 9);
			ft_push(stack_a, stack_b, 4);
		}
		else 
			ft_push(stack_a, stack_b, 4);
	}
	return (order);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		order;
	int 	len;
	int		full_len;
	// can imploment dracsis flag idea to do both! save some moves for doing movement on both stacks
	full_len = ft_lstsize(*stack_a);
	order = perfect_order(*stack_a);
	while (order != 0 || *stack_b)
	{
		len = ft_lstsize(*stack_a);
		last = ft_lstlast(*stack_a);
		two_halfs(stack_a, stack_b);
		if (len == 3)
		
		if (len == full_len / 2)
			order = sort_two(stack_a, stack_b);
		if (order == 0)
			put_back(stack_a, stack_b);
		else if ((*stack_a)->pos - last->pos == 1)
			check_rotate(stack_a, stack_b);
		else if ((*stack_a)->pos < (full_len / 2))
			ft_put_b(stack_a, stack_b);
		else if ((*stack_a)->pos >= (full_len / 2))
			make_a(stack_a, stack_b);		
		order = perfect_order(*stack_a);
		// ft_print_stack(*stack_a, *stack_b);
	}
}