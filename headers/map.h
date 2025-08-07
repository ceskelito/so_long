/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceskelito <ceskelito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:13:19 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/07 18:40:01 by ceskelito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "assets.h"
# include "mlx_data.h"

# define C_FLOOR '0'
# define C_WALL '1'
# define C_EXIT 'E'
# define C_ENEMY 'X'
# define C_COLLECTIBLE 'C'
# define C_PLAYER 'P'

// only used in flood_fill
typedef struct s_grid
{
	int		**grid;
	int		width;
	int		height;

}			t_grid;

typedef struct s_player
{
	int			x;
	int			y;
	bool		on_exit;
	int			moves;
	int			collectibles;
}				t_player;

typedef struct s_map
{
	t_data		*data;
	void		*asset[ASSETS_COUNT + 1];
	char		**c_grid;
	t_tile		**grid; // Defined in ASSETS_H
	t_player	player;
	int			total_collectibles;
	int			width;
	int			height;
}				t_map;

t_map			get_map(char *filename);

#endif
