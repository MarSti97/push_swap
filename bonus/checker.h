/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:01:14 by mstiedl           #+#    #+#             */
/*   Updated: 2023/02/03 09:33:50 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H 

# include "../push_swap.h"
# include "./get_next_line/get_next_line.h"

void	get_moves(t_list **stack_a, t_list **stack_b);
void	do_move(t_list **stack_a, t_list **stack_b, char *str);
void	do_move_two(t_list **stack_a, t_list **stack_b, char *str);
void	free_list_bonus(t_list **stack_a, t_list **stack_b, int error);
// bonus moves
void	push_bonus(t_list **from, t_list **to);
void	make_rotate(t_list **stack, int arg);
void	make_swap(t_list *list);
// libft
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
// Push_swap
void	ft_make_list(char **av, t_list **head);
int		ft_compare(t_list *list);
int		check_args(char **av);
int		perfect_order(t_list *stack);

#endif