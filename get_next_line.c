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
	// 1st pass: calculate the size of the line then you can malloc it.
	// char	*checker;
	// int	bytes_r;
	// size_t	size;
	// char	*tmp;
	
	// checker = (char *) malloc(1);
	// size = 0;
	// while (1)
	// {
	// 	bytes_r = read(fd, checker, 1);
	// 	if (bytes_r <= 0)
	// 		break;
	// 	if (checker[0] != '\n')
	// 		size++;
	// 	else
	// 	{
	// 		// malloc here
	// 		tmp = (char *) malloc(size);
	// 	}
	// }
	
	/**
	 * updated algo: read in according to buffer size to this buffer
	 * look through the buffer, if found a next line, throw everything
	 * before it into a array, return that array. as for the buffer,
	 * keep the stuff after the next line character ('\n'), because for next
	 * interation, we will need it for the next line
	*/
	static char	*buffer;
	int	bytes_r;
	int	i;
	char	*value;
	int	current_i;

	buffer = (char *) malloc(BUFFER_SIZE + 1);
	i = 0;
	while (1)
	{
		bytes_r = read(fd, buffer, BUFFER_SIZE);
		if (bytes_r <= 0)
			break;
		current_i = 0;
		while (buffer[current_i] != '\n')
		{
			i++;
			current_i++;
		}
		if (current_i == BUFFER_SIZE)
			continue;
		value = (char *) malloc(i + 1);
		
		
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
	}
	return NULL;
}