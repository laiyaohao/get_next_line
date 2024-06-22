/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:50:33 by ylai              #+#    #+#             */
/*   Updated: 2024/06/22 19:19:57 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	find_next_line(int *fd, char **remainder, char **buffer, int *bytes_r)
{
	char	*temp;

	*bytes_r = 1;
	while (bytes_r > 0 && (!*remainder || !gnl_strchr(*remainder, '\n')))
	{
		*bytes_r = read(*fd, *buffer, BUFFER_SIZE);
		if (*bytes_r <= 0)
			return (1);
		(*buffer)[*bytes_r] = '\0';
		temp = gnl_strjoin(*remainder, *buffer);
		
		free(*remainder);
		printf("*remainder, %s", *remainder);
		*remainder = temp;
	}
	return (0);
}

char	*form_line(char *remainder, char *newline, char *temp)
{
	char	*line;
	
	if (remainder && *remainder)
	{
		newline = gnl_strchr(remainder, '\n');
		if (newline)
		{
			*newline = '\0';
			line = gnl_strdup(remainder);
			temp = gnl_strdup(newline + 1);
			free(remainder);
			remainder = temp;
		}
		else
		{
			line = gnl_strdup(remainder);
			free(remainder);
			remainder = NULL;
		}
		return line;
	}
	free(remainder);
	remainder = NULL;
	return NULL;
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	int	bytes_r;
	char	*buffer;
	char	*temp;
	char	*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	if (find_next_line(&fd, &remainder, &buffer, &bytes_r))
	{
		free(buffer);
		return NULL;
	}
	return (form_line(remainder, newline, temp));
}

int	main(void)
{
	int fd = open("test.txt", O_RDONLY, 0);
	if (fd == -1) {
		perror("Error opening file");
		return 1;
	}
	char *line;
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return 0;
}