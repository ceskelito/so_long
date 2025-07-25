/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceskelito <ceskelito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:48:10 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/26 13:21:09 by ceskelito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "mlx_data.h"
#include "libft.h"
#include "mlx.h"
#include "so_long.h"
#include <X11/keysym.h>
#include <stdbool.h>
#include <stdlib.h>

/*typedef struct s_assets
{
	t_data_img	floor;
	t_data_img	wall;
	t_data_img	player;
	t_data_img	exit;
	t_data_img	enemy;
	t_data_img	collectible;
}			t_assests;

char		*get_path(char *name);
{
	return (ft_strdup(ft_strcat(ft_strcat("assets/", name), ".xpm")));
}

void	set_assets(t_assets *a)
{
	a.floor.filename = get_path("floor");
	a.wall.filename = get_path("block");
	a.player.filename = get_path("player");
	a.exit.filename = get_path("exit");
	a.enemy.filename = get_path("enemy");
}*/

void	draw_background(t_data *data, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->width)
	{
		while (j < map->height)
		{
			//if (map->grid[j][i] == T_PLAYER)
			mlx_put_image_to_window(data->mlx, data->win,
				map->asset[T_PLAYER], i * ASSETS_SIZE, j * ASSETS_SIZE);
			mlx_put_image_to_window(data->mlx, data->win,
				map->asset[map->grid[j][i]], i * ASSETS_SIZE, j * ASSETS_SIZE);
			j++;
		}
		i++;
		j = 0;
	}
}

int	render(void *param)
{
	if (param)
		return (0);
	return (0);
}

void the_last_goodbye_aka_free_all(t_map *map)
{
	free_grid((void **)map->c_grid);
	free_grid((void **)map->grid);
	free_asset(map->data->mlx, map->asset);
}

int	close_window(t_map *map)
{
	the_last_goodbye_aka_free_all(map);
	mlx_destroy_window(map->data->mlx, map->data->win);
	mlx_destroy_display(map->data->mlx);
	free(map->data->mlx);
	exit(0);
}

int handle_keypress(int keycode, t_map *map)
{
	if(keycode == XK_Escape)
		close_window(map);
	return (0);
}

bool	check_extension(const char *filename, const char *ext)
{
	if (ft_strcmp(filename + (ft_strlen(filename) - ft_strlen(ext)), ext) != 0)
		return (false);
	return (true);
}

static void check_args(int ac, char **av)
{
	if (ac != 2 || !av[1])
	{
		ft_printf("Arg Error: Invalid number of arguments, ");
		print_and_exit("give only the map's file path.\n", ARG_ERROR);
	}
	if (!check_extension((const char *)av[1], (const char *)".ber"))
	{

		ft_printf("Arg Error: Invalid file extension for the map's file, ");
		print_and_exit("need to be '.ber'\n", ARG_ERROR);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	check_args(ac, av);
	map = get_map(av[1]);
	data = data_init(NULL, map.width * ASSETS_SIZE, map.height * ASSETS_SIZE,
			"so_long");
	if(!data.mlx)
		print_and_exit("MLX error: Faild to create mlx instance\n",
			MLX_ERROR);
	map.data = &data;
	if (!set_assets(data.mlx, map.asset))
		close_window(&map);
	draw_background(&data, &map);
	mlx_loop_hook(data.win, &render, NULL);
	mlx_hook(data.win, 17, 0, &close_window, &map);
	mlx_hook(data.win, 2, 1L<<0, &handle_keypress, &map);
	mlx_loop(data.mlx);
	close_window(&map);
	
	
	return (0);
}
