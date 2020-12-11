/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:47:16 by paminna           #+#    #+#             */
/*   Updated: 2020/12/11 20:18:08 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int check_1(char *str_n, char *remainder, char **line)
{
	char *tmp;

	*str_n = '\0';
							// *helper = (char)malloc(ft_strlen(remainder));
							// while (*remainder != '\n')
							// 	*helper++ = *remainder++;
	tmp = remainder;
	remainder = ft_strjoin(str_n + 1, NULL); //  убираем записанное из remainder
	free(tmp);
	tmp = *line;
	*line = ft_strjoin(*line, remainder); // записываем из остатка в line
	free(tmp);
	return (1);
}
int malloc_line_and_remainder(char **line, char **remainder)
{
	if (!(*line = (char*)malloc(1)))
		return (-1);
	if (!(*remainder = (char*)malloc(1)))
	{
		free(*line);
		return (-1);
	}
	*line[0] = '\0';
	*remainder[0] = '\0';
	return (0);
}

int get_next_line(int fd, char **line)
{
	static char *remainder;  				// остаток
	int 		r;							// результат считывания из файла
	char 		*str_n;		 				// указатель на строку начиная с \n
    char		*helper;
	char		buf[BUFFER_SIZE + 1];		// считывание 
	char		*tmp;

	if (!fd || !line || !BUFFER_SIZE || !(r = read(fd, buf, BUFFER_SIZE)) ||
	malloc_line_and_remainder(line, &remainder) == -1)
		return (-1);

// 	if ((str_n = ft_strchr(remainder, '\n')))
// 	{
// 		// *str_n = '\0';
// 		// 					// *helper = (char)malloc(ft_strlen(remainder));
// 		// 					// while (*remainder != '\n')
// 		// 					// 	*helper++ = *remainder++;
// 		// tmp = remainder;
// 		// remainder = ft_strjoin(str_n + 1, NULL); //  убираем записанное из remainder
// 		// free(tmp);
// 		// tmp = *line;
// 		// *line = ft_strjoin(*line, remainder); // записываем из остатка в line
// 		// free(tmp);
// 		// return (1);
// 		return (check_1(str_n, remainder, line));
// 	}
// 	else
// 	{
// 		if ((r = read(fd, buf, BUFFER_SIZE)) > 0)
// 		{
// 			tmp = remainder;
// 			remainder = ft_strjoin(remainder, buf);
// 			free(tmp);
// 		}
// 		else
// 		{	
// 			tmp = *line;
// 			*line = ft_strjoin(*line,remainder);
// 			free(tmp);
// 			free(remainder);
// 			return(0);
// 		}
// 	}
// 	return (0);

}
