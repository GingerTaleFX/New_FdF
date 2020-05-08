/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:58:22 by ginger            #+#    #+#             */
/*   Updated: 2020/05/08 10:18:52 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int ac, char **av)
{
	t_map		*map;
	t_coords	*coords_stack;
	t_window	*window;
	int			fd;

	errno = 0;
	coords_stack = NULL;
	map = NULL;
	window = NULL;
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
