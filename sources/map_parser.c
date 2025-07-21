#include "libft.h"
#include "map.h"
#include <fcntl.h>	

// Return the content of the file as a string array.
static char **extract_map(char *filename, int width, int height)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(filename, O_RDONLY);
	if(fd < 0)
		return(NULL);
	map = ft_calloc(height, sizeof(char *));
	while (i < height)
	{
		map[i] = ft_calloc(width, sizeof(char));
		map[i] = get_next_line(fd);
		if (!map[i])
			return (NULL);
		i++;
	}
	return (map);
}

// Check if the map is a rectangle, set map width/height
static int	check_measurements(t_map *map)
{
	int		fd;
	char	*row;

	fd = open(map->filename, O_RDONLY);
	if(fd < 0)
		return (PARSE_ERROR);
	row = get_next_line(fd);
	map->width = ft_strlen(row);
	map->height = 0;
	while(row)
	{
		map->height++;
		free(row);
		row = get_next_line(fd);
		if (row && map->width != ft_strlen(row))
		{
			close(fd);
			ft_printf("Parse Error: Not every row has the same length\n");
			return (PARSE_ERROR);
		}
	}
	close(fd);
	return (0);
}

t_map	get_map(char *filename)
{
	//int		fd;
	//char	*row;
	t_map	map;

	map.filename = ft_strdup(filename);
	check_measurements(&map);
	map.string = extract_map(map.filename, map.width, map.height);
	return (map);
}



