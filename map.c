/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:30:37 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/16 16:06:29 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**getmap(char **map, int fd, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		map = getmap(map, fd, i + 1);
	else if (i == 0 && map == NULL)
		return (NULL);
	else
	{
		map = (char **)calloc((i + 2), sizeof(char *));
		mapdata()->height = i;
	}
	map[i] = line;
	if (map[i + 1] == NULL)
		mapdata()->length = ft_strlen(line);
	return (map);
}

void	flood_fill(int i, int j)
{
	void fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if(cur.x<0|| cur.y<0 ||cur.x >= size.x || cur.y >=size.y || tab[cur.y][cur.x]!=to_fill)
		return;

	tab[cur.y][cur.x]='F';
	fill(tab, size, (t_point){cur.x-1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x+1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y-1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y+1}, to_fill);
}
}

int	aaaaaa(int i, int j, int *player, int *exit)
{
	if (i == 0 || i == ((mapdata()->height) - 1) || j == 0
		|| j == ((mapdata()->length) - 1))
	{
		if (mapdata()->map[i][j] != '1')
			return (0);
	}
	else if (mapdata()->map[i][j] != '0' && mapdata()->map[i][j] != '1' \
			&& mapdata()->map[i][j] != 'P' && mapdata()->map[i][j] != 'E' \
			&& mapdata()->map[i][j] != 'C')
		return (0);
	if (mapdata()->map[i][j] == 'C')
		mapdata()->collectibles++;
	if (mapdata()->map[i][j] == 'P')
	{
		mapdata()->playery = i;
		mapdata()->playerx = j;
		(*player)++;
	}
	if (mapdata()->map[i][j] == 'E')
		(*exit)++;
	return (1);
}

int	chkvalidmap(void)
{
	int	i;
	int	j;
	int	player;
	int	exit;

	i = -1;
	mapdata()->collectibles = 0;
	player = 0;
	exit = 0;
	while (++i < mapdata()->height)
	{
		j = -1;
		while (++j < mapdata()->length)
		{
			aaaaaa(i, j, &player, &exit);
		}
	}
	if (mapdata()->collectibles < 1 || player != 1 || exit != 1)
		return (0);
	flood_fill(mapdata()->playery, mapdata()->playerx);
	return (1);
}
