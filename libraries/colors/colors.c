/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:03:07 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/24 12:04:22 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* unsigned int	get_pixel_color(char *data, int x, int y, int bpp, int size_line, int endian)
{
	int				bytes_per_pixel;
	char			*pixel;
	unsigned int	color;

	bytes_per_pixel = bpp / 8;
	pixel = data + (y * size_line + x * bytes_per_pixel);

	if (endian == 0)
		color = *(unsigned int *)pixel;
	else
		color = (pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | (pixel[3]);

	return (color);
} */

int	color_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color_get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	color_get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	color_get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	color_get_b(int trgb)
{
	return (trgb & 0xFF);
}
