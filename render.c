/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 06:57:37 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/17 17:03:33 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(int i)
{
	int	j;

	images();
	while (++i < mapdata()->height)
	{
		j = -1;
		while (++j < mapdata()->length)
		{
			if (mapdata()->map[i][j] == '0')
				mlx_put_image_to_window(data()->mlx, data()->win, \
						data()->image[0], j * 64, i * 64);
			if (mapdata()->map[i][j] == '1')
				mlx_put_image_to_window(data()->mlx, data()->win, \
						data()->image[1], j * 64, i * 64);
			if (mapdata()->map[i][j] == 'P')
				mlx_put_image_to_window(data()->mlx, data()->win, \
						data()->image[2], j * 64, i * 64);
			if (mapdata()->map[i][j] == 'E')
				mlx_put_image_to_window(data()->mlx, data()->win, \
						data()->image[3], j * 64, i * 64);
			if (mapdata()->map[i][j] == 'C')
				mlx_put_image_to_window(data()->mlx, data()->win, \
						data()->image[4], j * 64, i * 64);
		}
	}
}

void	ft_putnbr(int n)
{
	char	c;

	if (n <= -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}
