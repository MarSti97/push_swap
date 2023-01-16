/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:18:25 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/16 16:29:14 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

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
int		b_perfect(t_list *stack);
int		perfect_order(t_list *stack);
int		perfect_order_rev(t_list *stack);

// libft
int     ft_atoi(const char *nptr);
int     ft_printf(const char *input, ...);
int     ft_putchar_fd(char c, int fd);
int     ft_putstr_fd(char *str, int fd);
int     ft_putnbr_fd(int nb, int fd);
t_list	*ft_lstlast(t_list *lst);
int     ft_lstsize(t_list *lst);

// Delete later
int	ft_print_stack(t_list *stack_a, t_list *stack_b);



#endif