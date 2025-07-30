#include "mlx.h"
#include "mlx_data.h"
#include <stdlib.h>


/*	*** TO-DO ***

 * Free the structs at exit
 
*/

//void	img_put_on_window()

int	img_get_offset_4_byte(int line_length, int x, int y)
{
	return (y * (line_length / 4) + x);
}

int img_get_offset(int line_length, int bits_per_pixel, int x, int y)
{
	return (y * line_length + x * (bits_per_pixel / 8));
}

void img_put_pixel(t_data_img *img, int x, int y, int color)
{
	char	*dest;

	if(!img || !img->addr)
		exit(MLX_ERROR);
	dest = img->addr + img_get_offset(img, x, y);
	if(!dest)
		exit(MLX_ERROR);
	*(unsigned int *)dest = color;
}

void img_create(void* mlx, t_data_img *img, int img_width, int img_height)
{
	if(!mlx || !img)
		exit(MLX_ERROR);
	img->img = mlx_new_image(mlx, img_width, img_height);
	if(!img->img)
		exit(MLX_ERROR);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
										&img->endian);
	if(!img->addr)
		exit(MLX_ERROR);
	img->width = img_width;
	img->height = img_height;
}

void img_set_background(t_data_img *img, int color)
{
	int x;
	int y;

	x = 0;
	y = 0;

	for(y = 0; y < img->height; y++)
		for(x = 0; x < img->width; x++)
			img_put_pixel(img, x, y, color);
}

