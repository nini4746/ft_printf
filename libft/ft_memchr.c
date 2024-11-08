/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhpark <yunhpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:12:50 by yunhpark          #+#    #+#             */
/*   Updated: 2024/10/03 18:09:22 by yunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*p;
	unsigned char	c;
	size_t			i;

	p = (unsigned char *)ptr;
	c = (unsigned char)value;
	i = 0;
	while (i < num)
	{
		if (p[i] == c)
			return ((void *)(p + i));
		i++;
	}
	return (0);
}
