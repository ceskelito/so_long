/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:15:00 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/04 13:16:47 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
#include <stdlib.h>

typedef struct s_grid
{
	t_tile	**grid;
	int		width;
	int		height;

} t_grid;

// I'll use the T_PLAYER value to sign the checked tiles 
static bool floodfill(t_grid *g, int x, int y)
{
	if (x < 0 || x >= g->width || y < 0 || y >= g->height)
		return (false);
    if (g->grid[y][x] == T_WALL)
        return (false);
	else if (g->grid[y][x] == T_PLAYER)
		return (false);
	else if (g->grid[y][x] == T_EXIT)
        return (true);
    g->grid[y][x] = T_PLAYER;
    return (floodfill(g, x + 1, y) ||
        floodfill(g, x - 1, y) ||
        floodfill(g, x, y + 1) ||
        floodfill(g, x, y - 1));
}

static void	free_grid(t_grid *g)
{
	int	i;
	
	i = 0;
	while(i < g->height)
	{
		free(g->grid[i]);
		i++;
	}
	free(g->grid);
}	

//void print_grid(t_tile **grid, int height, int width)
//{
//    for (int y = 0; y < height; y++)
//    {
//        for (int x = 0; x < width; x++)
//        {
//            // Usa un carattere per rappresentare ciascun tipo di tile
//            switch (grid[y][x])
//            {
//                case T_VOID:
//                    ft_printf("  ");  // Spazio vuoto, puoi scegliere un altro simbolo
//                    break;
//                case T_WALL:
//                    ft_printf("X ");  // Parete, rappresentata da "X"
//                    break;
//                case T_PLAYER:
//                    ft_printf("P ");  // Giocatore, rappresentato da "P"
//                    break;
//                case T_EXIT:
//                    ft_printf("E ");  // Uscita, rappresentata da "E"
//                    break;
//                default:
//                    ft_printf(". ");  // Altri tipi di tile (opzionale), rappresentati da "."
//                    break;
//            }
//        }
//        ft_printf("\n");  // A capo alla fine di ogni riga
//    }
//	ft_printf("FINE GRIGGLIA\n");
//}

bool flood_fill(t_map *map)
{
	int												i;
	t_grid __attribute__	((cleanup(free_grid)))	g;

	g.height = map->height;
	g.width = map->width;
	g.grid = ft_calloc(map->height + 1, sizeof(t_tile *));
	i = 0;
	while(i < map->height)
	{
		g.grid[i] = ft_calloc(map->width + 1, sizeof(t_tile));
		if(!g.grid[i])
			return (false);
		ft_memcpy(g.grid[i], map->grid[i], map->width * sizeof(t_tile));
		g.grid[i][map->width] = T_VOID;
		i++;
	}
	g.grid[map->height] = NULL;
	g.grid[map->player.y][map->player.x] = T_FLOOR;
	return (floodfill(&g, map->player.x, map->player.y));
}
