/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceskelito <ceskelito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:32:36 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/07 18:40:09 by ceskelito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# define ASSETS_SIZE 128
# define ASSETS_COUNT 10

# define PATH_FLOOR			"assets/floor.xpm"
# define PATH_WALL			"assets/wall.xpm"
# define PATH_PLAYER_UP		"assets/player_up.xpm"
# define PATH_PLAYER_DOWN	"assets/player_down.xpm"
# define PATH_PLAYER_LEFT	"assets/player_left.xpm"
# define PATH_PLAYER_RIGHT	"assets/player_right.xpm"
# define PATH_ENEMY			"assets/tile-01.xpm"
# define PATH_COLLECTIBLE	"assets/collectible-128.xpm"
# define PATH_EXIT			"assets/exit.xpm"

# define T_PLAYER_STD T_PLAYER_DOWN

# include <stdbool.h>

typedef enum e_tile
{
	T_VOID,
	T_FLOOR,
	T_WALL,
	T_EXIT,
	T_PLAYER_UP,
	T_PLAYER_DOWN,
	T_PLAYER_LEFT,
	T_PLAYER_RIGHT,
	T_ENEMY,
	T_COLLECTIBLE,
}		t_tile;

bool	set_assets(void *mlx_ptr, void *asset[]);

#endif
