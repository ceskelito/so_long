/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:01:16 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/05 18:56:08 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* Libraries Inclusion */
# include "assets.h"
# include "errors.h"
# include "map.h"
# include "utils.h"
# include "mlx.h"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define CHROMA_KEY 0xFF00FF

int	move_player(t_map *map, int x, int y);
void *get_img_w_transparency(void *foreground, void *background, int width, int height, int chroma_key);
#endif
