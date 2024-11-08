/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhpark <yunhpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:39:33 by yunhpark          #+#    #+#             */
/*   Updated: 2024/10/25 14:53:41 by yunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putui_fd(unsigned int num, int fd)
{
	if (num >= 10)
		ft_putui_fd(num / 10, fd);
	ft_putchar_fd((num % 10) + '0', fd);
}

void	ft_putptr_fd(void *ptr, int fd)
{
	unsigned long	addr;
	char			buffer[17];
	int				i;

	addr = (unsigned long)ptr;
	i = 0;
	if (addr == 0)
	{
		write(fd, "0x0", 3);
		return ;
	}
	while (addr > 0)
	{
		buffer[i++] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	buffer[i] = '\0';
	write(fd, "0x", 2);
	while (--i >= 0)
		write(fd, &buffer[i], 1);
}

void	ft_puthex(unsigned int num, int sign, int fd)
{
	char	*hex_digits;

	if (sign == 0)
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	if (num >= 16)
		ft_puthex(num / 16, sign, fd);
	ft_putchar_fd(hex_digits[num % 16], fd);
}
