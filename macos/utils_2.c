/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:59:19 by ginger            #+#    #+#             */
/*   Updated: 2020/05/10 16:29:59 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		struct_freedom(t_map *map, t_window *window, t_coords *coords_stack)
{
	free(map);
	free(window);
	free(coords_stack);
}

void		push(t_coords **coords_stack, t_coords *new)
{
	if (coords_stack)
	{
		if (new)
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

int			get_index(int x, int y, int width)
{
	return (y * width + x);
}

double		percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return ((placement / distance));
}
