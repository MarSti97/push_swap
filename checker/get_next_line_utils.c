/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:40:28 by mstiedl           #+#    #+#             */
/*   Updated: 2022/12/06 14:43:24 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *str1, char *str2, int pos)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = (ft_strlen(str1 + pos) + ft_strlen(str2));
	if (len == 0)
	{
		free (str1);
		return (NULL);
	}
	res = ft_calloc(sizeof(char), (len + 1));
	if (!res)
		return (NULL);
	if (str1)
	{
		while (str1[pos])
			res[i++] = str1[pos++];
		free (str1);
	}
	pos = -1;
	if (str2)
		while (str2[++pos])
			res[i + pos] = str2[pos];
	return (res);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (!ptr)
	{
		return (0);
	}
	while (i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}
