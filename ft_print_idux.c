/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_idux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpapa <kpapa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:39:32 by kpapa             #+#    #+#             */
/*   Updated: 2023/03/22 20:17:48 by kpapa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_print_int(int num)
{
	unsigned int	i;
	int				ct;
	char			*str;

	ct = 0;
	str = ft_itoa(num);
	i = 0;
	while (i < ft_strlen(str))
		ct += write(STDOUT_FILENO, &str[i++], 1);
	free(str);
	return (ct);
}

int	ft_print_uint(unsigned int num)
{
	int		i;
	char	*str;

	str = ft_itoa_base(num, "0123456789");
	i = ft_print_str(str);
	free(str);
	return (i);
}

int	ft_print_hex_small(unsigned int num)
{
	int		i;
	char	*str;

	str = ft_itoa_base(num, "0123456789abcdef");
	i = ft_print_str(str);
	free(str);
	return (i);
}

int	ft_print_hex_big(unsigned int num)
{
	int		i;
	char	*str;

	str = ft_itoa_base(num, "0123456789ABCDEF");
	i = ft_print_str(str);
	free(str);
	return (i);
}
