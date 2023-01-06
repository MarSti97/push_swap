/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:18:25 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/06 11:26:16 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include "libft.h"

void	ft_swap(t_list *list_a, t_list *list_b, int arg);
void	make_swap(t_list *list);
int		check_order(t_list *stack, int arg);
int		check_args(char **av);
void	ft_push(t_list **from, t_list **to, int arg);
void	make_rotate(t_list **stack, int arg);
void	ft_rotate(t_list **stack_a, t_list **stack_b, int arg);
void	make_rev_rot(t_list **stack, int arg);
void	ft_listadd_back(t_list **lst, t_list *new);
void	ft_listadd_front(t_list **lst, t_list *new);
void	sort(t_list **stack_a, t_list **stack_b);
void	give_position(t_list *list);

#endif