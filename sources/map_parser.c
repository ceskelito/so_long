/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceskelito <ceskelito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:33:28 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/08 11:31:10 by ceskelito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>

#include "libft.h"
#include "so_long.h"
#include "utils.h"

// Check if the map is a rectangle, set map width/height
// Width = len(row) - 1; beacuse row has '\n' as last character
static bool	check_and_set_measurements(t_map *map, char *filename)
{
	char	*row;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n%s named \"%s\"\n", strerror(errno), filename);
		exit(errno);
	}
	row = get_next_line(fd);
	map->width = ft_strlen(row) - 1;
	map->height = 0;
	if (!measurements_helper(row, map, fd))
		return (false);
	close(fd);
	if (map->width == map->height)
	{
		ft_printf("Error\nMap is a square, need to be a rectangle\n");
		return (false);
	}
	return (true);
}

// Return the content of the file as a string array.
static char	**extract_map(char *filename, int height)
{
	int		fd;
	int		i;
	char	**grid;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n%s named \"%s\"\n", strerror(errno), filename);
		exit(errno);
	}
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

// Translate the map from char to t_tile (enum) matrix.
// This will usefull ongoing in the program
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
			if (!translate_helper(c_grid, tile_grid, i, j))
				return (NULL);
			j++;
			tile_grid[i][width] = T_VOID;
		}
		i++;
	}
	tile_grid[height] = 0;
	return (tile_grid);
}

// Return the map struct
t_map	get_map(char *filename)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	if (!check_and_set_measurements(&map, filename))
		exit(MAP_FORMAT_ERROR);
	if (map.width * ASSETS_SIZE > WINDOW_WIDTH || map.height
		* ASSETS_SIZE > WINDOW_HEIGHT)
	{
		ft_printf("Error\nMap is too big, max size is %ix%i\n", WINDOW_WIDTH
			/ ASSETS_SIZE, WINDOW_HEIGHT / ASSETS_SIZE);
		exit(MAP_FORMAT_ERROR);
	}
	map.c_grid = extract_map(filename, map.height);
	map.grid = translate_map(map.c_grid, map.width, map.height);
	if (!map.grid)
	{
		free_grid((void **)map.c_grid);
		print_and_exit("Error\nFailed in translating the map to t_tile\n",
			PARSE_ERROR);
	}
	continue_map_checking(&map);
	return (map);
}
