/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceskelito <ceskelito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:55:39 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/30 15:24:58 by ceskelito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "assets.h"
# include <stdbool.h>

// Free Memory Function
bool	free_asset(void *mlx, void *asset[]);
void	free_grid(void **grid);

void	print_and_exit(char *msg, int exit_code);

void	img_put_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, void *background_ptr, int x, int y);


#endif
