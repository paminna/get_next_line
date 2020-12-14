/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:47:16 by paminna           #+#    #+#             */
/*   Updated: 2020/12/14 19:44:37 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int n_in_rem(char *str_n, char **remainder, char **line)
{
	char *tmp;
	char *tmp_2;

	*str_n++ = '\0';
	tmp = *remainder;
	tmp_2 = ft_strjoin(*line, *remainder); // записываем из остатка в line
	*remainder = ft_strdup(str_n);
	// free(*line);
	*line = tmp_2;
	free(tmp);
	// free(tmp_2);
	return (1);
}

int get_next_line(int fd, char **line)
{
	static char *remainder;  				// остаток
	int 		r;							// результат считывания из файла
	char 		*str_n;		 				// указатель на строку начиная с \n
	char		*buf;						// считывание 
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (*line == NULL)
		*line = (char*)malloc(1);
	// else
	// 	*line = (char*)malloc(BUFFER_SIZE + 1);
	buf = (char*)malloc(sizeof(char)*(BUFFER_SIZE + 1));
	if (remainder == NULL)
		remainder = ft_strdup("");
	while ((r = read(fd, buf, BUFFER_SIZE)))
	{	
		buf[r] = '\0';
		tmp = remainder;
		remainder = ft_strjoin(remainder, buf);
		free(tmp);
		if ((str_n = ft_strchr(remainder, '\n')))
			return(n_in_rem(str_n, &remainder, line));
		if (r < 0)
		{
			free(buf);
			free(remainder);
			return (-1);
		}
	}
	if (remainder && r == 0)
	{
		*line = ft_strdup(remainder); 
		free(remainder);
	}
	return(0);
}

int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *line;
	int i;

	i = 1;
	while (i)
	{
		i = get_next_line(fd, &line);
		printf("i = %d %s\n", i, line);
		free(line);
	}
	return (0);
}

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