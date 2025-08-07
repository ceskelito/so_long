/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceskelito <ceskelito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:23:43 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/07 18:38:40 by ceskelito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "errors.h"
#include "map.h"
#include "utils.h"
#include "libft.h"

void	set_player_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == T_PLAYER_STD)
			{
				map->player.x = j;
				map->player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

// Check the presece of Exit, Player and Collectibles (and the quantity)
static bool	check_symbols_count(t_tile **grid, int *total_collectibles)
{
	int	i;
	int	j;
	int	count[ASSETS_COUNT];

	i = 0;
	while (i < ASSETS_COUNT)
		count[i++] = 0;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			count[grid[i][j]]++;
			j++;
		}
		i++;
	}
	if (count[T_PLAYER_STD] != 1 || count[T_EXIT] != 1
		|| count[T_COLLECTIBLE] < 1)
		return (false);
	*total_collectibles = count[T_COLLECTIBLE];
	return (true);
}

bool	check_wall_enclosure(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
		if (map->grid[0][i++] != T_WALL)
			return (false);
	i = 0;
	while (i < map->width)
		if (map->grid[map->height - 1][i++] != T_WALL)
			return (false);
	i = 1;
	while (i < map->height - 1)
		if (map->grid[i++][0] != T_WALL)
			return (false);
	i = 1;
	while (i < map->height - 1)
		if (map->grid[i++][map->width - 1] != T_WALL)
			return (false);
	return (true);
}

void	continue_map_checking(t_map *map)
{
	if (!check_symbols_count(map->grid, &map->total_collectibles))
	{
		free_grid((void **)map->c_grid);
		free_grid((void **)map->grid);
		print_and_exit("Error\nDuplicated or missing symbols in the map\n",
			PARSE_ERROR);
	}
	if (!check_wall_enclosure(map))
	{
		free_grid((void **)map->c_grid);
		free_grid((void **)map->grid);
		print_and_exit("Error\nWalls don't close the map\n", PARSE_ERROR);
	}
	set_player_position(map);
	if (!flood_fill(map))
	{
		free_grid((void **)map->c_grid);
		free_grid((void **)map->grid);
		print_and_exit("Error\nNo path in the map leads to the exit\n",
			PARSE_ERROR);
	}
}
