/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:59:27 by ginger            #+#    #+#             */
/*   Updated: 2020/05/07 16:02:55 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		isometric(double *x, double *y, double z, t_window *window)
{
	double	previous_x;
	double	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) \
	- window->camera->z_divisor * z;
}

void		change_proj(int key, t_window *window)
{
	window->camera->alpha = 0;
	window->camera->beta = 0;
	window->camera->gamma = 0;
	window->camera->speed = 0.1;
	window->camera->s_counter = 5;
	if (key == ISO_BTN)
		window->camera->projection = ISO;
	if (key == FLAT_BTN)
		window->camera->projection = PARALLEL;
	draw(window->map, window);
}

t_point		visual_ops(t_point p, t_window *window)
{
	p.x *= window->camera->zoom;
	p.y *= window->camera->zoom;
	p.z *= window->camera->zoom;
	p.x -= (window->map->width * window->camera->zoom) / 2;
	p.y -= (window->map->height * window->camera->zoom) / 2;
	rotate_x(&p.y, &p.z, window->camera->alpha);
	rotate_y(&p.x, &p.z, window->camera->beta);
	rotate_z(&p.x, &p.y, window->camera->gamma);
	if (window->camera->projection == ISO)
		isometric(&p.x, &p.y, p.z, window);
	p.x += (window->win_x - MENU_WIDTH) / 2 \
	+ window->camera->x_offset + MENU_WIDTH;
	p.y += (window->win_y + window->map->height * window->camera->zoom) / 2 \
	+ window->camera->y_offset;
	return (p);
}
