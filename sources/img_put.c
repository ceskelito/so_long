#include "mlx_data.h"
#include "colors.h"
#include "so_long.h"

#include <libft.h>

static int	get_image_square_size(void *img_ptr)
{
    int	size;
    int	bits_per_pixel;
    int	line_length;

    mlx_get_data_addr(img_ptr, &bits_per_pixel, &line_length, NULL);
    size = line_length / (bits_per_pixel / 8);
    return (size);
}

static void	set_image_transparency(void *front_ptr, void *back_ptr)
{
	t_data_img	front;
	t_data_img	back;
	int			index[2];
	int			off;
	
	
	front.pixels = (int*)mlx_get_data_addr(front_ptr, NULL, &front.line_len, NULL);
    back.pixels = (int *)mlx_get_data_addr(back_ptr, NULL, NULL, NULL);
	index[0] = 0;
	while(index[0] < ASSETS_SIZE)
	{
		index[1] = 0;
		while (index[1] < ASSETS_SIZE)
		{
			//off = img_get_offset_4_byte(front.line_len, index[1], index[0]);
			off = (index[0] * (front.line_len / 4) + index[1]);
			if ((front.pixels[off] & 0x00FFFFFF) == 0)
				front.pixels[off] = back.pixels[off];
			index[1]++;
		}
		index[0]++;
	}
}



void	img_put_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, void *background_ptr, int x, int y)
{
	t_data_img	new;
	t_data_img	img;
	int			size;
	int			i;

	if(!background_ptr)
	{
		mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
		return;
	}
	img.img = img_ptr;
	size = get_image_square_size(img_ptr);
	new.img = mlx_new_image(mlx_ptr, size, size);
	if(!new.img)
		return;
	img.pixels = (int*)mlx_get_data_addr(img_ptr, NULL, &img.line_len, NULL);
    new.pixels = (int*)mlx_get_data_addr(new.img, NULL, NULL, NULL);
    i = 0;
    while (i < (size * size))
    {
        new.pixels[i] = img.pixels[i];
        i++;
    }
	set_image_transparency(new.img, background_ptr);
	mlx_put_image_to_window(mlx_ptr, win_ptr, new.img, x, y);
}
