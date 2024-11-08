/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhpark <yunhpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:50:43 by yunhpark          #+#    #+#             */
/*   Updated: 2024/10/25 14:53:37 by yunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(const char *c, va_list ap)
{
	if (*c == 'c')
		return (ft_handle_char((char)va_arg(ap, int)));
	else if (*c == 's')
		return (ft_handle_string(va_arg(ap, char *)));
	else if (*c == 'd' || *c == 'i')
		return (ft_handle_int(va_arg(ap, int)));
	else if (*c == 'u')
		return (ft_handle_unsigned(va_arg(ap, unsigned int)));
	else if (*c == 'p')
		return (ft_handle_pointer(va_arg(ap, void *)));
	else if (*c == 'x')
		return (ft_handle_hex(va_arg(ap, unsigned int), 0));
	else if (*c == 'X')
		return (ft_handle_hex(va_arg(ap, unsigned int), 1));
	else if (*c == '%'){
		return (ft_handle_char('%'));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		cnt;

	va_start(ap, str);
	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			cnt += ft_handle_format(&str[i], ap);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			cnt++;
		}
		i++;
	}
	va_end(ap);
	return (cnt);
}
