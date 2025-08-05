/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:27:08 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/05 16:11:18 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DATA_H
# define MLX_DATA_H


typedef struct s_data
{
	void	*mlx;
	void	*win;
}				t_data;

typedef struct s_data_img
{
	void	*img;

	char	*filename;	// for xpm images
	char	*addr;
	int		*pixels;	// same ad addr, but 4 byte aligned

	int		bpp;		// bits per pixel
	int		line_len;
	int		endian;
  
	int		width;		// to set manually if not xpm
	int		height;		// to set manually if not xpm
}				t_data_img;

t_data	data_init(void *mlx_ptr, int w_l, int w_h, char *w_name);

void	img_set_background(t_data_img *img, int color);
int		img_get_offset(t_data_img *img, int x, int y);
void	img_put_pixel(t_data_img *img, int x, int y, int color);
int		img_get_offset_4_byte(int line_length, int x, int y);
void 	img_put_pixel_4_byte(int *pixels, int line_length,
			int x, int y, int color);
void	img_create(void *mlx, t_data_img *img, int img_width,
			int img_height);

#endif
