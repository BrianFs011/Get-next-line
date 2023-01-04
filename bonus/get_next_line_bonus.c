/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:43:03 by briferre          #+#    #+#             */
/*   Updated: 2022/07/16 13:25:08 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	line = NULL;
	while (fd != -1)
	{
		buf = (char *)malloc((sizeof(char) * 1));
		if (read(fd, buf, 1) == 1)
			line = ft_more_one(line, buf[0]);
		else
		{
			fd = -1;
			buf[0] = ' ';
		}
		if (buf[0] == '\n')
			fd = -1;
		if (*buf)
			free(buf);
	}
	return (line);
}
