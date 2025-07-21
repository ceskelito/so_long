/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:48:10 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/21 17:08:50 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "datalib.h"
#include "libft.h"
#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdbool.h>

/*typedef struct s_assets
{
	t_data_img	floor;
	t_data_img	wall;
	t_data_img	player;
	t_data_img	exit;
	t_data_img	enemy;
	t_data_img	collectible;
} t_assests;

char *get_path(char *name);
{
	return (ft_strdup(ft_strcat(ft_strcat("assets/", name), ".xpm")));
}

void set_assets(t_assets *a)
{

	a.floor.filename = get_path("floor");
	a.wall.filename = get_path("block");
	a.player.filename = get_path("player");
	a.exit.filename = get_path("exit");
	a.enemy.filename = get_path("enemy");
}*/

void	draw_backround(t_data *data, t_data_img *tile)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i + tile->width <= WINDOW_LENGTH)
	{
		while (j + tile->height <= WINDOW_HEIGTH)
		{
			mlx_put_image_to_window(data->mlx, data->win, tile->img, i, j);
			j += tile->height;
		}
		i += tile->width;
		j = 0;
	}
}

int	render(void *param)
{
	if(param)
		return (0);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

bool check_extension(const char *filename, const char *ext)
{
	if(ft_strcmp(filename + (ft_strlen(filename) - ft_strlen(ext)) , ext) != 0)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_data_img	tile;
	t_map		map;

	if (ac != 2 || ! av[1])
	{
		ft_printf("Arg Error: Invalid number of arguments, please give only the map's file path.\n");
		return (ARG_ERROR);
	}
	if(!check_extension((const char *)av[1], (const char*)".ber"))
	{
		ft_printf("Arg Error: Invalid file extension for the map's file, need to be '.ber'\n");
		return (ARG_ERROR);
	}
	// check for file extension is .ber
	// check_ext(av[1]);
	
	map = get_map(av[1]);
	if(!map.string)
		return(PARSE_ERROR);

	data = data_init(NULL, WINDOW_LENGTH, WINDOW_HEIGTH, "so_long");
	tile.img = mlx_xpm_file_to_image(data.mlx, tile.filename, &(tile.width),
			&(tile.height));
	if(!tile.img)
		return(MLX_ERROR);
	draw_backround(&data, &tile);
	mlx_loop_hook(data.win, &render, NULL);
	mlx_hook(data.win, 17, 0, &close_window, &data);
	mlx_loop(data.mlx);
	close_window(&data);
	return (0);
}
