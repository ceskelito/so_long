/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:48:10 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/23 18:36:47 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "datalib.h"
#include "libft.h"
#include "mlx.h"
#include "so_long.h"
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


void	print_and_exit(char *msg, int exit_code)
{
	ft_printf("%s", msg);
	exit(exit_code);
}

void	*img_add_transparency(void *start_img, void *start_subst);

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
			if (map->grid[j][i] == T_PLAYER)
			{
				void *tmp = img_add_transparency(map->asset[T_PLAYER], map->asset[T_FLOOR]);
				mlx_put_image_to_window(data->mlx, data->win, tmp, i * ASSETS_SIZE, j * ASSETS_SIZE);

			}
			else
				mlx_put_image_to_window(data->mlx, data->win,
					map->asset[map->grid[j][i]], i * ASSETS_SIZE,
					j * ASSETS_SIZE);
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

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
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
	void	*mlx_ptr;

	check_args(ac, av);
	map = get_map(av[1]);
	if (!map.c_grid || !map.grid)
		print_and_exit("Parse Error: Failed in retrieving the map\n",
			PARSE_ERROR);
	map.tile_size = ASSETS_SIZE;
	mlx_ptr = mlx_init();
	if (!set_assets(mlx_ptr, map.asset))
		print_and_exit("MLX Error: Failed in retrieving the assets\n",
			MLX_ERROR);
	if (!map.asset)
	{
		free(mlx_ptr);
		print_and_exit("Asset Error: Failed in creating images from assets\n",
			MLX_ERROR);
	}
	data = data_init(mlx_ptr, map.width * ASSETS_SIZE, map.height * ASSETS_SIZE,
			"so_long");
	draw_background(&data, &map);
	mlx_loop_hook(data.win, &render, NULL);
	mlx_hook(data.win, 17, 0, &close_window, &data);
	mlx_loop(data.mlx);
	close_window(&data);
	return (0);
}
