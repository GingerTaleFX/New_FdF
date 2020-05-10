/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_controls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 15:36:05 by ginger            #+#    #+#             */
/*   Updated: 2020/05/10 21:00:52 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				mouse_scroll_and_press(int key, int x, int y, void *param)
{
	t_window	*window;

	(void)x;
	(void)y;
	window = (t_window *)param;
	if (key == MOUSE_SCROLL_DOWN || key == MOUSE_SRCOLL_UP)
		zoom(key, window);
	return (0);
}

int				key_press(int key, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (key == ESC_BTN)
		exit(0);
	if (key == ISO_BTN || key == FLAT_BTN)
		change_proj(key, window);
	if (key == ALPINE_HIEGH || key == ALPINE_LOW)
		alpine_msr(key, window);
	if (key == X_RMAD_LEFT || key == X_RMAD_RIGHT || \
		key == Y_RMAD_RIGHT || key == Y_RMAD_LEFT || \
		key == Z_RMAD_LEFT || key == Z_RMAD_RIGHT || \
		key == X_MPAD_LEFT || key == X_MPAD_RIGHT || \
		key == Y_MPAD_RIGHT || key == Y_MPAD_LEFT || \
		key == Z_MPAD_LEFT || key == Z_MPAD_RIGHT)
		rotation_btns(key, window);
	if (key == HIGH_SPEED || key == LOW_SPEED)
		speed_btns(key, window);
	if (key == TOP_ARROW || key == BOTTOM_ARROW || \
		key == RIGHT_ARROW || key == LEFT_ARROW)
		shifting(key, window);
	if (key == ZOOM_PLUS || key == ZOOM_MINUS || \
		key == ZOOM_RIGHT_PLUS || key == ZOOM_RIGHT_MINUS)
		zoom(key, window);
	return (0);
}

void			controls(t_window *window)
{
	mlx_hook(window->win_ptr, 2, 0, \
	key_press, window);
	mlx_hook(window->win_ptr, 4, 0, \
	mouse_scroll_and_press, window);
}
