/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:39:59 by kdoyle            #+#    #+#             */
/*   Updated: 2021/09/28 19:48:20 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	o;
	char	*sors;

	o = 0;
	if (!dst && !src)
		return (0);
	sors = (char *)src;
	i = ft_strlen(sors);
	if (dstsize == 0)
		return (i);
	while (sors[o] != '\0' && (dstsize - 1) != 0)
	{
		dst[o] = sors[o];
		o++;
		dstsize--;
	}
	dst[o] = '\0';
	return (i);
}
