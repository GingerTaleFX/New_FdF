/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:58:48 by ginger            #+#    #+#             */
/*   Updated: 2020/05/12 19:43:28 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		parser(char **coords, t_coords **coords_stack)
{
	while (*coords)
		push(coords_stack, new_coord(*(coords++)));
}

void		get_coords(char *file, t_coords **coords_stack)
{
	int		fd;
	int		ret;
	char	*line;
	char	**coords;

	ret = 0;
	fd = open(file, O_RDONLY, 0);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (!(coords = ft_strsplit(line, ' ')) || ret < 0)
			terminate(ERR_COORDS_INIT);
		parser(coords, coords_stack);
		free_arr(coords);
		free(line);
	}
	free(line);
	if (!(*coords_stack))
		terminate(ERR_COORDS_INIT);
}

int			count_height(char *file)
{
	int		height;
	int		fd;
	int		ret;
	char	*line;

	ret = 0;
	height = 0;
	fd = open(file, O_RDONLY, 0);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < 0)
			terminate(ERR_MAP);
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

int			count_width(int fd, int i, t_map *map)
{
	int		width;
	int		ret;
	char	*line;

	if (!(map->w_checker = (int *)ft_memalloc(sizeof(int) * (i + 1))))
		terminate(ERR_MAP);
	i = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (ret <= 0 || (width = ft_cl(line, ' ')) == 0)
			terminate(ERR_MAP);
		count_white_spaces(line);
		map->w_checker[i] = width;
		i++;
		free(line);
	}
	map->w_checker[i] = width;
	ckeck_width(map);
	free(map->w_checker);
	free(line);
	return (width);
}

void		read_file(char *file, t_map *map, t_coords **coords_stack)
{
	int		fd;

	fd = open(file, O_RDONLY, 0);
	map->height = count_height(file);
	map->width = count_width(fd, map->height, map);
	get_coords(file, coords_stack);
	close(fd);
}
