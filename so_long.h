/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:37:40 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/14 01:09:38 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_mapdata
{
	char **map;
	int height;
	int length;
	int collectibles;
	int playerx;
	int playery;
	int exitx;
	int exity;
} t_mapdata;

typedef struct s_data
{
	void *mlx;
	void *win;
	int moves;
	char **image;
	t_mapdata *map;
}	t_data;

t_mapdata *mapdata();
t_data *data();

#endif