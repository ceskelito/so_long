/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:15:00 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/04 15:45:09 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"
#include <stdlib.h>

#define T_VISITED 99

static void	floodfill(t_grid *g, int x, int y)
{
	if (x < 0 || x >= g->width || y < 0 || y >= g->height)
		return ;
	if (g->grid[y][x] == T_WALL || g->grid[y][x] == T_VISITED
		|| g->grid[y][x] == T_VOID)
		return ;
	g->grid[y][x] = T_VISITED;
	floodfill(g, x + 1, y);
	floodfill(g, x - 1, y);
	floodfill(g, x, y + 1);
	floodfill(g, x, y - 1);
}

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

bool	flood_fill(t_map *map)
{
	int												i;
	t_grid __attribute__	((cleanup(free_grid)))	g;

	ft_memset(&g, 0, sizeof(t_grid));
	g.height = map->height;
	g.width = map->width;
	g.grid = ft_calloc(map->height + 1, sizeof(int *));
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
