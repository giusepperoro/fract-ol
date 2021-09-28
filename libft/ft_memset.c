/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 08:21:38 by kdoyle            #+#    #+#             */
/*   Updated: 2020/11/06 16:17:39 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*co;

	i = 0;
	c = (unsigned char)c;
	co = (unsigned char *)b;
	while (len != 0)
	{
		co[i] = c;
		i++;
		len--;
	}
	return (b);
}
