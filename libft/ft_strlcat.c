/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 04:18:31 by kdoyle            #+#    #+#             */
/*   Updated: 2020/11/17 22:26:05 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	c;
	char	*sors;

	if (!dst && !src)
		return (0);
	sors = (char *)src;
	c = ft_strlen(dst);
	i = ft_strlen(src);
	if (dstsize <= c)
		return (i + dstsize);
	dst = dst + c;
	while (*sors != '\0' && (dstsize - c - 1) != 0)
	{
		*(dst++) = *(sors++);
		dstsize--;
	}
	*dst = '\0';
	return (i + c);
}
