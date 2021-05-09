/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:11:06 by vifernan          #+#    #+#             */
/*   Updated: 2021/05/07 17:13:17 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	i = -1;
	j = 0;
	while (s[++i] != '\0')
	{
		if (i >= start && j < len)
			j++;
	}
	str = malloc(sizeof(char) * j + 1);
	if (!str)
		return (0);
	j = 0;
	i = 0;
	while (s[j] != '\0')
	{
		if (j >= start && i < len)
			str[i++] = s[j];
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = ft_strlen(s1);
	dst = (char *) malloc(i + 1);
	if (!dst)
		return (0);
	j = 0;
	while (s1[j] != '\0')
	{
//	buffer[BUFFER_SIZE] = '\0';
		dst[j] = s1[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 && s2)
	{
		str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!str)
			return (0);
		i = 0;
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
			str[i++] = s2[j++];
		str[i] = '\0';
		return (str);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*s1;
	size_t		i;
	size_t		x;

	s1 = s;
	x = ft_strlen(s1);
	i = 0;
	while (i < x)
	{
		if (s1[i] == (char)c)
			return ((char *) s1 + i);
		i++;
	}
	return (0);
}
