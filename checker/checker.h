/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:01:14 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/23 21:22:29 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H 

# include "../push_swap.h"
# include "../get_next_line/get_next_line.h"

void    get_moves(t_list **stack_a, t_list **stack_b);
void    do_move(t_list **stack_a, t_list **stack_b, char *str);
void    do_move_two(t_list **stack_a, t_list **stack_b, char *str);
void	push_bonus(t_list **from, t_list **to);
// libft
strncmp();

#endif