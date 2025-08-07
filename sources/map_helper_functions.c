/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceskelito <ceskelito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:30:22 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/07 18:38:40 by ceskelito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "libft.h"
#include "so_long.h"
#include "utils.h"

// Abbreviate the translate_map function
bool	translate_helper(char **c_grid, t_tile **tile_grid, int i, int j)
{
	if (c_grid[i][j] == C_FLOOR)
		tile_grid[i][j] = T_FLOOR;
	else if (c_grid[i][j] == C_WALL)
		tile_grid[i][j] = T_WALL;
	else if (c_grid[i][j] == C_PLAYER)
		tile_grid[i][j] = T_PLAYER_STD;
	else if (c_grid[i][j] == C_EXIT)
		tile_grid[i][j] = T_EXIT;
	else if (c_grid[i][j] == C_COLLECTIBLE)
		tile_grid[i][j] = T_COLLECTIBLE;
	else if (c_grid[i][j] == C_ENEMY)
		tile_grid[i][j] = T_ENEMY;
	else if (c_grid[i][j] == '\n')
		;
	else
	{
		tile_grid[i] = NULL;
		free_grid((void **)tile_grid);
		return (false);
	}
	return (true);
}

// Function needed to reduce the number of lines in the caller func
bool	measurements_helper(char *row, t_map *map, int fd)
{
	while (row)
	{
		map->height++;
		free(row);
		row = get_next_line(fd);
		if (row && map->width != ft_strlen(row) - 1)
		{
			close(fd);
			ft_printf("Error\nNot every row of the map has the same length\n");
			free(row);
			return (false);
		}
	}
	return (true);
}
