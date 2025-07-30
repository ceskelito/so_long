#include "mlx_data.h"
#include "colors.h"
#include "so_long.h"

#include <libft.h>

void	img_add_transparency(void *front_ptr, void *back_ptr)
{
	t_data_img	front;
	t_data_img	back;
	int			*front_pixels;
	int			*back_pixels;
	int			off;
	int			i;
	int			j;

	front.img = front_ptr;
	front.addr = mlx_get_data_addr(front.img, &front.bpp, &front.line_len,
			&front.endian);
	back.img = back_ptr;
	back.addr = mlx_get_data_addr(back.img, &back.bpp, &back.line_len,
			&back.endian);
    front_pixels = (int *)front.addr;
    back_pixels = (int *)back.addr;
	i = 0;
	while(i < ASSETS_SIZE)
	{
		j = 0;
		while (j < ASSETS_SIZE)
		{
			off = i * (front.line_len / 4) + j;
			//off = img_get_offset(&front, i, j);
			//ft_printf("%u\n", (unsigned int)front.addr[off]);
			//ft_printf("Pixel [%d,%d]: 0x%08X\n", i, j, front_pixels[off]);
			if ((front_pixels[off] & 0x00FFFFFF) == 0)
				front_pixels[off] = back_pixels[off];
			j++;
		}
		i++;
	}
}

