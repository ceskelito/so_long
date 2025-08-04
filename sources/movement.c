/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:07:30 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/04 12:18:15 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

static void render_one(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win,
		img, x * ASSETS_SIZE, y * ASSETS_SIZE);
}

int	move_player(t_map *map, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = map->player.x + x;
	new_y = map->player.y + y;
	
	if (map->grid[new_y][new_x] == T_WALL)
		return (0);
	if (map->grid[map->player.y][map->player.x] == T_EXIT)
	{
		if (map->player.collectibles == map->total_collectibles)
			return (1);
		else
			return (0);
	}
	map->player.x = new_x;
	map->player.y = new_y;
	map->player.moves++;
	if (map->grid[map->player.y][map->player.x] == T_COLLECTIBLE)
		map->player.collectibles++;
	map->grid[map->player.y][map->player.x] = T_PLAYER;
	render_one(map->data, map->asset[T_PLAYER], map->player.x, map->player.y);
	render_one(map->data, map->asset[T_FLOOR], map->player.x - x, map->player.y - y);
	return (0);
}
