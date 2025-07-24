/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:33:28 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/24 19:09:04 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"
#include "errors.h"
#include "utils.h"
#include <fcntl.h>	
#include <stdbool.h>

// Return the content of the file as a string array.
static char	**extract_map(char *filename, int height)
{
	int		fd;
	int		i;
	char	**grid;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	grid = ft_calloc(height + 1, sizeof(char *));
	i = 0;
	while (i < height)
	{
		grid[i] = get_next_line(fd);
		if (!grid[i])
			return (NULL);
		i++;
	}
	grid[height] = NULL;
	return (grid);
}

// Check if the map is a rectangle, set map width/height
// Width = len(row) - 1; beacuse row has '\n' as last character
static bool	check_measurements(t_map *map, char *filename)
{
	int		fd;
	char	*row;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (PARSE_ERROR);
	row = get_next_line(fd);
	map->width = ft_strlen(row) - 1;
	map->height = 0;
	while (row)
	{
		map->height++;
		free(row);
		row = get_next_line(fd);
		if (row && map->width != ft_strlen(row) - 1)
		{
			close(fd);
			ft_printf("Error in Map Format: ");
			ft_printf("Not every row has the same length\n");
			free(row);
			return (false);
		}
	}
	close(fd);
	if (map->width == map->height)
	{
		ft_printf("Error in Map Format: ");
		ft_printf("Map is a square, need to be a rectangle\n");
		return (false);
	}
	return (true);
}

static void free_map(t_tile **map, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static t_tile **translate_map(char **c_map, int width, int height)
{
	int		i;
	int		j;
	t_tile	**i_map;

	i_map = ft_calloc(height + 1, sizeof(t_tile *));
	i = 0;
	while (i < height)
	{
		i_map[i] = ft_calloc(width, sizeof(t_tile));
		j = 0;
		while (j < width)
		{
			if (c_map[i][j] == C_FLOOR)
				i_map[i][j] = T_FLOOR;
			else if (c_map[i][j] == C_WALL)
				i_map[i][j] = T_WALL;
			else if (c_map[i][j] == C_PLAYER)
				i_map[i][j] = T_PLAYER;
			else if (c_map[i][j] == C_EXIT)
				i_map[i][j] = T_EXIT;
			else if (c_map[i][j] == C_COLLECTIBLE)
				i_map[i][j] = T_COLLECTIBLE;
			else if (c_map[i][j] == C_ENEMY)
				i_map[i][j] = T_ENEMY;
			else if (c_map[i][j] == '\n')
				;
			else
			{
				free_map(i_map, i);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	i_map[height] = NULL;
	return (i_map);
}

t_map	get_map(char *filename)
{
	t_map	map;

	if (!check_measurements(&map, filename))
		exit(MAP_FORMAT_ERROR);
	map.c_grid = extract_map(filename, map.height);
	if (!map.c_grid)
		print_and_exit("Parse Error: Failed in retrieving the map\n",
			PARSE_ERROR);
	map.grid = translate_map(map.c_grid, map.width, map.height);
	if(!map.grid)
	{
		free_grid((void **)map.c_grid);
		print_and_exit("Parse Error: Failed in translating the map\n",
			PARSE_ERROR);
	}
	return (map);
}
