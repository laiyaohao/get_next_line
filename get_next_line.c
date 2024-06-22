/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:50:33 by ylai              #+#    #+#             */
/*   Updated: 2024/06/17 19:17:00 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	int	bytes_r;
	char	*buffer;
	char	*temp;
	char	*newline;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	if (find_next_line(fd, remainder, &bytes_r))
		return NULL;
	bytes_r = 1;
	while (ft_strchr(remainder, '\n') && bytes_r > 0)
	{
		bytes_r = read(fd, buffer, BUFFER_SIZE);
		if (bytes_r <= 0)
			break;
		buffer[bytes_r] = '\0';
		temp = ft_strjoin(remainder, buffer);
		free(remainder);
		remainder = temp;
		// following code can be one function
		// while (buffer[current_i] != '\n')
		// {
		// 	i++;
		// 	current_i++;
		// }
		// end of the function
		// if (current_i == BUFFER_SIZE)
		// 	continue;
		// value = (char *) malloc(i + 1);
		
		
		// so theres a i and current_i, 
		// i is to count the space required to malloc for the current line
		// current_i is to count the current iter
		// and if current_i == buffer_size, that means buffer size cannot find
		// \n, and thus means need to take in the next buffer
		// if can find \n, then we malloc to a size of i.
		// cpy the previou buffer to value.
		// cpy the current buffer over to value. this is what we need to return
		// find the difference between buffer_size and current_i
		// this is the number of characters after \n and for the next iter
		// malloc a space for next iter
		// cpy the remaining buffer into a space for next inter
		// return the value

		// reset i
		// i = 0;
	}
	free(buffer);
	if (remainder && *remainder)
	{
		newline = ft_strchr(remainder, '\n');
		if (newline)
		{
			*newline = '\0';

		}
	}
	return NULL;
}