/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:33:28 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/28 18:43:18 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "libft.h"
#include "map.h"
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

// Function needed to reduce the number of lines in the caller func
static bool	measurements_helper(char *row, t_map *map, int fd)
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

// Check if the map is a rectangle, set map width/height
// Width = len(row) - 1; beacuse row has '\n' as last character
static bool	check_and_set_measurements(t_map *map, char *filename)
{
	char	*row;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	row = get_next_line(fd);
	map->width = ft_strlen(row) - 1;
	map->height = 0;
	if(!measurements_helper(row, map, fd))
		return (false);
	close(fd);
	if (map->width == map->height)
	{
		ft_printf("Error\nMap is a square, need to be a rectangle\n");
		return (false);
	}
	return (true);
}

// Translate the map from char to t_tile matrix (usefull ongoing in the program)
static t_tile	**translate_map(char **c_grid, int width, int height)
{
	int		i;
	int		j;
	t_tile	**tile_grid;

	tile_grid = ft_calloc(height + 1, sizeof(t_tile *));
	i = 0;
	while (i < height)
	{
		tile_grid[i] = ft_calloc(width + 1, sizeof(t_tile));
		j = 0;
		while (j < width)
		{
			if (c_grid[i][j] == C_FLOOR)
				tile_grid[i][j] = T_FLOOR;
			else if (c_grid[i][j] == C_WALL)
				tile_grid[i][j] = T_WALL;
			else if (c_grid[i][j] == C_PLAYER)
				tile_grid[i][j] = T_PLAYER;
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
				return (NULL);
			}
			j++;
			tile_grid[i][width] = T_VOID;
		}
		i++;
	}
	tile_grid[height] = 0;
	return (tile_grid);
}

void			continue_map_checking(t_map *map);

t_map	get_map(char *filename)
{
	t_map	map;

	if (!check_and_set_measurements(&map, filename))
		exit(MAP_FORMAT_ERROR);
	map.c_grid = extract_map(filename, map.height);
	if (!map.c_grid)
		print_and_exit("Error\nFailed in retrieving the map from file\n",
			PARSE_ERROR);
	map.grid = translate_map(map.c_grid, map.width, map.height);
	if (!map.grid)
	{
		free_grid((void **)map.c_grid);
		print_and_exit("Error\nFailed in translating the map from char to t_tile\n",
			PARSE_ERROR);
	}
	continue_map_checking(&map);
	return (map);
}
