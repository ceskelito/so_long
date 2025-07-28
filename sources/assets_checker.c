/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:32:39 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/28 15:24:46 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>
#include <stdbool.h>
#include "assets.h"
#include "mlx.h"
#include "libft.h"
#include "utils.h"

static void free_path_array(char *path[])
{
	int i;

	i = 0;
	while(path[i])
	{
		free(path[i]);
		path[i] = NULL;
		i++;
	}

}

static void init_asset_null(void *asset[])
{
	int	i;

	i = 0;
	while(i <= ASSETS_COUNT)
	{
		asset[i] = NULL;
		i++;
	}
}

bool	set_assets(void *mlx_ptr, void *asset[])
{
	int		i;
	int		w;
	int		h;
	char	*path[ASSETS_COUNT + 1];

	path[T_FLOOR] = ft_strdup(PATH_FLOOR);
	path[T_WALL] = ft_strdup(PATH_WALL);
	path[T_EXIT] = ft_strdup(PATH_EXIT);
	path[T_PLAYER] = ft_strdup(PATH_PLAYER);
	path[T_ENEMY] = ft_strdup(PATH_ENEMY);
	path[T_COLLECTIBLE] = ft_strdup(PATH_COLLECTIBLE);
	path[ASSETS_COUNT] = NULL;

	init_asset_null(asset);
	i = 0;
	while(i < ASSETS_COUNT)
	{
		asset[i] = mlx_xpm_file_to_image(mlx_ptr, path[i], &w, &h);
		if (w != ASSETS_SIZE || h != ASSETS_SIZE || !asset[i])
		{
			ft_printf("MLX Error: Failed in retrieving the assets\n");
			free_path_array(path);
			return (false);
		}
		i++;
	}
	free_path_array(path);
return (true);
/*
	init_asset_null(asset);
	w = 0;
	h = 0;
	while(true)
	{
		asset[T_FLOOR] = mlx_xpm_file_to_image(mlx_ptr, PATH_FLOOR, &w, &h);
		if (w != ASSETS_SIZE || h != ASSETS_SIZE || !asset[T_FLOOR])
			break;
		asset[T_WALL] = mlx_xpm_file_to_image(mlx_ptr, PATH_WALL, &w, &h);
		if (w != ASSETS_SIZE || h != ASSETS_SIZE || !asset[T_WALL])
			break;
		asset[T_EXIT] = mlx_xpm_file_to_image(mlx_ptr, PATH_EXIT, &w, &h);
		if (w != ASSETS_SIZE || h != ASSETS_SIZE || !asset[T_EXIT])
			break;
		asset[T_PLAYER] = mlx_xpm_file_to_image(mlx_ptr, PATH_PLAYER, &w, &h);
		if (w != ASSETS_SIZE || h != ASSETS_SIZE || !asset[T_PLAYER])
			break;
		asset[T_ENEMY] = mlx_xpm_file_to_image(mlx_ptr, PATH_ENEMY, &w, &h);
		if (w != ASSETS_SIZE || h != ASSETS_SIZE || !asset[T_ENEMY])
			break;
		asset[T_COLLECTIBLE] = mlx_xpm_file_to_image(mlx_ptr, PATH_COLLECTIBLE,
				&w, &h);
		if (w != ASSETS_SIZE || h != ASSETS_SIZE || !asset[T_COLLECTIBLE])
			break;
		return (true);	
	}

	ft_printf("MLX Error: Failed in retrieving the assets\n");
	free_asset(mlx_ptr, asset);
	return (false);
*/
}

