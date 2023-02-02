/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:04 by mstiedl           #+#    #+#             */
/*   Updated: 2023/02/02 11:12:00 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*text;
	char		*res;

	if (BUFFER_SIZE <= 0 || fd > 1024 || fd < 0)
		return (NULL);
	if (checker(text) == 0)
		text = get_it_all(fd, text);
	if (!text || !*text)
		return (NULL);
	res = not_keep(text);
	if (checker(text) != 0)
		text = ft_strjoin(text, NULL, checker(res));
	else
	{
		free (text);
		text = NULL;
	}
	return (res);
}

char	*not_keep(char *text)
{
	int		len;
	int		i;
	char	*res;

	if (checker(text) != 0)
		len = checker(text);
	else
		len = ft_strlen(text);
	res = ft_calloc((len + 1), sizeof(char));
	if (!res)
		return (0);
	i = -1;
	while (++i < len)
		res[i] = text[i];
	return (res);
}

char	*get_it_all(int fd, char *text)
{
	char	*buffer;
	int		is;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	is = 1;
	while (is > 0)
	{
		if (checker(buffer) != 0)
			break ;
		is = read(fd, buffer, BUFFER_SIZE);
		if (is < 0)
		{
			if (text)
				free (text);
			text = NULL;
			break ;
		}
		buffer[is] = '\0';
		text = ft_strjoin(text, buffer, 0);
	}
	free (buffer);
	return (text);
}

int	checker(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
