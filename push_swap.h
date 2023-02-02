/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:18:25 by mstiedl           #+#    #+#             */
/*   Updated: 2023/02/02 11:10:38 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				pos;
	struct s_list	*prev;
	struct s_list	*next;

}					t_list;

// Algorithm = algo
void	sort(t_list **stack_a, t_list **stack_b);
int		split_stack(t_list **stack_a, t_list **stack_b, int divide, int len);
void	check_options(t_list **stack_a, t_list **stack_b, int front, int half);
void	last_to_b(t_list **stack_a, t_list **stack_b, int front, int half);
void	keep_a(t_list **stack_a, t_list **stack_b, int front);
// Algorithm == algo_back
void	put_back(t_list **stack_a, t_list **stack_b);
int		check_first(t_list **stack_a, t_list **stack_b, int second);
void	ft_search(t_list **stack_a, t_list **stack_b);
void	ft_search_two(t_list **stack_a, t_list **stack_b, int to_do);
// Algorithm = algo_tools
int		to_stop(t_list *stack_a, int divide);
int		how_to_divide(int len, int full, int time);
void	check_rotate(t_list **stack_a, t_list **stack_b);
void	no_b(t_list **stack_a, t_list **stack_b, int front);
void	three_or_less(t_list **stack_a, t_list **stack_b, int len);
// Algorithm = algo_back_tools
int		find_pos(t_list *stack, int find);
void	exec_rot(t_list **stack_a, t_list **stack_b);
void	exec_rev_rot(t_list **stack_a, t_list **stack_b);
int		check_fit(int smaller, int middle, int bigger);
// Moves
void	make_rotate(t_list **stack, int arg);
void	make_swap(t_list *list);
void	ft_swap(t_list *list_a, t_list *list_b, int arg);
void	ft_push(t_list **from, t_list **to, int arg);
void	ft_rotate(t_list **stack_a, t_list **stack_b, int arg);
// Writing
void	to_write(int arg);
void	dub_search(int arg);
int		dub_search_two(int keep, int arg);
// Checkers
int		check_args(char **av);
int		b_perfect(t_list *stack);
int		perfect_order(t_list *stack);
int		perfect_order_rev(t_list *stack);
// New list funcs
void	ft_listadd_back(t_list **lst, t_list *new);
void	ft_listadd_front(t_list **lst, t_list *new);
void	give_position(t_list *list);
// Push_swap
void	ft_make_list(char **av, t_list **head);
void	free_list(t_list *lst, int error);
int		ft_compare(t_list *list);
// libft
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

#endif
