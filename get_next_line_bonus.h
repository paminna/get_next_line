/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:46:30 by paminna           #+#    #+#             */
/*   Updated: 2020/12/19 17:31:43 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, char c);
char	*ft_strjoin(char const *s1, const char *s2);
int		ft_strlen(const char *s);
char	*ft_strlcpy(char *dst, const char *src, int dstsize);
char	*ft_strdup(const char *s1);

#endif
