/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:07:30 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/04 11:23:01 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

int	move_player(t_map *map, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = map->player.x + x;
	new_y = map->player.y + y;

	if (map->grid[new_y][new_x] == T_WALL)
		return (0);
	if (map->grid[new_y][new_x] == T_COLLECTIBLE)
		map->player.collectibles++;
	map->player.x = new_x;
	map->player.y = new_y;
	map->player->moves++;
	ft_printf("Moves: %d\n", map->player->moves);
	if (map->grid[new_y][new_x] == T_EXIT)
	{
		map->grid[map->player.y][map->player.x] = T_P_ON_EXIT;
		if(map->player.collectibles == map->total_collectibles)
			return (1);
	}
	map->grid[map->player.y][map->player.x] = T_PLAYER;
	return (0);
}
