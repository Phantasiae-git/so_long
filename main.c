/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:13:25 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/13 20:28:01 by rfontes-         ###   ########.fr       */
/*             -                                                               */
/* ************************************************************************** */

#include "so_long.h"

// int	key_hook(int keycode, t_data *data)
// {
// 	int	moves;

// 	(void)vars;
// 	(void)keycode;
// 	moves = 56;
// 	printf("moves:%i\n", moves);
// 	return (0);
// }

// int	close_hook(int keycode, t_data *data)
// {
// 	(void)vars;
// 	(void)keycode;
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	exit(0);
// 	return (0);
// }

int checkfile(char *name, char *ext)
{
	int i;
	int j;
	i=0;
	j=0;
	while(name[i])
	{
		if(name[i]==ext[j])
		{
			if(j==3 && name[i+1]=='\0')
				return(1);
			j++;
		}
		else
			j=0;
		i++;
	}
	return(0);
}

int errorf(int i)
{
	if(i==1)
		printf("Incorrect number of arguments\n");
	if(i==2)
		printf("Incorrect map extension\n");
	if(i==3)
		printf("Reading file failed\n");
	if(i==4)
		printf("Map creation failed\n");
	if(i==5)
		printf("Invalid map\n");
	return(1);
}

int	main(int argc, char **argv)
{
	int fd;

	if(argc!=2)
		return(errorf(1));
	if(!checkfile(argv[1], ".ber"))
		return(errorf(2));
	fd = open(argv[1], O_RDONLY);
	if (fd<0)
		return(errorf(3));
	data()->map=mapdata();
	mapdata()->map=getmap(mapdata()->map, fd, 0);
	close(fd);
	if(!mapdata()->map)
		return(errorf(4));
	if(!chkvalidmap())
		return(errorf(5));
	data()->mlx = mlx_init();
	data()->win = mlx_new_window(data()->mlx, mapdata()->length*64, mapdata()->height*64, "so_long");
	int i;
	i=-1;
	while(mapdata()->map[++i])
		printf("%s", mapdata()->map[i]);
	printf("height=%i\nlength=%i\n", mapdata()->height, mapdata()->length);
	render();
	// mlx_key_hook(data()->win, key_hook, data());
	// mlx_hook(data()->win, 17, 1L << 2, close, data());
	mlx_loop(data()->mlx);
}