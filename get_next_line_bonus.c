/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:48:52 by ylai              #+#    #+#             */
/*   Updated: 2024/06/29 14:58:55 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*find_next_line(int fd, char *remainder)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_r;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_r = 1;
	while (bytes_r > 0 && (!remainder || !gnl_strchr(remainder, '\n')))
	{
		bytes_r = read(fd, buffer, BUFFER_SIZE);
		if (bytes_r < 0)
		{
			free(remainder);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_r] = '\0';
		temp = gnl_strjoin(remainder, buffer);
		free(remainder);
		remainder = temp;
	}
	free(buffer);
	return (remainder);
}

char	*form_line(char **remainder)
{
	char	*newline;
	char	*line;
	char	*temp;
	size_t	len;

	newline = gnl_strchr(*remainder, '\n');
	if (newline)
	{
		len = newline - *remainder + 1;
		line = malloc(len + 1);
		if (!line)
			return (NULL);
		gnl_memcpy(line, *remainder, len);
		line[len] = '\0';
		temp = gnl_strdup(newline + 1);
		free(*remainder);
		*remainder = temp;
	}
	else
	{
		line = gnl_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder[fd] = find_next_line(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	if (*remainder[fd])
		return (form_line(&remainder[fd]));
	free(remainder[fd]);
	remainder[fd] = NULL;
	return (NULL);
}
