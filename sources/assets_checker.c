/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:32:39 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/05 12:17:40 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "assets.h"
#include "utils.h"
#include "libft.h"
#include "mlx.h"

static void	free_path_array(char *path[])
{
	int	i;

	i = 1;
	while (path[i])
	{
		free(path[i]);
		path[i] = NULL;
		i++;
	}
}

static void	init_asset_null(void *asset[])
{
	int	i;

	i = 0;
	while (i <= ASSETS_COUNT)
	{
		asset[i] = NULL;
		i++;
	}
}

static void	set_path_array(char *path[])
{
	path[T_VOID] = NULL;
	path[T_FLOOR] = ft_strdup(PATH_FLOOR);
	path[T_WALL] = ft_strdup(PATH_WALL);
	path[T_EXIT] = ft_strdup(PATH_EXIT);
	path[T_PLAYER_UP] = ft_strdup(PATH_PLAYER_UP);
	path[T_PLAYER_DOWN] = ft_strdup(PATH_PLAYER_DOWN);
	path[T_PLAYER_LEFT] = ft_strdup(PATH_PLAYER_LEFT);
	path[T_PLAYER_RIGHT] = ft_strdup(PATH_PLAYER_RIGHT);
	path[T_ENEMY] = ft_strdup(PATH_ENEMY);
	path[T_COLLECTIBLE] = ft_strdup(PATH_COLLECTIBLE);
	path[ASSETS_COUNT] = NULL;
}

bool	set_assets(void *mlx_ptr, void *asset[])
{
	int		i;
	int		w;
	int		h;
	char	*path[ASSETS_COUNT + 1];

	set_path_array(path);
	init_asset_null(asset);
	i = 1;
	while (i < ASSETS_COUNT)
	{
		asset[i] = mlx_xpm_file_to_image(mlx_ptr, path[i], &w, &h);
		if (w != ASSETS_SIZE || h != ASSETS_SIZE || !asset[i])
		{
			ft_printf("Error\nFailed in retrieving the assets n. %i\n", i);
			free_path_array(path);
			return (false);
		}
		i++;
	}
	free_path_array(path);
	return (true);
}
