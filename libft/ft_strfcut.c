/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfcut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:09:51 by kcowle            #+#    #+#             */
/*   Updated: 2016/07/10 14:09:59 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfcut(char *str, unsigned int n)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(sizeof(char *) * ft_strlen(str) - n + 1);
	while (str[i] != '\0')
	{
		ptr[i] = str[n];
		i++;
		n++;
	}
	return (ptr);
}
