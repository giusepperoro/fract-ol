/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:53:01 by kdoyle            #+#    #+#             */
/*   Updated: 2020/11/07 11:19:19 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*sors;
	char	*dest;

	i = 0;
	dest = dst;
	sors = (char *)src;
	if (dest == 0 && sors == 0)
		return (0);
	while (i < n)
	{
		*(dest + i) = *(sors + i);
		i++;
	}
	return (dst);
}
