/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 10:52:43 by vifernan          #+#    #+#             */
/*   Updated: 2021/05/10 17:44:38 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);
int		ft_finalline(char **s, char **line);
int		ft_status(int resread, char	**s, char **line);
char	*ft_sfd_cutlines(char **s, char *buffer);
char	*freestatic(char **s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

#endif
