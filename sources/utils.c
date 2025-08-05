/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:54:55 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/05 12:21:17 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "utils.h"
#include "mlx.h"
#include "libft.h"

void	print_and_exit(char *msg, int exit_code)
{
	ft_printf("%s", msg);
	exit(exit_code);
}

bool	free_asset(void *mlx, void *asset[])
{
	int	i;

	i = 1;
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
	while (grid && grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
