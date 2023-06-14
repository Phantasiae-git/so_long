/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:31:39 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/14 08:50:43 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

t_mapdata	*mapdata(void)
{
	static t_mapdata mapdata;

	return (&mapdata);
}

void images(void)
{
	int a;
	data()->image=malloc(5*sizeof(void *));
	if(!data()->image)
		return;
	data()->image[0]=mlx_xpm_file_to_image(data()->mlx, "treerings.xpm", &a, &a);//floor
	data()->image[1]=mlx_xpm_file_to_image(data()->mlx, "iron.xpm", &a, &a);//wall
	data()->image[2]=mlx_xpm_file_to_image(data()->mlx, "waterf2.xpm", &a, &a);//player
	data()->image[3]=mlx_xpm_file_to_image(data()->mlx, "treerings.xpm", &a, &a);//exit
	data()->image[4]=mlx_xpm_file_to_image(data()->mlx, "treerings.xpm", &a, &a);//collectible
}