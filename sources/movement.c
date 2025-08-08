/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceskelito <ceskelito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:07:30 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/08 12:16:06 by ceskelito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include "colors.h"

static void	render_one(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x * ASSETS_SIZE, y
		* ASSETS_SIZE);
}

static t_tile	get_tile(int x, int y)
{
	if (x == 1)
		return (T_PLAYER_RIGHT);
	else if (x == -1)
		return (T_PLAYER_LEFT);
	else if (y == 1)
		return (T_PLAYER_DOWN);
	else if (y == -1)
		return (T_PLAYER_UP);
	return (T_PLAYER_DOWN);
}

static void	update_player(t_player *player, int x, int y)
{
	player->x += x;
	player->y += y;
	player->moves++;
	ft_printf("Moves count: %i\n", player->moves);
}

int	evaluate_exit(t_map *map, int nx, int ny)
{
	if (map->player.collectibles == map->total_collectibles)
		return (1);
	mlx_string_put(map->data->mlx, map->data->win,
		nx * 128, ny * 128, COLOR_WHITE,
		"I can't go to sleep until I've collected all the matches");
	return (0);
}

int	move_player(t_map *map, int x, int y)
{
	int	new_x;
	int	new_y;
	int	old_x;
	int	old_y;

	old_x = map->player.x;
	old_y = map->player.y;
	new_x = map->player.x + x;
	new_y = map->player.y + y;
	render_one(map->data, map->asset[get_tile(x, y)], old_x, old_y);
	if (map->grid[new_y][new_x] == T_EXIT)
		return (evaluate_exit(map, new_x, new_y));
	if (map->grid[new_y][new_x] == T_WALL)
		return (0);
	if (map->grid[new_y][new_x] == T_COLLECTIBLE)
	{
		map->player.collectibles++;
		map->grid[new_y][new_x] = T_FLOOR;
	}
	render_one(map->data, map->asset[get_tile(x, y)], new_x, new_y);
	render_one(map->data, map->asset[T_FLOOR], old_x, old_y);
	update_player(&map->player, x, y);
	return (0);
}
