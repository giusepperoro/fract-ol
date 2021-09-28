/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 22:22:47 by kdoyle            #+#    #+#             */
/*   Updated: 2020/11/07 08:59:58 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *so1;
	unsigned char *so2;

	so1 = (unsigned char *)s1;
	so2 = (unsigned char *)s2;
	while (n != 0)
	{
		if (*so1 == '\0' && *so2 == '\0')
			break ;
		if (*so1 > *so2)
			return (1);
		else if (*so1 < *so2)
			return (-1);
		so1++;
		so2++;
		n--;
	}
	return (0);
}
