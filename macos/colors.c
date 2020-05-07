/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:57:05 by ginger            #+#    #+#             */
/*   Updated: 2020/05/07 16:03:52 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			get_color(t_point current, \
			t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,\
	(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF, \
	(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, \
	end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int			get_default_color(int z, t_map *map)
{
	double	percentage;

	percentage = percent(map->z_min, map->z_max, z);
	if (percentage < 0.2)
		return (COLOR_RED);
	else if (percentage < 0.4)
		return (COLOR_ORANGE);
	else if (percentage < 0.6)
		return (COLOR_PEACH);
	else if (percentage < 0.8)
		return (COLOR_MINT);
	else
		return (COLOR_BLUE);
}
