/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:59:08 by ginger            #+#    #+#             */
/*   Updated: 2020/05/10 16:29:59 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

void		free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int			ft_is_space(int c)
{
	return (c == '\t' ||
			c == '\n' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ');
}

void		count_white_spaces(char *line)
{
	int		space;
	int		i;

	i = 0;
	space = 0;
	while (line[i])
	{
		while (line[i] == ' ')
		{
			space++;
			i++;
		}
		if (space > 3)
			terminate(ERR_SPACES);
		space = 0;
		i++;
	}
}
