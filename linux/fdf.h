/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:57:51 by ginger            #+#    #+#             */
/*   Updated: 2020/05/10 16:27:42 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "errors.h"
# include "colors.h"
# include "linux_controls.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <X11/X.h>

# define MENU_WIDTH		350

typedef enum
{
	false,
	true
}	t_bool;

typedef enum
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct		s_coords
{
	int				color;
	int				z;
	struct s_coords	*next;
}					t_coords;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_point;

typedef struct		s_map
{
	int				width;
	int				height;
	int				*coords_arr;
	int				*colors_arr;
	int				z_min;
	int				z_max;
	int				z_range;
}					t_map;

typedef struct		s_camera
{
	t_projection	projection;
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	double			speed;
	int				s_counter;
	float			z_divisor;
	int				x_offset;
	int				y_offset;
}					t_camera;

typedef struct		s_window
{
	int				win_x;
	int				win_y;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	t_map			*map;
	t_camera		*camera;
}					t_window;

void				alpine_msr(int key, t_window *window);
void				change_proj(int key, t_window *window);
void				controls(t_window *window);
void				count_white_spaces(char *line);
void				draw(t_map *map, t_window *window);
t_camera			*init_camera_position(void);
void				free_arr(char **arr);
int					ft_atoi_base(const char *str, int base);
t_bool				ft_is_number(char *str, int base);
int					ft_is_space(int c);
int					get_default_color(int z, t_map *map);
int					get_color(t_point current, t_point start, \
					t_point end, t_point delta);
int					get_index(int x, int y, int width);
t_coords			*new_coord(char *line);
t_map				*new_map(void);
t_point				new_point(int x, int y, t_map *map);
t_window			*new_window(t_map *map);
double				percent(int start, int end, int current);
void				print_menu(t_window *window);
void				push(t_coords **coords_stack, t_coords *new);
void				read_file(char *file, t_map *map, t_coords **coords_stack);
void				rotate_x(double *y, double *z, double alpha);
void				rotate_y(double *x, double *z, double beta);
void				rotate_z(double *x, double *y, double gamma);
void				rotation_btns(int key, t_window *window);
void				speed_btns(int key, t_window *window);
void				shifting(int key, t_window *window);
void				struct_freedom(t_map *map, t_window *window, \
					t_coords *coords_stack);
void				structure_to_array(t_coords **coords_stack, t_map *map);
void				terminate(char *s);
t_point				visual_ops(t_point p, t_window *window);
void				zoom(int key, t_window *window);

#endif
