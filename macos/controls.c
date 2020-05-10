/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:57:24 by ginger            #+#    #+#             */
/*   Updated: 2020/05/07 15:36:13 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shifting(int key, t_window *window)
{
	if (key == LEFT_ARROW)
		window->camera->x_offset -= 10;
	else if (key == RIGHT_ARROW)
		window->camera->x_offset += 10;
	else if (key == BOTTOM_ARROW)
		window->camera->y_offset -= 10;
	else if (key == TOP_ARROW)
		window->camera->y_offset += 10;
	draw(window->map, window);
}

void	alpine_msr(int key, t_window *window)
{
	if (key == ALPINE_HIEGH)
		window->camera->z_divisor += 0.1;
	if (key == ALPINE_LOW)
		window->camera->z_divisor -= 0.1;
	draw(window->map, window);
}

void	rotation_btns(int key, t_window *window)
{
	if (key == X_ROTATE_LEFT)
		window->camera->alpha += window->camera->speed;
	if (key == X_ROTATE_RIGHT)
		window->camera->alpha -= window->camera->speed;
	if (key == Y_ROTATE_LEFT)
		window->camera->beta += window->camera->speed;
	if (key == Y_ROTATE_RIGHT)
		window->camera->beta -= window->camera->speed;
	if (key == Z_ROTATE_LEFT)
		window->camera->gamma += window->camera->speed;
	if (key == Z_ROTATE_RIGHT)
		window->camera->gamma -= window->camera->speed;
	draw(window->map, window);
}

void	speed_btns(int key, t_window *window)
{
	if (key == HIGH_SPEED)
	{
		window->camera->speed += 0.05;
		window->camera->s_counter += 5;
	}
	if (key == LOW_SPEED)
	{
		if (window->camera->speed > 0.05)
		{
			window->camera->speed -= 0.05;
			window->camera->s_counter -= 5;
		}
	}
}

void	zoom(int key, t_window *window)
{
	if (key == ZOOM_PLUS || key == ZOOM_RIGHT_PLUS || \
	key == MOUSE_SRCOLL_UP)
		window->camera->zoom += 1;
	if (key == ZOOM_MINUS || key == ZOOM_RIGHT_MINUS \
	|| key == MOUSE_SCROLL_DOWN)
		if (window->camera->zoom > 1)
			window->camera->zoom -= 1;
	draw(window->map, window);
}
