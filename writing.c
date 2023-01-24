/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:40:17 by mstiedl           #+#    #+#             */
/*   Updated: 2023/01/23 16:44:39 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dub_search(int arg)
{
	static int	keep;

	if (arg == -1)
		to_write(keep);
	else if (!keep)
		keep = arg;
	else if (keep == arg)
		to_write(keep);
	else if ((keep == 1 && arg == 2) || (keep == 2 && arg == 1))
	{
		to_write(3);
		keep = 0;
	}
	else if ((keep == 6 && arg == 7) || (keep == 7 && arg == 6))
	{
		to_write(8);
		keep = 0;
	}
	else
		keep = dub_search_two(keep, arg);
}

int	dub_search_two(int keep, int arg)
{
	if ((keep == 9 && arg == 10) || (keep == 10 && arg == 9))
	{
		to_write(11);
		keep = 0;
	}
	else
	{
		to_write(keep);
		keep = arg;
	}
	return (keep);
}

void	to_write(int arg)
{
	if (arg == 1)
		write(1, "sa\n", 3);
	else if (arg == 2)
		write(1, "sb\n", 3);
	else if (arg == 3)
		write(1, "ss\n", 3);
	else if (arg == 4)
		write(1, "pa\n", 3);
	else if (arg == 5)
		write(1, "pb\n", 3);
	else if (arg == 6)
		write(1, "ra\n", 3);
	else if (arg == 7)
		write(1, "rb\n", 3);
	else if (arg == 8)
		write(1, "rr\n", 3);
	else if (arg == 9)
		write(1, "rra\n", 4);
	else if (arg == 10)
		write(1, "rrb\n", 4);
	else if (arg == 11)
		write(1, "rrr\n", 4);
}
