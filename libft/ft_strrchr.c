/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:35:23 by kdoyle            #+#    #+#             */
/*   Updated: 2020/11/15 16:35:27 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*a;
	char	*aa;

	i = 0;
	c = (char)c;
	a = (char *)s;
	i = ft_strlen(a);
	aa = a;
	a = a + i;
	while (!(a == aa) && !(*a == c))
		a--;
	return ((*a == c) ? a : NULL);
}
