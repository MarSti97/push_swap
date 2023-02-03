/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:13:25 by mstiedl           #+#    #+#             */
/*   Updated: 2023/02/03 09:36:47 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{	
		if (check_args(av) != 0)
		{
			ft_make_list(av, &stack_a);
			if (ft_compare(stack_a) == 0)
				free_list_bonus(&stack_a, &stack_b, 1);
		}
		else
			return (0);
		give_position(stack_a);
		get_moves(&stack_a, &stack_b);
		free_list_bonus(&stack_a, &stack_b, 0);
	}
	return (0);
}

void	get_moves(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		do_move(stack_a, stack_b, str);
		free (str);
		str = get_next_line(STDIN_FILENO);
	}
	if (perfect_order(*stack_a) == 0 && !*stack_b)
		write(1, "OK\n", 3);
	if (perfect_order(*stack_a) != 0 || *stack_b)
	{
		write(1, "KO\n", 3);
	}
}

void	do_move(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strncmp(str, "sa\n", 5) == 0)
		make_swap(*stack_a);
	else if (ft_strncmp(str, "sb\n", 5) == 0)
		make_swap(*stack_b);
	else if (ft_strncmp(str, "ss\n", 5) == 0)
	{
		make_swap(*stack_a);
		make_swap(*stack_b);
	}
	else if (ft_strncmp(str, "pa\n", 5) == 0)
		push_bonus(stack_b, stack_a);
	else if (ft_strncmp(str, "pb\n", 5) == 0)
		push_bonus(stack_a, stack_b);
	else if (ft_strncmp(str, "ra\n", 5) == 0)
		make_rotate(stack_a, 1);
	else if (ft_strncmp(str, "rb\n", 5) == 0)
		make_rotate(stack_b, 1);
	else if (ft_strncmp(str, "rr\n", 5) == 0)
	{
		make_rotate(stack_a, 1);
		make_rotate(stack_b, 1);
	}
	else
		do_move_two(stack_a, stack_b, str);
}

void	do_move_two(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strncmp(str, "rra\n", 5) == 0)
		make_rotate(stack_a, -1);
	else if (ft_strncmp(str, "rrb\n", 5) == 0)
		make_rotate(stack_b, -1);
	else if (ft_strncmp(str, "rrr\n", 5) == 0)
	{
		make_rotate(stack_a, -1);
		make_rotate(stack_b, -1);
	}
	else
		free_list_bonus(stack_a, stack_b, 1);
}
