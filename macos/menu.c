/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:58:35 by ginger            #+#    #+#             */
/*   Updated: 2020/05/10 20:59:45 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_window *window)
{
	int y;

	y = 0;
	mlx_string_put(window->mlx_ptr, window->win_ptr, 25, y += 25, \
	TEXT_COLOR, "Moving: Arrows");
	mlx_string_put(window->mlx_ptr, window->win_ptr, 25, y += 35, \
	TEXT_COLOR, "Isometric: 'i' - isometric, 'p' - flat");
	mlx_string_put(window->mlx_ptr, window->win_ptr, 25, y += 35, \
	TEXT_COLOR, "Alpines: 'h' - alpine high, 'l' - alpine low");
	mlx_string_put(window->mlx_ptr, window->win_ptr, 25, y += 35, \
	TEXT_COLOR, "Zooming: '+' and '-'");
	mlx_string_put(window->mlx_ptr, window->win_ptr, 25, y += 35, \
	TEXT_COLOR, "Rotate X: '2' and '8'");
	mlx_string_put(window->mlx_ptr, window->win_ptr, 25, y += 15, \
	TEXT_COLOR, "Rotate Y: '4' and '6'");
	mlx_string_put(window->mlx_ptr, window->win_ptr, 25, y += 15, \
	TEXT_COLOR, "Rotate Z: '1' and '3'");
	mlx_string_put(window->mlx_ptr, window->win_ptr, 25, y += 15, \
	TEXT_COLOR, "Rotatin speed: '9' - slower, '0' - faster");
	mlx_string_put(window->mlx_ptr, window->win_ptr, 25, y += 35, \
	TEXT_COLOR, "Mouse: scroll up/down - zooming");
	mlx_string_put(window->mlx_ptr, window->win_ptr, 25, y += 35, \
	TEXT_COLOR, "Exit: ESC");
}
