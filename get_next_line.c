/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:47:16 by paminna           #+#    #+#             */
/*   Updated: 2020/11/23 21:16:29 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int get_next_line(int fd, char **line)
{
	static char *arr;
	int 		r;
	char 		*str_n;
	int 		i;

	if (!fd || !line || !BUFFER_SIZE || !(arr = (char*)malloc(BUFFER_SIZE + 1)))
		return(-1);
	while ((r = read(fd, arr, BUFFER_SIZE) > 0))
	{
		if ((str_n = ft_strchr((const char*)arr, '\n')))
		{
			str_n++;
			return (1);
		}
		arr[BUFFER_SIZE] = '\0';
		*line = ft_strjoin(*line,arr);
	}
	return (0);
}git commit -m "first commit"

int main()
{

}