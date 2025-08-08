/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceskelito <ceskelito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:15:00 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/08 11:52:09 by ceskelito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "map.h"

#define T_VISITED 99

// I assume that the exit acts like a wall,
// but anyway i need to mark it as visited
// in order to check if is possible reach it.
static void	floodfill(t_grid *g, int x, int y)
{
	int	*actual;

	actual = &g->grid[y][x];
	if (x < 0 || x >= g->width || y < 0 || y >= g->height)
		return ;
	if (*actual == T_WALL || *actual == T_VISITED || *actual == T_VOID)
		return ;
	*actual = T_VISITED;
	if (*actual == T_EXIT)
		return ;
	floodfill(g, x + 1, y);
	floodfill(g, x - 1, y);
	floodfill(g, x, y + 1);
	floodfill(g, x, y - 1);
}

// Once i filled the map whit T_VISITED,
// if are still present collectibles or the exit tile,
// it means they are not reachable, and the game will not start.
static bool	map_is_completable(t_grid *g, int x, int y)
{
	int	i;
	int	j;

	floodfill(g, x, y);
	i = 0;
	while (i < g->height)
	{
		j = 0;
		while (j < g->width)
		{
			if (g->grid[i][j] == T_EXIT || g->grid[i][j] == T_COLLECTIBLE)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static void	free_grid(t_grid *g)
{
	int	i;

	i = 0;
	while (i < g->height)
	{
		free(g->grid[i]);
		i++;
	}
	free(g->grid);
}

// I'll going to copy the map in order to modify it,
// without repercussions.
bool	flood_fill(t_map *map)
{
	int												i;
	t_grid __attribute__	((cleanup(free_grid)))	g;

	ft_memset(&g, 0, sizeof(t_grid));
	g.height = map->height;
	g.width = map->width;
	g.grid = ft_calloc(map->height + 1, sizeof(t_tile *));
	if (!g.grid)
		return (false);
	i = 0;
	while (i < map->height)
	{
		g.grid[i] = ft_calloc(map->width + 1, sizeof(int));
		if (!g.grid[i])
			return (false);
		ft_memcpy(g.grid[i], map->grid[i], map->width * sizeof(t_tile));
		g.grid[i][map->width] = (int)T_VOID;
		i++;
	}
	g.grid[map->height] = NULL;
	return (map_is_completable(&g, map->player.x, map->player.y));
}
