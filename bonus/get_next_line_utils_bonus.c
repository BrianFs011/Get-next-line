/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:07:06 by briferre          #+#    #+#             */
/*   Updated: 2022/07/16 13:25:16 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

int	ft_cont_string(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

char	*ft_more_one(char *line, char word)
{
	int		i;
	int		size_line;
	char	*new_line;

	if (!line)
		size_line = 0;
	else
		size_line = ft_cont_string(line);
	new_line = (char *)malloc((sizeof(char) * size_line) + 1 + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = word;
	new_line[i + 1] = '\0';
	if (line)
		free(line);
	return (new_line);
}
