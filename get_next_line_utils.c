/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:07:19 by paminna           #+#    #+#             */
/*   Updated: 2020/12/14 13:52:20 by paminna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, char c)
{
	int i;

	i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char*)&s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}

char	*ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int i;

	i = 0;
	if (src == NULL)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] != '\0' && (dstsize - i - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*buffer;
	size_t	i;
	int 	len;

	i = -1;
	if (s1 == NULL)
		len = 0;
	else
		len = ft_strlen(s1);
	buffer = (char*)malloc(len + 1);
	if (buffer == 0)
		return (NULL);
	while (s1[++i])
		buffer[i] = s1[i];
	buffer[i] = '\0';
	return (buffer);
}
