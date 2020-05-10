/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:58:22 by ginger            #+#    #+#             */
/*   Updated: 2020/05/10 17:47:27 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			nulling_funcs(t_map **map, t_coords **coords, t_window **window)
{
	coords = NULL;
	map = NULL;
	window = NULL;
}

int				main(int ac, char **av)
{
	t_map		*map;
	t_coords	*coords_stack;
	t_window	*window;
	int			fd;

	errno = 0;
	nulling_funcs(&map, &coords_stack, &window);
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY, 0)) <= 0)
			terminate(ERR_READING);
		map = new_map();
		read_file(av[1], map, &coords_stack);
		if (!(window = new_window(map)))
			terminate(ERR_WINDOW_INIT);
		structure_to_array(&coords_stack, map);
		window->camera = init_camera_position();
		draw(map, window);
		controls(window);
		mlx_loop(window->mlx_ptr);
	}
	else
		terminate(ERR_USAGE);
	struct_freedom(map, window, coords_stack);
	return (0);
}
