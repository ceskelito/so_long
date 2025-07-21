#ifndef MAP_H
# define MAP_h

# define ASSETS_SIZE 128

# define T_FLOOR		0
# define T_WALL			1
# define T_EXIT			2
# define T_ENEMY		3
# define T_COLLECTIBLE	4
# define T_PLAYER		5


typedef struct s_tile
{
	int	type;
	int	x;
	int	y;
} t_tile;

typedef struct s_map
{
	char	*filename;
	char	**string;
	t_tile	**tile;
	int		width;
	int		height;
} t_map;

t_map	get_map(char *filename);

#endif
