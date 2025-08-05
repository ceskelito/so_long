/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   giwt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:09:23 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/05 19:19:11 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_data.h"
#include "colors.h"
#include "so_long.h"

#include <libft.h>

static void img_set_data(t_data_img *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
				&img->line_len, &img->endian);
	img->pixels = (int *)img->addr;
}

// The function assume the two images have the same size
void *get_img_w_transparency(void *foreground, void *background,
			int width, int height, int chroma_key)
{
	int			i;
	int			j;
	int			off;
	t_data_img	front;
	t_data_img	back;

	ft_memset(&front, 0, sizeof(t_data_img));
	front.img = ft_calloc(1, sizeof(t_data_img));
	ft_memcpy(front.img, foreground, sizeof(foreground));
	ft_memset(&back, 0,	sizeof(t_data_img));
	back.img = ft_calloc(1, sizeof(t_data_img));
	ft_memcpy(back.img, background, sizeof(background));
	if (!front.img || !back.img)
		return (NULL);
	img_set_data(front.img);
	img_set_data(back.img);
	if (front.addr || ! back.addr)
		return (NULL);
	i = 0;
	while (i < height)
	{
		j = 0;
		while(j < width)
		{
			off = img_get_offset_4_byte(front.line_len, j, i);
			if(front.pixels[off] == chroma_key)
				front.pixels[off] = back.pixels[off];
			j++;
		}
		i++;
	}
	return (front.img);
}
