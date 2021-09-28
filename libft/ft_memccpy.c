/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:50:26 by kdoyle            #+#    #+#             */
/*   Updated: 2020/11/07 06:41:21 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*sors;
	unsigned char		*dest;

	c = (unsigned char)c;
	sors = (unsigned char *)src;
	dest = (unsigned char *)dst;
	while (n != 0)
	{
		*dest = *sors;
		if (*sors == c)
			return (dest + 1);
		dest++;
		sors++;
		n--;
	}
	return (NULL);
}
