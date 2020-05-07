/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:57:58 by ginger            #+#    #+#             */
/*   Updated: 2020/05/07 16:32:55 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map			*new_map(void)
{
	t_map		*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		terminate(ERR_MAP_INIT);
	map->width = 0;
	map->height = 0;
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->z_min = FT_INT_MAX;
	map->z_max = FT_INT_MIN;
	map->z_range = 0;
	return (map);
}

t_window		*new_window(t_map *map)
{
	t_window	*window;

	if (!(window = (t_window *)ft_memalloc(sizeof(t_window))))
		terminate(ERR_WINDOW_INIT);
	window->win_x = 1920;
	window->win_y = 1080;
	if (!(window->mlx_ptr = mlx_init()))
		terminate(ERR_WINDOW_INIT);
	if (!(window->win_ptr = mlx_new_window(window->mlx_ptr, \
	window->win_x, window->win_y, "FDF")))
		terminate(ERR_WINDOW_INIT);
	if (!(window->img = mlx_new_image(window->mlx_ptr, \
	window->win_x, window->win_y)))
		terminate(ERR_WINDOW_INIT);
	window->data_addr = mlx_get_data_addr(window->img, \
	&(window->bits_per_pixel), \
	&(window->size_line), &(window->endian));
	window->map = map;
	return (window);
}

t_coords		*new_coord(char *line)
{
	t_coords	*coord;
	char		**parts;

	if (!(coord = (t_coords *)ft_memalloc(sizeof(t_coords))))
		terminate(ERR_MAP_READING);
	if (!(parts = ft_strsplit(line, ',')))
		terminate(ERR_MAP_READING);
	if (!ft_is_number(parts[0], 10))
		terminate(ERR_MAP_READING);
	if (parts[1] && !ft_is_number(parts[1], 16))
		terminate(ERR_MAP_READING);
	coord->z = ft_atoi(parts[0]);
	coord->color = parts[1] ? ft_atoi_base(parts[1], 16) : -1;
	coord->next = NULL;
	free_arr(parts);
	return (coord);
}

t_camera		*init_camera_position(void)
{
	t_camera	*camera;

	if (!(camera = (t_camera*)ft_memalloc(sizeof(t_camera))))
		terminate(ERR_CAMERA_INIT);
	camera->zoom = 20;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->speed = 0.1;
	camera->s_counter = 5;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->projection = PARALLEL;
	return (camera);
}

t_point			new_point(int x, int y, t_map *map)
{
	t_point		point;
	int			index;

	index = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->coords_arr[index];
	point.color = (map->colors_arr[index] == -1) ? \
		get_default_color(point.z, map) : map->colors_arr[index];
	return (point);
}
