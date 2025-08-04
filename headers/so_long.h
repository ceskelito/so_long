/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:01:16 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/04 17:54:38 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* Libraries Inclusion */
# include "assets.h"
# include "errors.h"
# include "map.h"
# include "utils.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

int	move_player(t_map *map, int x, int y);
//void render_all(t_data *data, t_map *map);
//int	render_void(void *param);
//int	close_window(t_map *map);
//int	handle_keypress(int keycode, t_map *map);

#endif
