/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:26:03 by ylai              #+#    #+#             */
/*   Updated: 2024/06/17 18:26:14 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t len = 0;
	while (s[len])
			len++;
	return len;
}

char *gnl_strchr(const char *s, int c) {
	while (*s) {
		if (*s == (char)c)
				return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*gnl_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	i = 0;
	if (temp_dest == NULL && temp_src == NULL)
		return (NULL);
	while (i < n)
	{
		*temp_dest = *temp_src;
		temp_src++;
		temp_dest++;
		i++;
	}
	return (dest);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t len1 = ft_strlen(s1);
	size_t len2 = ft_strlen(s2);
	char *joined = malloc((len1 + len2 + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	strcpy(joined, s1);
	strcpy(joined + len1, s2);
	return joined;
}

int	find_next_line(int fd, char *remainder, char *buffer, int *bytes_r)
{
	char	*temp;

	*bytes_r = 1;
	while (ft_strchr(remainder, '\n') && *bytes_r > 0)
	{
		bytes_r = read(fd, buffer, BUFFER_SIZE);
		if (bytes_r <= 0)
		{
			free(buffer);
			return (1);
		}
		buffer[bytes_r] = '\0';
		temp = gnl_strjoin(remainder, buffer);
		free(remainder);
		remainder = temp;
	}
}