/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnshift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:09:51 by kcowle            #+#    #+#             */
/*   Updated: 2016/07/10 14:09:59 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnshift(char *str, unsigned int n)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(sizeof(char *) * ft_strlen(str));
	while (str[n])
	{
		ptr[i] = str[n];
		i++;
		n++;
	}
	while (str[i])
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
