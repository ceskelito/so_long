/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:32:39 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/24 19:04:57 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>
#include <stdbool.h>
#include "assets.h"
#include "mlx.h"
#include "libft.h"
#include "utils.h"

bool	set_assets(void *mlx_ptr, void *asset[])
{
	int		w;
	int		h;

	asset[ASSETS_COUNT] = NULL;
	asset[T_FLOOR] = mlx_xpm_file_to_image(mlx_ptr, PATH_FLOOR, &w, &h);
	if (w != ASSETS_SIZE || h != ASSETS_SIZE || !asset[T_FLOOR])
		return (free_asset(mlx_ptr, asset));
	asset[T_WALL] = mlx_xpm_file_to_image(mlx_ptr, PATH_WALL, &w, &h);
	if (w != ASSETS_SIZE || h != ASSETS_SIZE || !asset[T_WALL])
		return (free_asset(mlx_ptr, asset));
	asset[T_EXIT] = mlx_xpm_file_to_image(mlx_ptr, PATH_EXIT, &w, &h);
	if (w != ASSETS_SIZE || h != ASSETS_SIZE || !asset[T_EXIT])
		return (free_asset(mlx_ptr, asset));
	asset[T_PLAYER] = mlx_xpm_file_to_image(mlx_ptr, PATH_PLAYER, &w, &h);
	if (w != ASSETS_SIZE || h != ASSETS_SIZE || !asset[T_PLAYER])
		return (free_asset(mlx_ptr, asset));
	asset[T_ENEMY] = mlx_xpm_file_to_image(mlx_ptr, PATH_ENEMY, &w, &h);
	if (w != ASSETS_SIZE || h != ASSETS_SIZE || !asset[T_ENEMY])
		return (free_asset(mlx_ptr, asset));
	asset[T_COLLECTIBLE] = mlx_xpm_file_to_image(mlx_ptr, PATH_COLLECTIBLE,
			&w, &h);
	if (w != ASSETS_SIZE || h != ASSETS_SIZE || !asset[T_COLLECTIBLE])
		return (free_asset(mlx_ptr, asset));
	return (true);
}

