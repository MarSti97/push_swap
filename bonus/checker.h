/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:01:14 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/24 12:56:33 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H 

# include "../push_swap.h"
# include "./get_next_line/get_next_line.h"

void	get_moves(t_list **stack_a, t_list **stack_b);
void	do_move(t_list **stack_a, t_list **stack_b, char *str);
void	do_move_two(t_list **stack_a, t_list **stack_b, char *str);
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
void	free_list(t_list *lst, int error);
int		ft_compare(t_list *list);
int		check_args(char **av);
int		perfect_order(t_list *stack);
void	ft_listadd_back(t_list **lst, t_list *new);
void	ft_listadd_front(t_list **lst, t_list *new);

#endif