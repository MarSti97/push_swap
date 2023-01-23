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

void	ft_put_b(t_list **stack_a, t_list **stack_b, int front, int back)
{
	t_list	*b_last;
	t_list	*last;
	int a_first = (*stack_a)->pos;
	int b_first = (*stack_b)->pos;
	int a_last;
	int b_last_pos;

	b_last = ft_lstlast(*stack_b);
	last = ft_lstlast(*stack_a);
	a_last = last->pos;
	b_last_pos = b_last->pos;
	ft_printf("%i%i%i%i", a_first, b_first, a_last, b_last_pos);
	if ((*stack_a)->pos - (*stack_b)->pos == -1 || ((*stack_a)->pos <= front && (*stack_a)->pos < (*stack_b)->pos))
	{
		ft_push(stack_a, stack_b, 5);
		ft_swap(*stack_a, *stack_b, 2);
	}
	else if ((*stack_a)->pos - b_last->pos == -1 || (*stack_a)->pos >= back)
	{
		ft_push(stack_a, stack_b, 5);
		ft_rotate(stack_a, stack_b, 7);
	}
	else if ((*stack_a)->pos >= back || last->pos >= back)
	{
		ft_rotate(stack_a, stack_b, 9);
		ft_push(stack_a, stack_b, 5);
		ft_rotate(stack_a, stack_b, 7);
	}
	else // protection agains infinite loop, may not needed 
		ft_push(stack_a, stack_b, 5);
}