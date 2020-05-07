/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginger <ginger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:57:43 by ginger            #+#    #+#             */
/*   Updated: 2020/05/07 12:25:55 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_USAGE			"Usage: ./fdf MAP_FILE"
# define ERR_MAP			"Incorrect MAP_FILE"
# define ERR_READING		"Reading error"
# define ERR_MAP_READING	"Reading error: bad map or color"
# define ERR_SPACES			"Incorrect MAP_FILE: Spaces more then 3"
# define ERR_WIDTH			"Incorrect MAP_FILE: diff lines' width"
# define ERR_MAP_INIT		"Map initialization error"
# define ERR_COORDS_INIT	"Coords initialization error"
# define ERR_WINDOW_INIT	"Window initialization error"
# define ERR_CONV_TO_ARR	"Conversion to array"
# define ERR_CAMERA_INIT	"Camera initialization error"

#endif
