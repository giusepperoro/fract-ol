/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:53:01 by kdoyle            #+#    #+#             */
/*   Updated: 2021/09/28 19:49:27 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
