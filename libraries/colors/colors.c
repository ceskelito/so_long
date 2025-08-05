/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:03:07 by rceschel          #+#    #+#             */
/*   Updated: 2025/08/05 12:24:41 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	color_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color_get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	color_get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	color_get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	color_get_b(int trgb)
{
	return (trgb & 0xFF);
}
