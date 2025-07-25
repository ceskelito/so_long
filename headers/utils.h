/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:55:39 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/24 18:56:48 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include "assets.h"

// Free Memory Function
bool	free_asset(void *mlx, void *asset[]);
void	free_grid(void **grid);

void	print_and_exit(char *msg, int exit_code);

#endif