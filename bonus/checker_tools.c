/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:25:47 by mstiedl           #+#    #+#             */
/*   Updated: 2023/02/03 09:54:34 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] && i < n - 1)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void	ft_make_list(char **av, t_list **head)
{
	int		i;
	t_list	*node;

	i = 0;
	while (av[++i])
	{
		node = (t_list *)malloc(sizeof(t_list));
		if (!node)
			return ;
		node->content = ft_atoi(av[i]);
		node->next = NULL;
		node->prev = NULL;
		ft_listadd_back(head, node);
	}
}

void	free_list_bonus(t_list **stack_a, t_list **stack_b, int error)
{
	t_list	*temp;

	if (error == 1)
		write(2, "Error\n", 6);
	while (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free (temp);
	}
	if (*stack_b)
		free_list_bonus(stack_b, stack_a, 0);
	if (error == 1)
		exit (1);
}

int	ft_compare(t_list *list)
{
	int		compare;
	t_list	*temp;

	while (list->next)
	{
		compare = list->content;
		list = list->next;
		temp = list;
		while (temp->next)
		{
			if (compare == temp->content)
				return (0);
			temp = temp->next;
		}
		if (compare == temp->content)
			return (0);
	}
	return (1);
}
