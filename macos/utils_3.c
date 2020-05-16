/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 19:02:46 by ginger            #+#    #+#             */
/*   Updated: 2020/05/16 16:28:03 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		check_width(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->height - 1)
	{
		if (map->w_checker[i] != map->w_checker[i + 1])
			terminate(ERR_WIDTH);
		i++;
	}
}

int			count_check(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
		{
			i++;
		}
		if (s[i])
			words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (words);
}
