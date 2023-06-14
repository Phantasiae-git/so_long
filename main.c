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
#include <mlx.h>

int	key_hook(int keycode, t_vars *vars)
{
	int	moves;

	(void)vars;
	(void)keycode;
	moves = 56;
	printf("moves:%i\n", moves);
	return (0);
}

int	close_hook(int keycode, t_vars *vars)
{
	(void)vars;
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

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
			if(j==3 and name[i+1]=='\0')
				return(1);
			j++;
		}
		else
			j=0;
		i++;
	}
	return(0);
}

void getmap(int fd, )

int	main(int argc, char **argv)
{
	int fd;

	if(argc!=2)
		return(1);
	if(!checkfile(argv[1], ".ber"))
		return(1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return(1);
	mapdata()=NULL;
	data()->map=mapdata();
	getmap(fd, mapdata()->map);
	checkscheckschecks
	data()->mlx = mlx_init();
	data()->win = mlx_new_window(vars.mlx, mapdata()->height*64, mapdata()->length*64, "so_long");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 2, close_hook, &vars);
	mlx_loop(vars.mlx);
}