/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceskelito <ceskelito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:55:39 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/05 12:16:24 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

# include "map.h" 
# include "assets.h"

// Free Memory Function
bool	free_asset(void *mlx, void *asset[]);
void	free_grid(void **grid);

// Exit from the program
void	print_and_exit(char *msg, int exit_code);

// Map relatives functions
bool	measurements_helper(char *row, t_map *map, int fd);
bool	translate_helper(char **c_grid, t_tile **tile_grid, int i, int j);
void	continue_map_checking(t_map *map);
bool	flood_fill(t_map *map);

#endif
