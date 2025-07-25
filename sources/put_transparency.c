/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_transparency.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:06:02 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/25 19:45:42 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"
#include "colors.h"
#include "so_long.h"

#include <libft.h>

void	*img_add_transparency(void *start_img, void *start_subst)
{
	int			i;
	int			j;
	unsigned int			off;
	t_data_img	img;
	t_data_img	subst;

	subst.img = start_subst;
	img.img = start_img;
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len,
			&img.endian);
	subst.addr = mlx_get_data_addr(subst.img, &subst.bpp, &subst.line_len,
			&subst.endian);
	i = 0;
	while (i < ASSETS_SIZE)
	{
		j = 0;
		while (j < ASSETS_SIZE)
		{
			off = img_get_offset(&img, i, j);
			if (1 /*clr_get_t(img.addr[off])*/)
			{
				//ft_memcpy(img.addr + off, subst.addr + off, 1);
				//img.addr[off % 128] = subst.addr[off % 128];
				img_put_pixel(&img, i, j, (off + COLOR_RED) * 2);
				//ft_printf("addr: %u\ncolor: %u\n\n", img.addr[off], COLOR_BLUE);
				//ft_printf("offset: %i\nimg addr: %u\nsub addr: %u\n\n", off, img.addr[off], subst.addr[off]);
				//ft_printf("copied  ");
			}
			j++;
			//ft_printf("i: %i\tj: %i\n", i, j);
		}
		i++;
	}
	return (img.img);
}

