/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:33:28 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/22 15:44:41 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"
#include "errors.h"
#include <fcntl.h>	
#include <stdbool.h>

// Return the content of the file as a string array.
static char	**extract_map(char *filename, int height)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = ft_calloc(height, sizeof(char *));
	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (NULL);
		i++;
	}
	return (map);
}

// Check if the map is a rectangle, set map width/height
static bool	check_measurements(t_map *map)
{
	int		fd;
	char	*row;

	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		return (PARSE_ERROR);
	row = get_next_line(fd);
	map->width = ft_strlen(row);
	map->height = 0;
	while (row)
	{
		map->height++;
		free(row);
		row = get_next_line(fd);
		if (row && map->width != ft_strlen(row))
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

static int	**translate_map(char **c_map, int width, int height)
{
	int	i;
	int j;
	int	**i_map;

	i_map = ft_calloc(width, sizeof(int *));
	i = 0;
	while (i < height)
	{
		i_map[i] = ft_calloc(width, sizeof(int));
		j = 0;
		while (j < width)
		{
			if (!c_map[0][0])
				return(i_map);
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
			else if (c_map[i][j] == C_EXIT)
				i_map[i][j] = T_EXIT;
			else if (c_map[i][j] == C_ENEMY)
				i_map[i][j] = T_ENEMY;
			else
				return (NULL);
			j++;
		}
		i++;
	}
	return (i_map);
}

t_map	get_map(char *filename)
{
	t_map	map;

	map.filename = ft_strdup(filename);
	if (!check_measurements(&map))
		exit(MAP_FORMAT_ERROR);
	map.c_grid = extract_map(map.filename, map.height);
	if (!map.c_grid)
		return (map);
	map.grid = (t_tile **)translate_map(map.c_grid, map.width, map.height);
	return (map);
}
