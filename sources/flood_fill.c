/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:15:00 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/04 11:44:21 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
#include <stdlib.h>

// I'll use the T_PLAYER value to sign the checked tiles 
static bool floodfill(t_tile **grid, int x, int y)
{
    if (grid[y][x] == T_WALL)
        return (false);
	else if (grid[y][x] == T_PLAYER)
		return (false);
	else if (grid[y][x] == T_EXIT)
        return (true);
    grid[y][x] = T_PLAYER;
    return (floodfill(grid, x + 1, y) ||
        floodfill(grid, x - 1, y) ||
        floodfill(grid, x, y + 1) ||
        floodfill(grid, x, y - 1));
}

static void	free_grid(t_tile ***grid)
{
	int	i;

	i = 0;
	while((*grid)[i])
	{
		free((*grid)[i]);
		i++;
	}
	free(*grid);
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
	t_tile __attribute__	((cleanup(free_grid)))	**grid;

	grid = ft_calloc(map->height + 1, sizeof(t_tile *));
	i = 0;
	while(i < map->height)
	{
		grid[i] = ft_calloc(map->width + 1, sizeof(t_tile));
		if(!grid[i])
			return (false);
		ft_memcpy(grid[i], map->grid[i], map->width * sizeof(t_tile));
		grid[i][map->width] = T_VOID;
		i++;
	}
	grid[map->height] = T_VOID;
	grid[map->player.y][map->player.x] = T_FLOOR;
	return (floodfill(grid, map->player.x, map->player.y));
}
