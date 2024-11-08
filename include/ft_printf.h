/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhpark <yunhpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:46:03 by yunhpark          #+#    #+#             */
/*   Updated: 2024/10/25 14:53:46 by yunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
#include "../libft/libft.h"

typedef struct s_info
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	dot_only;
	int	locass;
	int	num_base;
	int	num_sign;
	int	address;
}	t_info;

int		ft_printf(const char *str, ...);
int		ft_handle_format(const char *c, va_list ap);
int		ft_handle_char(char c);
int		ft_handle_string(char *str);
int		ft_handle_int(int num);
int		ft_handle_unsigned(unsigned int num);
int		ft_handle_pointer(void *ptr);
int		ft_handle_hex(unsigned int num, int n);
void	ft_putui_fd(unsigned int num, int fd);
void	ft_putptr_fd(void *ptr, int fd);
void	ft_puthex(unsigned int num, int sign, int fd);
int		ft_numlen(int num);
int		ft_uilen(unsigned int num);
int		ft_ptrlen(void *ptr);
int		ft_hexlen(unsigned int num);

// int		ft_handle_format2(const char *c, va_list ap);

#endif