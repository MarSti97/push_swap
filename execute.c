#include "push_swap.h"

void    check_b_both(t_list **stack_a, t_list **stack_b, int arg)
{
    t_list  *last;

    last = ft_lstlast(*stack_b);
    if (arg == 0)
    {
        if ((*stack_b)->pos - (*stack_b)->next->pos == -1 || (*stack_b)->pos < (*stack_b)->next->pos)
            ft_swap(*stack_a, *stack_b, 2);
        else
            ft_swap(*stack_a, *stack_b, 0);
    }
    else if (arg == 5)
    {
        if ((*stack_b)->pos - (*stack_b)->next->pos != 1 && (*stack_b)->pos < last->pos)
            ft_rotate(stack_a, stack_b, 7);
        else
            ft_rotate(stack_a, stack_b, 5);
    }
    else if (arg == 8)
    {
        if (last->pos - last->prev->pos != -1 && (*stack_b)->pos < last->pos)
            ft_rotate(stack_a, stack_b, 10);
        else
            ft_rotate(stack_a, stack_b, 8); 
    }
}

void    check_a_both(t_list **stack_a, t_list **stack_b, int arg)
{
    if (arg == 1)
    else if (arg == 6)
    else if (arg == 9)
}