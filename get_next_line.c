/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:50:33 by ylai              #+#    #+#             */
/*   Updated: 2024/06/29 14:30:48 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = find_next_line(fd, remainder);
	if (!remainder)
		return (NULL);
	if (*remainder)
		return (form_line(&remainder));
	free(remainder);
	remainder = NULL;
	return (NULL);
}
