/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:07:30 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/05 19:01:18 by rceschel         ###   ########.fr       */
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

static void render_player(t_map *map, int prev_x, int prev_y)
{
	void *player_img;
	void *prev_pos_image;

	prev_pos_image = map->asset[map->grid[prev_x][prev_y]];
	player_img = get_img_w_transparency(
			map->asset[T_PLAYER],
			map->asset[map->grid[map->player.y][map->player.x]],
			ASSETS_SIZE, ASSETS_SIZE,
			CHROMA_KEY);
	render_one(map->data,
			prev_pos_image,
			prev_x, prev_y);
	render_one(map->data,
			player_img,
			map->player.x, map->player.y);
}

static void clone_player(t_player *dest, t_player *src)
{
	dest->x = src->x;
	dest->y = src->y;
	dest->on_exit = src->on_exit;
	dest->moves = src->moves;
	dest->collectibles = src->collectibles;
}

int	move_player(t_map *map, int x, int y)
{
	t_player	new_p;

	clone_player(&new_p, &map->player);
	new_p.x += x;
	new_p.y += y;
	new_p.moves++;
	if (map->grid[new_p.y][new_p.x] == T_WALL)
		return (0);
	if (map->grid[new_p.y][new_p.x] == T_COLLECTIBLE)
		new_p.collectibles++;
	clone_player(&map->player, &new_p);
	render_player(map, map->player.x - x, map->player.y - y);
	if (map->grid[map->player.y][map->player.x] == T_EXIT
		&& map->player.collectibles == map->total_collectibles)
		return (1);
	return (0);
}
