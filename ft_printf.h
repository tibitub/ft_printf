/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpapa <kpapa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:46:10 by kpapa             #+#    #+#             */
/*   Updated: 2023/03/22 20:01:43 by kpapa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_int(int num);
int	ft_print_uint(unsigned int num);
int	ft_print_hex_small(unsigned int num);
int	ft_print_hex_big(unsigned int num);
int	ft_print_char(char ch);
int	ft_print_str(char *str);
int	ft_print_ptr(void *ptr_address);

#endif
