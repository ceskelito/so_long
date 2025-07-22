/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:32:36 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/22 18:00:46 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# define ASSETS_SIZE	128
# define ASSETS_COUNT	6

# define PATH_FLOOR			"assets/floor.xpm"
# define PATH_WALL			"assets/wall.xpm"
# define PATH_PLAYER		"assets/player.xpm"
# define PATH_ENEMY			"assets/tile-01.xpm"
# define PATH_COLLECTIBLE	"assets/tile-01.xpm"
# define PATH_EXIT			"assets/exit.xpm"

typedef enum e_tile
{
	T_FLOOR,
	T_WALL,
	T_EXIT,
	T_PLAYER,
	T_ENEMY,
	T_COLLECTIBLE,
} t_tile;


bool	set_assets(void *mlx_ptr, void *asset[]);

#endif
