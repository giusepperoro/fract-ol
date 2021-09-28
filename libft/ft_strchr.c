/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:05:15 by kdoyle            #+#    #+#             */
/*   Updated: 2021/09/28 19:49:00 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*a;

	c = (char)c;
	a = (char *)s;
	while (*a && !(*a == c))
		a++;
	if (*a == c)
		return (a);
	else
		return (NULL);
}
