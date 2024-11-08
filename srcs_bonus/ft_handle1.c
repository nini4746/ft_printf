/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhpark <yunhpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:24:24 by yunhpark          #+#    #+#             */
/*   Updated: 2024/10/25 14:53:35 by yunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_handle_string(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_handle_int(int num)
{
	ft_putnbr_fd(num, 1);
	return (ft_numlen(num));
}

int	ft_handle_unsigned(unsigned int num)
{
	ft_putui_fd(num, 1);
	return (ft_uilen(num));
}

int	ft_handle_pointer(void *ptr)
{
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putptr_fd(ptr, 1);
	return (ft_ptrlen(ptr));
}
