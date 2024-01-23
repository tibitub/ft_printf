/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpapa <kpapa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:18:03 by kpapa             #+#    #+#             */
/*   Updated: 2023/03/22 20:16:28 by kpapa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversion(va_list args, const char ch)
{
	int	ct;

	if (ch == 'i' || ch == 'd')
		ct = ft_print_int(va_arg(args, int));
	if (ch == 'u')
		ct = ft_print_uint(va_arg(args, unsigned int));
	if (ch == 'x')
		ct = ft_print_hex_small(va_arg(args, unsigned int));
	if (ch == 'X')
		ct = ft_print_hex_big(va_arg(args, unsigned int));
	if (ch == 'p')
		ct = ft_print_ptr(va_arg(args, void *));
	if (ch == 'c')
		ct = ft_print_char(va_arg(args, int));
	if (ch == 's')
		ct = ft_print_str(va_arg(args, char *));
	return (ct);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				count;
	unsigned int	i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '%')
				count += conversion(args, format[i + 1]);
			else
				count += write(STDOUT_FILENO, "%", 1);
			++i;
		}
		else
			count += write(STDOUT_FILENO, &format[i], 1);
		++i;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	char	str[] = "Heyo";
// 	int num = ft_printf("Hello %i, %d, %u, %x, %X, 
// %c, %s, %p", 1, 3, 16, 22, '+', str, &str);
// 	ft_printf("\n%i%%\n", num);
// 	return (0);
// }
