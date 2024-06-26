/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:26:03 by ylai              #+#    #+#             */
/*   Updated: 2024/06/22 20:03:56 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	while (s && *s)
	{
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
	char	*joined;
	size_t	len1;
	size_t	len2;

	len1 = gnl_strlen(s1);
	len2 = gnl_strlen(s2);
	joined = malloc((len1 + len2 + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	gnl_memcpy(joined, s1, len1);
	gnl_memcpy(joined + len1, s2, len2 + 1);
	return (joined);
}

char	*gnl_strdup(const char *s)
{
	size_t	len;
	char	*ans;
	size_t	i;

	i = 0;
	len = gnl_strlen(s);
	ans = (char *) malloc((len + 1) * sizeof(char));
	if (ans == NULL)
		return (NULL);
	while (i < len)
	{
		ans[i] = s[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
