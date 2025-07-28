/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:23:43 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/28 17:46:21 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"
#include "errors.h"
#include "utils.h"
#include <fcntl.h>	
#include <stdbool.h>

static bool check_symbols_count(t_tile **grid)
{
	int	i;
	int	j;
	int	count[ASSETS_COUNT];

	i = 0;
	while(i < ASSETS_COUNT)
	{
		count[i] = 0;
		i++;
	}

	i = 0;
	while(grid[i])
	{
		j = 0;
		while(grid[i][j])
		{
			count[grid[i][j]]++;
			j++;
		}
		i++;
	}
	if(count[T_PLAYER] != 1 || count[T_EXIT] != 1 || count[T_COLLECTIBLE] < 1)
		return (false);
	return (true);
}

bool check_wall_enclosure(t_map *map) {
    int i = 0;

    while (i < map->width)
	{
        if (map->grid[0][i] != T_WALL)
			return (false);
        i++;
    }

    i = 0;
    while (i < map->width - 1)
	{
        if (map->grid[map->height - 1][i] != T_WALL)
			return (false);
        i++;
    }

    i = 1;
    while (i < map->height - 1)
	{
        if (map->grid[i][0] != T_WALL)
			return (false);
        i++;
    }

    i = 1;
    while (i < map->height - 1)
	{
        if (map->grid[i][map->width - 1] != T_WALL)
			return (false);
        i++;
    }

    return (true);
}

void	continue_map_checking(t_map *map)
{
	if(!check_symbols_count(map->grid))
	{
		free_grid((void**)map->c_grid);
		free_grid((void**)map->grid);
		print_and_exit("Error\nDuplicated or missing symbols in the map\n",
			PARSE_ERROR);
	}
	if(!check_wall_enclosure(map))
	{
		free_grid((void**)map->c_grid);
		free_grid((void**)map->grid);
		print_and_exit("Error\nWalls dont't close the map\n",
			PARSE_ERROR);
	}
}

