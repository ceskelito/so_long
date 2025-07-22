/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:32:36 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/22 15:57:48 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# define ASSETS_SIZE	128
# define ASSETS_FOLDER	assets
# define ASSETS_COUNT	6

# define PATH_FLOOR			"ASSETS_FOLDER/floor.xpm"
# define PATH_WALL			"ASSETS_FOLDER/wall.xpm"
# define PATH_PLAYER		"ASSETS_FOLDER/player.xpm"
# define PATH_ENEMY			"ASSETS_FOLDER/enemy.xpm"
# define PATH_COLLECTIBLE	"ASSETS_FOLDER/collectible.xpm"
# define PATH_EXIT			"ASSETS_FOLDER/exit.xpm"

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
