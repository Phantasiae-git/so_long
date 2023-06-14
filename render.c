/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 06:57:37 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/14 08:43:09 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render(void)
{
    int i;
    int j;

    images();
    i=-1;
    while(++i<mapdata()->height)
	{
		j=-1;
		while(++j<mapdata()->length)
        {
            if(mapdata()->map[i][j]=='0')
                mlx_put_image_to_window(data()->mlx, data()->win, data()->image[0], j*64, i*64);
            if(mapdata()->map[i][j]=='1')
                mlx_put_image_to_window(data()->mlx, data()->win, data()->image[1], j*64, i*64);
            if(mapdata()->map[i][j]=='P')
                mlx_put_image_to_window(data()->mlx, data()->win, data()->image[2], j*64, i*64);
            if(mapdata()->map[i][j]=='E')
                mlx_put_image_to_window(data()->mlx, data()->win, data()->image[3], j*64, i*64);
            if(mapdata()->map[i][j]=='C')
                mlx_put_image_to_window(data()->mlx, data()->win, data()->image[4], j*64, i*64);
        }
    }
}