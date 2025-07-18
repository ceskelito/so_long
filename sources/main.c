#include "mlx.h"
#include "datalib.h"
#include "colors.h"
#include "libft.h"

#include <stdlib.h>

void draw_backround(t_data *data, t_data_img *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i + tile.width < WINDOW_LENGTH)
	{	
		while(j + tile.heigth < WINDOW_HEIGTH)
		{
			mlx_put_image_to_window(data->mlx, data->win, img->img, i, j);
			j += tile.heigth;
		}
		i += tile.width;
	}
}

int render(void *param)
{
	return (0);
}

int close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int main(void)
{
	t_data		data;
	t_data_img	tile;
	
	tile.filename = ft_strdup("assets/tile.xpm");
	data = data_init(NULL, 1920, 1080, "so_long");
	tile.img = mlx_xpm_file_to_image(data.mlx, tile.filename,
								&(tile.width), &(tile.heigth));
	draw_backround(&data, &tile);
	
	mlx_loop_hook(data.win, &render, NULL);
	mlx_hook(data.win, 17, 0, &close_window, &data);

	mlx_loop(data.mlx);
	close_window(&data);
	return (0);
}
