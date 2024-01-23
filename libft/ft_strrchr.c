/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpapa <kpapa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:51:51 by kpapa             #+#    #+#             */
/*   Updated: 2023/02/06 18:30:52 by kpapa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*found;
	int		count;

	count = 0;
	found = NULL;
	while (str[count])
	{
		if (str[count] == (unsigned char)c)
			found = (char *)str + count;
		count ++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str + count);
	else
		return (found);
}
