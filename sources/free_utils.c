/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceskelito <ceskelito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:54:55 by rceschel          #+#    #+#             */
/*   Updated: 2025/07/26 12:12:01 by ceskelito        ###   ########.fr       */
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
