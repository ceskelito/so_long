#ifndef MLX_DATA_H
# define MLX_DATA_H

# ifndef MLX_ERROR
#  define MLX_ERROR 1
# endif

typedef struct s_data {
	void	*mlx;
	void	*win;
} t_data;

typedef struct s_data_img
{
	void    *img;

	char	*filename;	// for xpm images
	char    *addr;
                                                           
	int     bpp;		// bits per pixel
	int     line_len;
	int     endian;

	int		width;		// to set manually if not xpm
	int		height;		// to set manually if not xpm
} t_data_img;

/*
typedef struct s_data_mlx
{
	// pointer to the actual istance of mlx
	void		*istance;

	// pointers to the first window/image linked to this istance of mlx
	void		*window;
	t_data_img	*image;
	
	// number of registered windos/images
	int			num_win;
	int			num_img;

	// current position in the windows/images pointer
	int			cur_win;
	int			cur_img;
} t_data_mlx
*/ //Don't know if useful, in doubt commented it 

t_data	data_init(void *mlx_ptr, int w_l, int w_h, char *w_name);

void	img_set_background(t_data_img *img, int color);
int		img_get_offset(t_data_img *img, int x, int y);
void	img_put_pixel(t_data_img *img, int x, int y, int color);
void	img_create(void *mlx, t_data_img *img, int img_width, int img_height);

#endif
