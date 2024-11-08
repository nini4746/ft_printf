/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhpark <yunhpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:28:27 by yunhpark          #+#    #+#             */
/*   Updated: 2024/10/04 11:59:02 by yunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dup(char const *str, char c)
{
	int		len;
	char	*dest;
	int		i;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	word_count(char const *str, char c)
{
	int	cnt;
	int	j;

	j = 0;
	cnt = 0;
	while (str[j] != '\0')
	{
		if (str[j] != c)
		{
			cnt++;
			while (str[j] != c && str[j] != '\0')
				j++;
		}
		else
			j++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	int		num;
	int		i;
	int		j;
	char	**result;

	j = 0;
	num = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (num + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c)
		{
			result[i++] = ft_dup(&s[j], c);
			while (s[j] != c && s[j] != '\0')
				s++;
		}
		else
			s++;
	}
	result[i] = 0;
	return (result);
}
