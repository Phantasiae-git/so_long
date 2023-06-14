/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 03:10:08 by rfontes-          #+#    #+#             */
/*   Updated: 2023/06/14 05:55:02 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char	*ft_strdup(const char *str)
// {
// 	char	*ptr;
// 	int		len;

// 	len = ft_strlen(str) + 1;
// 	ptr = (char *)malloc(len);
// 	if (!ptr)
// 	{
// 		return (0);
// 	}
// 	ptr = ft_memcpy(ptr, str, len);
// 	return (ptr);
// }

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	size_t	i;
// 	char	*d;
// 	char	*s;

// 	if (!dest && !src)
// 	{
// 		return (0);
// 	}
// 	d = (char *)dest;
// 	s = (char *)src;
// 	i = 0;
// 	while (i < n)
// 	{
// 		d[i] = s[i];
// 		i++;
// 	}
// 	return (dest);
// }