/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpapa <kpapa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:02:51 by kpapa             #+#    #+#             */
/*   Updated: 2023/02/06 18:30:17 by kpapa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	count;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		sub = (char *)malloc((ft_strlen(&s[start]) + 1) * sizeof(char));
	else
		sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	count = 0;
	while (count < len && *(s + start + count))
	{
		sub[count] = *(s + start + count);
		count ++;
	}
	sub[count] = '\0';
	return (sub);
}
