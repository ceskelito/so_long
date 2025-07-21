#ifndef MAP_H
# define MAP_h

# define ASSETS_SIZE 128

# define T_FLOOR		'0'
# define T_WALL			'1'
# define T_EXIT			'E'
# define T_ENEMY		'X'
# define T_COLLECTIBLE	'C'
# define T_PLAYER		'P'


typedef struct s_tile
{
	char	*filename;
	void	*img;
	int		width;
	int		height;
	int		type;
	int		x;
	int		y;
} t_tile;

typedef struct s_map
{
	char	*filename;
	char	**string;
	int		width;
	int		height;
} t_map;

t_map	get_map(char *filename);

#endif
