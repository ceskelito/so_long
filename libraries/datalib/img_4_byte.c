/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_4_byte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:07:40 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/05 16:11:53 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_data.h"
#include "mlx.h"
#include "mlx_data.h"
#include <stdlib.h>

#ifndef MLX_ERROR
# define MLX_ERROR 1
#endif

int	img_get_offset_4_byte(int line_length, int x, int y)
{
	return (y * (line_length / 4) + x);
}

void img_put_pixel_4_byte(int *pixels, int line_length, int x, int y, int color)
{
	int	*dest;

	if(!pixels)
		exit(MLX_ERROR);
	dest = pixels + img_get_offset_4_byte(line_length, x, y);
	if(!dest)
		exit(MLX_ERROR);
	*(unsigned int *)dest = color;
}