/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:46:05 by paminna           #+#    #+#             */
/*   Updated: 2020/12/25 14:44:26 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	n_in_rem(char *str_n, char **remainder, char **line)
{
	char *tmp;
	char *tmp_2;

	*str_n++ = '\0';
	tmp = *remainder;
	tmp_2 = *line;
	*line = ft_strdup(*remainder);
	if (*line == NULL)
		return (-1);
	*remainder = ft_strdup(str_n);
	if (*remainder == NULL)
		return (-1);
	free(tmp);
	return (1);
}

int	r_less_null(char **remainder)
{
	free(*remainder);
	return (-1);
}

int	r_null(char **line, char **remainder)
{
	*line = ft_strdup(*remainder);
	if (*line == NULL)
		return (-1);
	free(*remainder);
	*remainder = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char *remainder[1024];
	int			r;
	char		*str_n;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (remainder[fd] == NULL && !(remainder[fd] = ft_strdup("")))
		return (-1);
	if ((str_n = ft_strchr(remainder[fd], '\n')))
		return (n_in_rem(str_n, &remainder[fd], line));
	while ((r = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r] = '\0';
		tmp = remainder[fd];
		remainder[fd] = ft_strjoin(remainder[fd], buf);
		if (remainder [fd] == NULL)
			return (-1);
		free(tmp);
		if ((str_n = ft_strchr(remainder[fd], '\n')))
			return (n_in_rem(str_n, &remainder[fd], line));
	}
	return ((r < 0) ?
		r_less_null(&remainder[fd]) : r_null(line, &remainder[fd]));
}
