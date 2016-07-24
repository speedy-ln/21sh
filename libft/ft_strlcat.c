/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:09:51 by kcowle            #+#    #+#             */
/*   Updated: 2016/07/10 14:09:59 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	n;

	len = 0;
	while (len < size && *dest && *(dest++))
		len++;
	n = size - len;
	if (!n)
		return (len + ft_strlen(src));
	while (*src)
	{
		if (n != 1)
		{
			*(dest++) = *src;
			n--;
		}
		src++;
		len++;
	}
	*dest = '\0';
	return (len);
}
