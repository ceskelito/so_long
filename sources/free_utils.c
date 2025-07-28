/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:54:55 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/28 15:17:12 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include "mlx.h"

bool	free_asset(void *mlx, void *asset[])
{
	int	i;
	
	i = 0;
	while (asset[i])
	{
		mlx_destroy_image(mlx, asset[i]);
		asset[i] = NULL;
		i++;
	}
	return (false);
}

void	free_grid(void **grid)
{
	int	i;

	i = 0;
	while(grid && grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
