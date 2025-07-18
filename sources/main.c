/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:48:10 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/18 19:08:05 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "datalib.h"
#include "headers/libft.h"
#include "mlx.h"
#include <stdlib.h>

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
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	main(void)
{
	t_data		data;
	t_data_img	tile;

	tile.filename = ft_strdup("./assets/block.xpm");
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
