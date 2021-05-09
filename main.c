/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:14:58 by vifernan          #+#    #+#             */
/*   Updated: 2021/05/08 18:01:16 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*line;

	line = malloc(sizeof(char *));
/*	if (argc == 1)
		fd = 0;
	else if	(argc == 2)
	{*/
		fd = open("fichero.txt", O_RDONLY);
		printf("fd-----%d\n", fd);

		//get_next_line(fd, line);
		printf("%d-----", get_next_line(fd, &line));
		//system("leaks a.out");
		printf("******MA-1-IN******%s\n", line);
		free(line);

		printf("%d-----", get_next_line(fd, &line));
		//system("leaks a.out");
		printf("******MA-2-IN******%s\n", line);
		free(line);

		printf("%d-----", get_next_line(fd, &line));
		//system("leaks a.out");
		printf("******MA-3-IN******%s\n", line);
		free(line);

		printf("%d-----", get_next_line(fd, &line));
		printf("******MA-4-IN******%s\n", line);
		free(line);

		printf("%d-----", get_next_line(fd, &line));
		printf("******MA-5-IN******%s\n", line);
		free(line);

		printf("%d-----", get_next_line(fd, &line));
		printf("******MA-6-IN******%s\n", line);
		free(line);

		printf("%d-----", get_next_line(fd, &line));
		printf("******MA-7-IN******%s\n", line);
		free(line);
/*	}
	if (argc == 2)*/
		close(fd);
}
