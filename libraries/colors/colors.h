#ifndef COLORS_H
# define COLORS_H

# include "colorsdef.h"

int	color_create_trgb(int t, int r, int g, int b);
int	color_get_t(int trgb);
int	color_get_r(int trgb);
int	color_get_g(int trgb);
int	color_get_b(int trgb);

#endif
