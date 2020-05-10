/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:57:36 by ginger            #+#    #+#             */
/*   Updated: 2020/05/10 19:00:20 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(t_window *window, int x, int y, int color)
{
	int		i;

	if (x >= MENU_WIDTH && x < window->win_x && y >= 0 && y < window->win_y)
	{
		i = (x * window->bits_per_pixel / 8) + (y * window->size_line);
		window->data_addr[i] = color;
		window->data_addr[++i] = color >> 8;
		window->data_addr[++i] = color >> 16;
	}
}

void		make_steps(t_point *step, t_point *first, t_point *second)
{
	step->x = FT_ABS(second->x - first->x);
	step->y = FT_ABS(second->y - first->y);
}

void		bresenham(t_point first, t_point second, t_window *window)
{
	t_point	step;
	t_point	sign;
	t_point	curr;
	int		position[2];

	make_steps(&step, &first, &second);
	sign.x = first.x < second.x ? 1 : -1;
	sign.y = first.y < second.y ? 1 : -1;
	position[0] = step.x - step.y;
	curr = first;
	while ((int)(curr.x - second.x) || (int)(curr.y - second.y))
	{
		put_pixel(window, curr.x, curr.y, get_color(curr, first, second, step));
		if ((position[1] = position[0] * 2) > -step.y)
		{
			position[0] -= step.y;
			curr.x += sign.x;
		}
		if (position[1] < step.x)
		{
			position[0] += step.x;
			curr.y += sign.y;
		}
	}
}

void		draw_background(t_window *window)
{
	int		*image;
	int		i;

	ft_bzero(window->data_addr, ((window->win_x + window->win_y) \
	* (window->bits_per_pixel / 8)));
	image = (int *)(window->data_addr);
	i = 0;
	while (i < (window->win_x * window->win_y))
	{
		image[i] = ((i % window->win_x) < MENU_WIDTH) \
		? MENU_BACKGROUND : BACKGROUND;
		i++;
	}
}

void		draw(t_map *map, t_window *window)
{
	double	x;
	double	y;

	draw_background(window);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != window->map->width - 1)
				bresenham(visual_ops(new_point(x, y, map), window), \
				visual_ops(new_point(x + 1, y, map), window), window);
			if (y != window->map->height - 1)
				bresenham(visual_ops(new_point(x, y, map), window), \
				visual_ops(new_point(x, y + 1, map), window), window);
			x++;
		}
		y++;
	}
	single_dot(window, map);
	mlx_put_image_to_window(window->mlx_ptr, \
	window->win_ptr, window->img, 0, 0);
	print_menu(window);
}
