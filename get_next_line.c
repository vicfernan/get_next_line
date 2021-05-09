/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:17:29 by vifernan          #+#    #+#             */
/*   Updated: 2021/05/08 19:06:40 by vifernan         ###   ########.fr       */
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

	if (!s1)
		return (0);
	i = ft_strlen(s1);
	dst = (char *) malloc(i + 1);
	if (!dst)
		return (0);
	j = 0;
	while (s1[j] != '\0')
	{
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

	if (!s)
		return (0);
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

int	ft_finalline(char **s, char **line)
{
	char	*aux;
	int		i;

	i = 0;
	while (((*s)[i] != '\n') && ((*s)[i] != '\0'))
		i++;
	if ((*s)[i] == '\n')
	{
		*line = ft_substr(*s, 0, i);
		aux = ft_strdup(&(*s)[i + 1]);
		free(*s);
		*s = aux;
		printf("--S--%s\n", *s);
		if ((*s)[0] == 0)
		{
			free(*s);
			*s = NULL;
		}
		return (1);
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
	}
	return (0);
}

int get_next_line(int fd, char **line)
{
	static char	*s[4096];
	char		buffer[BUFFER_SIZE + 1];
	char		*aux;
	int		resread;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	resread = 1;
	while (resread > 0)
	{
		resread = read(fd, buffer, BUFFER_SIZE);
		buffer[resread] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buffer);
		else
		{
			aux = ft_strjoin(s[fd], buffer);
			free(s[fd]);
			s[fd] = aux;
		}
		if (ft_strchr(s[fd], '\n') != 0)
			break;
	}
	if (!s[fd] && resread == 0)
		return (0);
	return (ft_finalline(&s[fd], line));
}
