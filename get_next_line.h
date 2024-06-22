/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:50:25 by ylai              #+#    #+#             */
/*   Updated: 2024/06/17 17:21:16 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifnDef BUFFER_SIZE
# define BUFFER_SIZE 24
#endif

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s)
char  *gnl_strchr(const char *s, int c);
void	*gnl_memcpy(void *dest, const void *src, size_t n);
char	*gnl_strjoin(char const *s1, char const *s2);
void  find_next_line(int fd, char *remainder, int *byte_r)