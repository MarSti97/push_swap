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