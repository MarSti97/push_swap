/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:18:25 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/24 11:06:18 by mstiedl          ###   ########.fr       */
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
void	check_options(t_list **stack_a, t_list **stack_b, int front, int back);
void	last_to_b(t_list **stack_a, t_list **stack_b, int front, int back);
void	keep_a(t_list **stack_a, t_list **stack_b, int front, int back);
// Algorithm = algo_two
void	put_back(t_list **stack_a, t_list **stack_b);
void	put_back_2(t_list **stack_a, t_list **stack_b, int b_last, int a_last);
void	ft_search(t_list **stack_a, t_list **stack_b);
int		search_pos(t_list **stack_a, t_list **stack_b, int len, int last);
int		calculate_min(int front, int back);
// Algorithm = algo_tools
int		to_stop(t_list *stack_a, int front, int back);
int		how_to_divide(int len, int full, int time);
void	check_rotate(t_list **stack_a, t_list **stack_b);
void	no_b(t_list **stack_a, t_list **stack_b, int front, int back);
void	three_or_less(t_list **stack_a, t_list **stack_b, int len);
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
// Delete later
int		ft_print_stack(t_list *stack_a, t_list *stack_b);
int		ft_printf(const char *input, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *str, int fd);
int		ft_putnbr_fd(int nb, int fd);

#endif