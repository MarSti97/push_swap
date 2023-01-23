#include "push_swap.h"

void    execute_a(t_list **stack_a, t_list **stack_b, int arg)
{
    t_list  *last;

    last = ft_lstlast(*stack_b);
	if (*stack_b && (*stack_b)->next)
	{
		if (arg == 1)
		{
			if ((*stack_b)->pos - (*stack_b)->next->pos == -1 || (*stack_b)->pos < (*stack_b)->next->pos)
				ft_swap(*stack_a, *stack_b, 3);
			else
				ft_swap(*stack_a, *stack_b, 1);
		}
	}
	else
		if (arg == 1)
			ft_swap(*stack_a, *stack_b, 1);
}

void    execute_b(t_list **stack_a, t_list **stack_b, int arg)
{
	// t_list  *last;

    // last = ft_lstlast(*stack_b);
    if (arg == 2)
	{
		if ((*stack_a)->pos - (*stack_a)->next->pos == -1 || (*stack_a)->pos > (*stack_a)->next->pos)
			ft_swap(*stack_a, *stack_b, 3);
		else
			ft_swap(*stack_a, *stack_b, 2);
	}
} // changed things to work with 500 turn back if fucked