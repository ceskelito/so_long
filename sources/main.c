/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceskelito <ceskelito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:48:10 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/08 11:48:24 by ceskelito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <stdbool.h>
#include <stdlib.h>

#include "so_long.h"
#include "libft.h"
#include "mlx_data.h"
#include "colors.h"
#include "mlx.h"

void	render_all(t_data *data, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->width)
	{
		while (j < map->height)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				map->asset[map->grid[j][i]], i * ASSETS_SIZE, j * ASSETS_SIZE);
			j++;
		}
		i++;
		j = 0;
	}
}

int	close_window(t_map *map)
{
	free_grid((void **)map->c_grid);
	free_grid((void **)map->grid);
	free_asset(map->data->mlx, map->asset);
	mlx_destroy_window(map->data->mlx, map->data->win);
	mlx_destroy_display(map->data->mlx);
	free(map->data->mlx);
	exit(0);
}

int	handle_keypress(int keycode, t_map *map)
{
	int	win;

	if (keycode == XK_Escape)
		close_window(map);
	else if (keycode == XK_Left || keycode == XK_a)
		win = move_player(map, -1, 0);
	else if (keycode == XK_Right || keycode == XK_d)
		win = move_player(map, 1, 0);
	else if (keycode == XK_Up || keycode == XK_w)
		win = move_player(map, 0, -1);
	else if (keycode == XK_Down || keycode == XK_s)
		win = move_player(map, 0, 1);
	if (win)
	{
		ft_printf("Moves count: %i\n", map->player.moves + 1);
		ft_printf("Error\nToo skilled player has won the game\n");
		close_window(map);
	}
	return (0);
}

static void	check_args(int ac, char **av)
{
	if (ac != 2 || !av[1])
	{
		ft_printf("Error\nInvalid number of arguments: ");
		print_and_exit("give only the map's file path.\n", ARG_ERROR);
	}
	if (ft_strcmp(av[1] + (ft_strlen(av[1]) - ft_strlen(".ber")), ".ber") != 0)
	{
		ft_printf("Error\nInvalid file extension for the map's file: ");
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
	if (!data.mlx)
		print_and_exit("Error\nFailed to create mlx instance\n", MLX_ERROR);
	map.data = &data;
	if (!set_assets(data.mlx, map.asset))
		close_window(&map);
	render_all(&data, &map);
	mlx_loop_hook(data.win, NULL, NULL);
	mlx_hook(data.win, 17, 0, &close_window, &map);
	mlx_hook(data.win, 2, 1L << 0, &handle_keypress, &map);
	mlx_loop(data.mlx);
	close_window(&map);
	return (0);
}
