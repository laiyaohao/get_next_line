/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:56:19 by ylai              #+#    #+#             */
/*   Updated: 2024/06/29 15:05:04 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
void	*gnl_memcpy(void *dest, const void *src, size_t n);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*find_next_line(int fd, char *remainder);
char	*form_line(char **remainder);
char	*gnl_strdup(const char *s);
#endif
