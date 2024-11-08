/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhpark <yunhpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:26:53 by yunhpark          #+#    #+#             */
/*   Updated: 2024/10/03 18:11:40 by yunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *src)
{
	char	*str;
	int		src_len;
	int		i;

	src_len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!(str))
		return (0);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
