/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:13:25 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/13 20:28:01 by rfontes-         ###   ########.fr       */
/*            
	-                                                               */
/* ************************************************************************** */

#include "so_long.h"

void	freearr(void)
{
	int	j;

	j = -1;
	if (mapdata()->tmp)
	{
		while (++j < mapdata()->height)
			free(mapdata()->tmp[j]);
		free(mapdata()->tmp);
	}
	j = -1;
	if (mapdata()->map)
	{
		while (++j < mapdata()->height)
			free(mapdata()->map[j]);
		free(mapdata()->map);
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (++i < nmemb * size)
		ptr[i] = '\0';
	return (ptr);
}

int	checkfile(char *name, char *ext)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (name[i])
	{
		if (name[i] == ext[j])
		{
			if (j == 3 && name[i + 1] == '\0')
				return (1);
			j++;
		}
		else
			j = 0;
		i++;
	}
	return (0);
}

int	errorf(int i)
{
	freearr();
	if (i == 1)
		printf("Incorrect number of arguments\n");
	if (i == 2)
		printf("Incorrect map extension\n");
	if (i == 3)
		printf("Reading file failed\n");
	if (i == 4)
		printf("Map creation failed\n");
	if (i == 5)
		printf("Invalid map\n");
	return (1);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (errorf(1));
	if (!checkfile(argv[1], ".ber"))
		return (errorf(2));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (errorf(3));
	data()->map = mapdata();
	(mapdata()->map) = getmap((mapdata()->map), fd, 0);
	close(fd);
	if (!mapdata()->map)
		return (errorf(4));
	if (!chkvalidmap())
		return (errorf(5));
	data()->mlx = mlx_init();
	(data()->win) = mlx_new_window((data()->mlx), (mapdata()->length) * 64, \
			(mapdata()->height) * 64, "so_long");
	render(-1);
	mlx_hook(data()->win, 02, 1L << 0, key_hook, data());
	mlx_hook(data()->win, 17, 1L << 2, closewin, data());
	mlx_loop(data()->mlx);
}
