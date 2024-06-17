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
	char	*checker;
	int	bytes_r;
	size_t	size;
	char	*tmp;
	
	checker = (char *) malloc(1);
	size = 0;
	while (1)
	{
		bytes_r = read(fd, checker, 1);
		if (bytes_r <= 0)
			break;
		if (checker[0] != '\n')
			size++;
		else
		{
			// malloc here
			tmp = (char *) malloc(size);
		}
	}
	
}