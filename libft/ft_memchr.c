/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 02:18:07 by kdoyle            #+#    #+#             */
/*   Updated: 2021/09/28 19:49:33 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*so;

	so = (unsigned char *)s;
	c = (unsigned char)c;
	if (n == 0)
		return (NULL);
	while (n != 0)
	{
		if (*so == c)
			return (so);
		n--;
		so++;
	}
	return (NULL);
}
