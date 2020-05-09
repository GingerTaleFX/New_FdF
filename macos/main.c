/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:58:22 by ginger            #+#    #+#             */
/*   Updated: 2020/05/08 10:18:44 by ginger           ###   ########.fr       */
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
		printf("%d\n", "1");
		if ((fd = open(av[1], O_RDONLY, 0)) <= 0)
			terminate(ERR_READING);
		printf("%d\n", "2");
		map = new_map();
		printf("%d\n", "3");
		read_file(av[1], map, &coords_stack);
		printf("%d\n", "4");
		if (!(window = new_window(map)))
			terminate(ERR_WINDOW_INIT);
		printf("%d\n", "5");
		structure_to_array(&coords_stack, map);
		printf("%d\n", "6");
		window->camera = init_camera_position();
		printf("%d\n", "7");
		draw(map, window);
		printf("%d\n", "8");
		controls(window);
		printf("%d\n", "9");
		mlx_loop(window->mlx_ptr);
		printf("%d\n", "10");
	}
	else
		terminate(ERR_USAGE);
	struct_freedom(map, window, coords_stack);
	return (0);
}
