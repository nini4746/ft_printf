/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhpark <yunhpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:05:18 by yunhpark          #+#    #+#             */
/*   Updated: 2024/10/04 12:32:53 by yunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	intlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_nbr(char *result, int *i, int n)
{
	if (n == -2147483648)
	{
		result[(*i)++] = '-';
		result[(*i)++] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		result[(*i)++] = '-';
		n = -n;
	}
	if (n >= 10)
	{
		ft_nbr(result, i, n / 10);
	}
	result[(*i)++] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	int		i;

	len = intlen(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	ft_nbr(result, &i, n);
	result[i] = '\0';
	return (result);
}
