/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:13:19 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/28 17:32:57 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "assets.h"
# include "mlx_data.h"

# define C_FLOOR		'0'
# define C_WALL			'1'
# define C_EXIT			'E'
# define C_ENEMY		'X'
# define C_COLLECTIBLE	'C'
# define C_PLAYER		'P'

/*
# define T_FLOOR		0
# define T_WALL			1
# define T_EXIT			2
# define T_ENEMY		3
# define T_COLLECTIBLE	4
# define T_PLAYER		5


typedef enum e_tile
{
	T_FLOOR,
	T_WALL,
	T_EXIT,
	T_ENEMY,
	T_COLLECTIBLE,
	T_PLAYER,
} t_tile;
*/

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;


typedef struct s_map
{
	//char		*filename;
	
	t_data		*data;
	void		*asset[ASSETS_COUNT + 1];
	char		**c_grid;
	t_tile		**grid; // Defined in ASSETS_H
	t_player	player;
	//int			tile_size;
	int			width;
	int			height;
}	t_map;

t_map	get_map(char *filename);

#endif
