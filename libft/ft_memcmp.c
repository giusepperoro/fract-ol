/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 03:10:42 by kdoyle            #+#    #+#             */
/*   Updated: 2020/11/07 06:57:20 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*so1;
	unsigned char	*so2;

	so1 = (unsigned char *)s1;
	so2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*so1 != *so2)
			return (*so1 - *so2);
		n--;
		so1++;
		so2++;
	}
	return (0);
}
