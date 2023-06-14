/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:30:37 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/14 05:54:52 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **getmap(char **map, int fd, int i)
{
	char *line;

	line=get_next_line(fd);
	if(line)
		getmap(map, fd, i+1);
	else if(i==0 && map==NULL)
		return(NULL);
	else
	{
		map=(char **)malloc(i*sizeof(char *));
		mapdata()->height=i;
		return(NULL);
	}
	map[i]=line;
	printf("%s", map[i]);
	mapdata()->length=ft_strlen(line);
	free(line);
	return(map);
}

void flood_fill(int i, int j)
{
	(void)i;
	(void)j;
	return;
}

int chkvalidmap()
{
	int i;
	int j;
	int player;
	int exit;

	i=0;
	mapdata()->collectibles=0;
	player=0;
	exit=0;
	while(mapdata()->map[i])
	{
		j=0;
		while(mapdata()->map[i][j]!='\0')
		{
			if(i==0 || i==(mapdata()->height-1) || j==0 ||j==(mapdata()->length-1))
			{
				if(mapdata()->map[i][j]!='1')
					return(0);
			}
			else if(mapdata()->map[i][j]!='0' && mapdata()->map[i][j]!='1' && mapdata()->map[i][j]!='P' && mapdata()->map[i][j]!='E'&& mapdata()->map[i][j]!='C')
				return(0);
			if(mapdata()->map[i][j]=='C')
				mapdata()->collectibles++;
			if(mapdata()->map[i][j]=='P')
			{
				mapdata()->playery=i;
				mapdata()->playerx=j;
				player++;
			}
			if(mapdata()->map[i][j]=='E')
				exit++;
		}
	}
	if(mapdata()->collectibles<1 || player!=1 || exit!=1)
		return(0);
	flood_fill(mapdata()->playery, mapdata()->playerx);
	return(1);
}