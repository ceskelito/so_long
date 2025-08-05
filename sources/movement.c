/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:07:30 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/05 12:20:49 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

static void	render_one(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x * ASSETS_SIZE, y
		* ASSETS_SIZE);
}

int	move_player(t_map *map, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = map->player.x + x;
	new_y = map->player.y + y;
	if (map->grid[new_y][new_x] == T_WALL)
		return (0);
	if (map->grid[map->player.y][map->player.x] == T_EXIT
		&& map->player.collectibles == map->total_collectibles)
		return (1);
	if (map->grid[new_y][new_x] == T_COLLECTIBLE)
		map->player.collectibles++;
	map->player.x += x;
	map->player.y += y;
	map->player.moves++;
	render_one(map->data, map->asset[T_PLAYER], map->player.x, map->player.y);
	render_one(map->data, map->asset[T_FLOOR], map->player.x - x, map->player.y
		- y);
	if (map->grid[map->player.y - y][map->player.x - x] == T_EXIT)
		render_one(map->data, map->asset[T_EXIT], map->player.x - x,
			map->player.y - y);
	return (0);
}
