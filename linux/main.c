/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:58:22 by ginger            #+#    #+#             */
/*   Updated: 2020/05/12 19:44:51 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			file_checker(char *file)
{
	int			fd;
	int			rd;

	if ((fd = open(file, O_RDONLY, 0)) <= 0 || \
		(rd = read(fd, 0, 0)) < 0)
		terminate(ERR_READING);
}

int				main(int ac, char **av)
{
	t_map		*map;
	t_coords	*coords_stack;
	t_window	*window;

	errno = 0;
	coords_stack = NULL;
	if (ac == 2)
	{
		file_checker(av[1]);
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
