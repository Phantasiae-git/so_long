/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:37:40 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/17 18:06:23 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_mapdata
{
	char		**map;
	char		**tmp;
	int			height;
	int			length;
	int			collectibles;
	int			playerx;
	int			playery;
}				t_mapdata;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			moves;
	void		**image;
	t_mapdata	*map;
}				t_data;

t_mapdata		*mapdata(void);
t_data			*data(void);

int				chkvalidmap(void);
void			flood_fill(char **map, int i, int j);
char			**getmap(char **map, int fd, int i);
int				checkfile(char *name, char *ext);
void			render(int i);
void			images(void);
int				key_hook(int keycode, t_data *data);
int				closewin(void);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_putnbr(int n);
void			freearr(void);

#endif
