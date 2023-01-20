/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_500_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:24:39 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/20 13:33:59 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	to_stop_500(t_list *stack_a, int front, int back)
{
	while (stack_a->next)
	{
		if (stack_a->pos <= front || stack_a->pos >= back)
			return (1);
		stack_a = stack_a->next;
	}
	if (stack_a->pos <= front || stack_a->pos >= back)
		return (1);
	return (0);
}