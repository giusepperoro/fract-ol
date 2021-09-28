/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:59:12 by kdoyle            #+#    #+#             */
/*   Updated: 2020/11/17 22:34:21 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*sors;
	unsigned char	*dest;

	sors = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if ((dest == NULL) && (sors == NULL))
		return (0);
	if (dest < sors)
		while (len--)
			*(dest++) = *(sors++);
	else if (dest > sors)
	{
		dest = dest + len;
		sors = sors + len;
		while (len--)
			*(--dest) = *(--sors);
	}
	return (dest);
}
