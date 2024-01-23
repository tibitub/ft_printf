/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpapa <kpapa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:43:45 by kpapa             #+#    #+#             */
/*   Updated: 2023/03/22 20:03:33 by kpapa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char ch)
{
	int	ct;

	ct = write(STDOUT_FILENO, &ch, 1);
	return (ct);
}

int	ft_print_str(char *str)
{
	int	i;
	int	ct;

	if (str == NULL)
	{
		ct = write(STDOUT_FILENO, "(null)", 6);
		return (ct);
	}	
	ct = 0;
	i = 0;
	while (str[i] != '\0')
	{
		ct += write(STDOUT_FILENO, &str[i], 1);
		++i;
	}
	return (ct);
}

static int	ft_print_prefix(char *str)
{
	int	i;

	i = ft_print_str(str);
	return (i);
}

int	ft_print_ptr(void *ptr_address)
{
	int				i;
	char			*str;
	unsigned long	address;

	address = (unsigned long)ptr_address;
	i = ft_print_prefix("0x");
	str = ft_itoa_base(address, "0123456789abcdef");
	i = i + ft_print_str(str);
	free(str);
	return (i);
}
